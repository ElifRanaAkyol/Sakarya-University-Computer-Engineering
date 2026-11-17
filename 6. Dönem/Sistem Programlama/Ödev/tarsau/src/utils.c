#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

bool is_ascii_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return false;

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch < 0 || ch > 127) { //ascii karakter kontrolü
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;  //bayt cindinden dosya boyutu
    }
    return -1;
}

int get_file_permissions(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_mode & 0777;
    }
    return 0;
}