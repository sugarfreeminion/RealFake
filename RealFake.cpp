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
                unsigned int index = 0;
                unsigned int innerIndex = 0;
                unsigned int sum = 0;

                while(index < 19)
                {
                    if(buffer[index] != ' ')
                    {
                        while(innerIndex < 4)
                        {
                            if(innerIndex == 0 || innerIndex == 2)
                            {
                                //printf("Index Val: %u\n", (buffer[index]-48)*2);

                                sum = sum + ((buffer[index]-48)*2);
                            }
                            else
                            {
                                //printf("Index Val: %u\n",buffer[index]-48);   
                                sum = sum + (buffer[index]-48);
                            }
                            ++innerIndex;
                            ++index;
                        }

                        innerIndex = 0;
                    }
                    ++index;
                }
                if(sum % 10 == 0)
                {
                    printf("Real\n");
                }
                else
                {
                    printf("Fake\n");
                }
                //printf("Sum: %u\n", sum);
                //fputs(buffer,stdout);
            }
        }
        fclose(pFile);
    }

    return 0;
}
