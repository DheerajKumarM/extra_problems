#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *in, *out;
    int count = 0,k=5;
    long int pos;
    char s[10000],ch;
    in = fopen("file1.txt", "r");
    if (in == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fseek(in,0,SEEK_END);
    pos = ftell(in);
    while(pos)
    {
        fseek(in,--pos,SEEK_SET);
        if (fgetc(in) == '\n')
            count++;

        if (count == k)
            break;
    }
    while (fgets(s, sizeof(s), in))
    {
        printf("%s",s);
    }
    fclose(in);
    return 0;
}
