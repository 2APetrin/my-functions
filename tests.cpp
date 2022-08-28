#include "header.h"

char str[20]  = "Poltorashka";
char str2[20] = "Phystech";
char buf[10]  = {0};
char cat[5]   = " cat";
char file[50] = {0};
char * line   = NULL;

size_t len    = 0;

FILE * fp     = NULL;

int num = 0;

void my_puts_test(void)
{
    my_puts(str);
    printf("my_puts works\n\n");
}

void my_strchr_test(void)
{
    printf("%p", my_strchr(str, 'a'));
    printf(" - my_strchr works\n\n");                // выводит найденный символ по возвращаемому адресу
}

void my_strlen_test(void)
{
    printf("poltorashka = %u symbols", my_strlen(str));
    printf(" - my_strlen works\n\n");                // выводит количество символов в строке
}

void my_strcpy_test(void)
{
    printf("Before %s", str2);                     // выводит строку до копирования
    my_strcpy(str2, str);
    printf("After %s", str2);
    printf(" - my_strcpy works\n\n");                     // выводит строку после копирования
}

void my_strncpy_test(void)
{
    my_strncpy(buf, str, sizeof(buf) - 1);
    printf("Cut poltorashka = %s", buf);
    printf(" - my_strncpy works\n\n");                      // выводит скопированную строку
}

void my_strcat_test(void)
{
    my_strcat(str, cat);
    printf("Poltorashka + cat = %s", str);
    printf(" - my_strcat works\n\n");                      // выводит полученную строку
}

void my_strncat_test(void)
{
    my_strncat(str, str2, sizeof(str) - 1);
    printf("%s", str);
    printf(" - my_strncat works\n\n");                      // выводит полученную строку
}

void my_fgets_test(void)
{
    if((fp = fopen("file.txt", "r")) != NULL)
    {
        my_fgets(file, 20, fp);
        printf("%s", file);                 // выводит полученную из файла строку
        fclose(fp);
    }
    printf(" - my_fgets works\n\n");
}

void my_strdup_test(void)
{
    printf("%s\n", my_strdup(str));             // выводит скопированную строку
    printf("%p\n", my_strdup(str));             // выводит адрес скопированной строки
    printf("%p\n", str);
    printf("my_strdup works\n\n");                      // адрес изанчальной строки
}

void my_getline_test(void)
{
    if((fp = fopen("file2.txt", "r")) != NULL)
    {
        line = (char*) malloc(len);
        num = my_getline(&line, &len, fp);
        printf("%u bytes\n", len);
        printf("your line with %d symbols is: %s", num, line);
        fclose(fp);
    }
    printf("my_getline works\n\n");
}

void my_strcmp_test(void)
{
    printf("%s - 1\n", str);
    printf("%s - 2\n", str2);
    printf("%d", my_strcmp(str, str2));
    printf(" - my_strcmp works\n\n");
}
