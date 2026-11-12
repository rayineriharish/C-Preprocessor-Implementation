#include"header.h"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage : ./pre filename.c\n");
        return 1;
    }

    int ch, size = 0;
    char s[100], key[] = "#include";
    char *p;

    strcpy(s, argv[1]);

    // Change .c to .i
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '.')
        {
            s[i] = '\0';
            break;
        }
    }

    strcat(s, ".i");

    FILE *fs = fopen(argv[1], "r");

    if(fs == NULL)
    {
        printf("File is not there\n");
        fclose(fs);
        return 1;
    }

    FILE *fd = fopen(s, "w");

    if(fd == NULL)
    {
        printf("File is not there\n");
        fclose(fs);
        fclose(fd);
        return 1;
    }

    // Count number of characters
    while((ch = fgetc(fs)) != EOF)
        size++;

    rewind(fs);

    // DMA allocation
    p = malloc(size + 1);

    // Copy complete file content
    fread(p, 1, size, fs);
    p[size] = '\0';

    // Header file inclusion
    header(p, fd, key);

    // Comment removal
    comment(&p);

    // Macro replacement
    macro(p, fd);

    free(p);

    fclose(fs);
    fclose(fd);

    return 0;
}