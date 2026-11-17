#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define MAX_FILES 32
#define MAX_TOTAL_SIZE (200 * 1024 * 1024) // giriş dosyaları için maks 200 mb

bool is_ascii_file(const char *filename);
long get_file_size(const char *filename);
int get_file_permissions(const char *filename);

#endif