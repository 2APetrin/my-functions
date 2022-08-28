#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int    my_puts(char *str);
char * my_strchr(const char *str, int ch);
size_t my_strlen(const char *str);
char * my_strcpy(char *dest, const char *str);
char * my_strncpy(char * dest, const char * str, size_t len);
char * my_strcat(char * dest, const char * str);
char * my_strncat(char * dest, const char * str, size_t len);
char * my_fgets(char * str, int num, FILE * stream);
char * my_strdup(const char * str);
size_t my_getline(char **lineptr, size_t *n, FILE *stream);
int    my_strcmp(const char *str1, const char *str2);

void my_puts_test(void);
void my_strchr_test(void);
void my_strlen_test(void);
void my_strcpy_test(void);
void my_strncpy_test(void);
void my_strcat_test(void);
void my_strncat_test(void);
void my_fgets_test(void);
void my_strdup_test(void);
void my_getline_test(void);
void my_strcmp_test(void);

#endif // HEADER_H_INCLUDED
