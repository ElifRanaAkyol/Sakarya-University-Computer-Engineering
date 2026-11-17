#include "unpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void unpack_archive(const char *archive_file, const char *output_dir) {
    const char *ext = strrchr(archive_file, '.');
    if (!ext || strcmp(ext, ".sau") != 0) { //uzantı sau mü kontrol edilir
        printf("Arşiv dosyası uygunsuz veya bozuk!\n");
        return;
    }

    FILE *arch = fopen(archive_file, "r");
    if (!arch) { //dosya mevcut mu kontrolü
        printf("Arşiv dosyası uygunsuz veya bozuk!\n");
        return;
    }

    char header_len_str[11];
    if (fread(header_len_str, 1, 10, arch) != 10) {
        printf("Arşiv dosyası uygunsuz veya bozuk!\n");
        fclose(arch);
        return;
    }
    header_len_str[10] = '\0';
    long total_header_size = strtol(header_len_str, NULL, 10); //stringi sayıya çevirmme

    if (total_header_size <= 10) {
        printf("Arşiv dosyası uygunsuz veya bozuk!\n");
        fclose(arch);
        return;
    }

    long org_len = total_header_size - 10; //ilk 10 bayt kontrol edildiği için çıkarılır 
    char *org_buffer = malloc(org_len + 1); //bellekte yer açtık
    if (fread(org_buffer, 1, org_len, arch) != (size_t)org_len) {
        printf("Arşiv dosyası uygunsuz veya bozuk!\n");
        free(org_buffer);
        fclose(arch);
        return;
    }
    org_buffer[org_len] = '\0';

    if (output_dir != NULL) { //kullanıcı girdisi var mı kontrol edilir
        struct stat st = {0};
        if (stat(output_dir, &st) == -1) {
            if (mkdir(output_dir, 0777) != 0) {
                printf("Hata: Dizin oluşturulamadı!\n");
                free(org_buffer);
                fclose(arch);
                return;
            }
        }
    }

    fseek(arch, total_header_size, SEEK_SET);

    char *token = strtok(org_buffer, "|"); //  işarete göre parçalanır
    
    char opened_files_list[32][256];
    int opened_file_count = 0;

    while (token != NULL && strlen(token) > 0) {
        char filename[256];
        char mode_str[10];
        long file_size;
//virgüle göre ayrıştırıldıktan sonra bilgiler atnır
        if (sscanf(token, "%[^,],%[^,],%ld", filename, mode_str, &file_size) == 3) {
            
            char target_path[512];
            if (output_dir != NULL) {
                sprintf(target_path, "%s/%s", output_dir, filename);
            } else {
                strcpy(target_path, filename);
            }

            FILE *out_file = fopen(target_path, "w");
            if (out_file) {
                for (long i = 0; i < file_size; i++) {
                    int ch = fgetc(arch);
                    if (ch != EOF) {
                        fputc(ch, out_file);
                    }
                }
                fclose(out_file);

                mode_t mode = strtol(mode_str, NULL, 8);
                chmod(target_path, mode);

                strcpy(opened_files_list[opened_file_count++], filename);
            }
        }
        token = strtok(NULL, "|");
    }

    if (output_dir != NULL) {
        printf("%s dizininde ", output_dir);
    }
    for (int i = 0; i < opened_file_count; i++) {
        printf("%s", opened_files_list[i]);
        if (i < opened_file_count - 2) printf(", "); //aralara virgül koyulur
        else if (i == opened_file_count - 2) printf(" ve "); //sonrdan bir öncekine ve yazar
    }
    printf(" dosyaları açıldı.\n");

    free(org_buffer); //bellek geri iade edilir
    fclose(arch);
}