#include"header.h"

// Comment removal
void comment(char **p)
{
    char *s = *p;

    while(*s)
    {
        // Single-line comment
        if(*s == '/' && *(s+1) == '/')
        {
            while(*s && *s != '\n')
            {
                *s = ' ';
                s++;
            }
        }

        // Multi-line comment
        else if(*s == '/' && *(s+1) == '*')
        {
            *s = ' ';
            *(s+1) = ' ';
            s += 2;

            while(*s)
            {
                if(*s == '*' && *(s+1) == '/')
                {
                    *s = ' ';
                    *(s+1) = ' ';
                    s += 2;
                    break;
                }

                if(*s != '\n')
                    *s = ' ';

                s++;
            }
        }
        else
        {
            s++;
        }
    }
}