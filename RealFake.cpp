#include <stdio.h>

int main(int argc, char *argv[])
{
    char buffer[21];

    FILE *pFile;

    pFile = fopen(argv[1], "r");

    if(pFile == NULL)
    {
        printf("ERROR Opening %s", argv[1]);
    }
    else
    {
        while(!feof(pFile))
        {
            if( fgets(buffer, 21, pFile) == NULL )
            {
                break;
            }
            else
            {
                fputs(buffer,stdout);
            }
        }
        fclose(pFile);
    }

    return 0;
}
