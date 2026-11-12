#include"header.h"

// Macro handling
char macro_name[100][50];
char macro_value[100][50];
int count = 0;

void macro(char *p, FILE *fd)
{
    char *q = p, *start, *temp;
    char key[20];
    char name[50];
    char value[50];
    char line[256];
    int i = 0, n, v;

    // Storing macro names and values
    while(*q)
    {
        start = q;
        i = 0;

        while(*q && *q != '\n')
        {
//            if(i < 255)
            line[i++] = *q;
            q++;
        }

        line[i] = '\0';

        if(*q == '\n')
                q++;

        if(sscanf(line, " %s", key) )
        {
                if(strncmp(key, "#include",8) == 0)
                {
                        temp = start;

                        while(temp < q)
                        {
                                if(*temp != '\n')
                                        *temp = ' ';
                                temp++;
                        }
                }
                else if(strcmp(key, "#define") == 0)
                {
                        temp = start + 7;
                        n = 0;
                v = 0;

                // Skip spaces
                while(*temp == ' ' || *temp == '\t')
                    temp++;

                // Store macro name
                while(*temp != ' ' && *temp != '\t' &&
                      *temp != '\n' && *temp != '\0')
                {
                        name[n++] = *temp;
                    temp++;
                }
                name[n] = '\0';

                // Skip spaces
                while(*temp == ' ' || *temp == '\t')
                    temp++;

                // Store macro value
                while(*temp && *temp != '\n')
                {
                        value[v++] = *temp;
                    temp++;
                }
                value[v] = '\0';

                // Store macro name and value
                strcpy(macro_name[count], name);
                strcpy(macro_value[count], value);
                count++;

                // Replace complete #define line with spaces
                temp = start;

                while(temp < q)
                {
                    if(*temp != '\n')
                        *temp = ' ';
                    temp++;
                }
            }
        }
    }

    // Macro replacement
    replace(p, fd);
}



// Macro replace
void replace(char *p, FILE *fd)
{
    char word[50];
    char q;
    int i, j, found;

    while(*p)
    {
        // Skip string and character literals
        if(*p == '"' /*|| *p == '\''*/)
        {
            q = *p;
            fputc(*p++, fd);

            while(*p && *p != q)
            {
               // if(*p == '\\' && *(p+1))
                 //   fputc(*p++, fd);

                fputc(*p++, fd);
            }

            if(*p == q)
                fputc(*p++, fd);
        }

        // Check identifier
        else if((*p >= 'A' && *p <= 'Z') ||(*p >= 'a' && *p <= 'z') || *p == '_')
        {
            i = 0;

            while((*p >= 'A' && *p <= 'Z') ||(*p >= 'a' && *p <= 'z') ||(*p >= '0' && *p <= '9') || *p == '_')
            {
                    word[i++] = *p;

                p++;
            }

            word[i] = '\0';
            found = 0;

            for(j = 0; j < count; j++)
            {
                if(strcmp(word, macro_name[j]) == 0)
                {
                    fputs(macro_value[j], fd);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                fputs(word, fd);
        }
        else
        {
            fputc(*p, fd);
            p++;
        }
    }
}