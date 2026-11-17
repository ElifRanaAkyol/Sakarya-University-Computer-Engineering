#include "pack.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

void pack_files(int file_count, char *input_files[], const char *output_file) {
    if (file_count > MAX_FILES) {
            printf(" giriş dosyası sayısı en fazla %d olmalı!!\n", MAX_FILES);
        return;
    }

    long total_size = 0;
    for (int i = 0; i < file_count; i++) {
        if (!is_ascii_file(input_files[i])) { //sadece ascii olmalıdır kontrol yapar
            printf("%s giriş dosyasının formatı uyumsuzdur!\n", input_files[i]);
            return;
        }
        
        long size = get_file_size(input_files[i]);
        if (size == -1) {   //dosya var mı kontrol edilir
            printf("%s dosyası okunamadı!\n", input_files[i]);
            return;
        }
        total_size += size;
    }

    if (total_size > MAX_TOTAL_SIZE) {  //200mb geçmemesi için kontrol yapılır
        printf("giriş dosyalarının maksimum 200 mb olmalı!\n");
        return;
    }


    long org_section_size = 0;
    for (int i = 0; i < file_count; i++) {
        char temp[512];
        char *base_name = basename(input_files[i]); 
        int perms = get_file_permissions(input_files[i]);
        long size = get_file_size(input_files[i]);
        
        sprintf(temp, "|%s,%04o,%ld", base_name, perms, size);
        org_section_size += strlen(temp);
    }
    org_section_size += 1; // sondaki kapatma "|" karakteri için 1 bayt eklenir
    
    long total_header_size = 10 + org_section_size;

    FILE *out = fopen(output_file, "w");
    if (!out) {
        printf("çıktı dosyası oluşturulamadı!\n");
        return;
    }

    fprintf(out, "%010ld", total_header_size);

    for (int i = 0; i < file_count; i++) {
        char *base_name = basename(input_files[i]);
        int perms = get_file_permissions(input_files[i]); //izinler alınır
        long size = get_file_size(input_files[i]); //boyut alınır
        fprintf(out, "|%s,%04o,%ld", base_name, perms, size);
    }
    fprintf(out, "|"); 

    for (int i = 0; i < file_count; i++) {
        FILE *in = fopen(input_files[i], "r");
        if (in) {
            int ch;
            while ((ch = fgetc(in)) != EOF) {
                fputc(ch, out);
            }
            fclose(in);
        }
    }

    fclose(out);
    printf("Dosyalar birleştirildi.\n");
}