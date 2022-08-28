#include "header.h"

int main()
{
    char str[20]  = "Poltorashka";
    char str2[20] = "Phystech";
    char buf[10]  = {0};
    char cat[5]   = " cat";
    char file[50] = {0};
    char * line   = NULL;

    size_t len    = 0;

    FILE * fp     = NULL;

    int num = 0;

    my_puts(str);

    printf("\n%p\n\n", my_strchr(str, 'a'));    // ������� ��������� ������ �� ������������� ������

    printf("%u\n\n", my_strlen(str));           // ������� ���������� �������� � ������

    printf("%s\n\n", str2);                     // ������� ������ �� �����������
    my_strcpy(str2, str);
    printf("%s\n\n", str2);                     // ������� ������ ����� �����������

    my_strncpy(buf, str, sizeof(buf) - 1);
    printf("%s\n\n", buf);                      // ������� ������������� ������

    my_strcat(str, cat);
    printf("%s\n\n", str);                      // ������� ���������� ������

    my_strncat(str, str2, sizeof(str) - 1);
    printf("%s\n\n", str);                      // ������� ���������� ������

    if((fp = fopen("file.txt", "r")) != NULL)
    {
        my_fgets(file, 20, fp);
        printf("%s\n\n", file);                 // ������� ���������� �� ����� ������
        fclose(fp);
    }

    printf("%s\n", my_strdup(str));             // ������� ������������� ������
    printf("%p\n", my_strdup(str));             // ������� ����� ������������� ������
    printf("%p\n\n", str);                      // ����� ����������� ������

    if((fp = fopen("file2.txt", "r")) != NULL)
    {
        line = (char*) malloc(len);
        num = my_getline(&line, &len, fp);
        printf("%u bytes\n", len);
        printf("your line with %d symbols is: %s\n", num, line);
        fclose(fp);
    }

    printf("%s - str\n", str);
    printf("%s - str2\n", str2);
    printf("%d", my_strcmp(str, str2));

    getchar();

    return 0;
}
