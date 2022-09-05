#include "header.h"

int my_puts(char *str)
{
    if (printf("%s\n", str))
        return '\n';
    else
        return -1;
}

char * my_strchr(const char *str, int ch)
{
    int i = 0;
    char* ret = NULL;

    while (str[i])
    {
        if (str[i] == ch)
        {
            ret = (char *)(str + i);
            break;
        }
        i++;
    }
    return ret;
}

size_t my_strlen(const char *str)
{
    size_t i = 0;

    while (str[i] != 0)
        i++;
    return i;
}

char * my_strcpy(char *dest, const char *str)
{
    int i = 0;

    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }

    dest[i + 1] = str[i + 1];

    return dest;
}

char * my_strncpy(char * dest, const char * str, size_t len)
{
    unsigned int i = 0;
    for (; i < len; i++)
        dest[i] = str[i];

    dest[i] = 0;

    return dest;
}

char * my_strcat(char * dest, const char * str)
{
    int i = my_strlen(str);

    int start_second = i;

    while (*(str + i - start_second) != 0)
    {
        dest[i] = str[i - start_second];
        i++;
    }

    dest[i] = 0;

    return dest;
}

char * my_strncat(char * dest, const char * str, size_t len)
{
    unsigned int i = my_strlen(dest);

    int start_second = i;

    for (;i < len; i++)
        dest[i] = str[i - start_second];

    dest[i] = 0;

    return dest;
}

char * my_fgets(char * str, int num, FILE * stream)
{
    int  i = 0;
    int ch = 0;

    while ((ch = getc(stream)) != EOF and ch != '\n' and i < (num - 1))
    {
        str[i] = (char)ch;
        i++;
    }

    if (i < num - 1)
    {
        switch(ch)
        {
            case EOF: return NULL;
                break;

            case '\n':
            {
                *(str + i) = 0;
                return str;
            }
                break;

            default: return NULL;
                break;
        }
    }
    else
    {
        str[i] = 0;
        return str;
    }
}

char * my_strdup(const char * str)
{
    size_t len = my_strlen(str) + 1;

    char * copy_str = (char*) malloc(len * sizeof(char));

    if (copy_str != NULL)
    {
        int i = my_strlen(str);

        *(copy_str + i) = 0;

        return copy_str;
    }
    else
        return NULL;

}

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    unsigned int i = 0;
    int ch = 0;

    while ((ch = getc(stream)) != '\n' and ch != EOF)
        i++;

    if (i == 0)
        return -1;

    i++;

    if (*n > 0)
    {
        while (*n < i)
            *n *= 2;

        *lineptr = (char*) realloc(*lineptr, sizeof(char) * (*n));
    }
    else
    {
        *n = 32;
        while (*n < i)
            *n *= 2;

        *lineptr = (char*) realloc(*lineptr, sizeof(char) * (*n));
    }

    int c = 0;

    rewind(stream);

    while ((ch = getc(stream)) != '\n' and ch != EOF)
    {
        *(lineptr[c]) = (char) ch;
        c++;
    }

    if (ch == EOF)
        return -1;

    *(lineptr[c]) = (char) ch;

    return i;
}

int my_strcmp(const char *str1, const char *str2)
{
    size_t len1 = 0, len2 = 0;

    len1 = my_strlen(str1);
    len2 = my_strlen(str2);

    if (len1 > len2)
    {
        unsigned i = 0;
        for (; i < len2; i++)
        {
            if (str1[i] != str2[i])
                return str1[i] - str2[i];
        }
        return str1[i];
    }
    else if (len1 < len2)
    {
        unsigned i = 0;
        for (; i < len1; i++)
        {
            if (str1[i] != str2[i])
                return str1[i] - str2[i];
        }
        return -str2[i];
    }
    return 0;
}
