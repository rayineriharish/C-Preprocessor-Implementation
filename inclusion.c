#include"header.h"

// Header file inclusion

void header(char *p, FILE *fd, char *key)
{
    int keylen = strlen(key);
    int c = 0, i = 0;

    char s[100], path[200];
    FILE *fs;
    int ch;

    while(*p)
    {
        if(*p == '#')
        {
            c = 0;

            while(*p == key[c])
            {
                c++;
                p++;
            }

            if(c == keylen)
            {
                while(*p != '<' )
                    p++;

                if(*p == '<')
                {
                    p++;
                    i = 0;

                    while( *p != '>' && i < 99)
                    {
                        s[i++] = *p;
                        p++;
                    }

                    s[i] = '\0';

                    if(*p == '>')
                    {
                        strcpy(path, "/usr/include/");
                        strcat(path, s);

                        fs = fopen(path, "r");

                        if(fs == NULL)
                        {
                            printf("Header file not found: %s\n", s);
                            p++;
                            return;
                        }

                        // Copy header contents
                        while((ch = fgetc(fs)) != EOF)
                            fputc(ch, fd);

                        fclose(fs);
                    }
                }
            }
        }

        if(*p)
            p++;
    }
}