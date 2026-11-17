#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"
#include "unpack.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Kullanım:\n");
        printf("  Arşivleme: %s -b <dosyalar...> -o <output.sau>\n", argv[0]);
        printf("  Açma:      %s -a <archive.sau> [hedef_dizin]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-b") == 0) {
        int input_file_count = 0;
        char *input_files[32]; //dizide en fazla 32 dosya saklanabilir
        const char *output_file = "a.sau"; 

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-o") == 0) { //eğer terminale -o yazıldıysa bu bloğa girilir
                if (i + 1 < argc) { //-o dan sonra bir kelime var mı kontrol edilir
                    output_file = argv[i + 1]; //bu kelime yeni dosya adımız olur  
                    i++; 
                } else {
                    printf("Fosya adı belirtiltiniz!\n");
                    return 1;
                }
            } else {//-o yazılmadıysa bir arşiv dosyasıdır. dosya listeye eklenir
                if (input_file_count < 32) {
                    input_files[input_file_count++] = argv[i];
                } else {
                    printf("makisimum 32 dosya saklanabilir!\n");
                    return 1;
                }
            }
        }

        if (input_file_count == 0) {
            printf("arşivlenmiş dosya yok!\n");
            return 1;
        }

        pack_files(input_file_count, input_files, output_file);
    }
    
    else if (strcmp(argv[1], "-a") == 0) {
    
        if (argc < 3 || argc > 4) {
            printf("Arşiv dosyası uygunsuz veya bozuk!\n");
            return 1;
        }

        const char *archive_file = argv[2]; //girilen arşiv dosya adı verilir
        const char *output_dir = (argc == 4) ? argv[3] : NULL; //varsa hedef klasör adı verilir

        unpack_archive(archive_file, output_dir);
    } 
    
    else {
        printf(" -b veya -a kullanmalısınız!!.\n");
    }

    return 0;
}