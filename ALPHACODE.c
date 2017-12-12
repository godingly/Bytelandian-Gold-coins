#include <stdio.h>
#include <string.h>

void decode(char* str)
{
    unsigned long long w2, w1;
    w2 = w1 = 1;
    for (int i = (int) strlen(str) - 2; i >=0 ; i--)
    {
    	if (str[i] == '0' || str[i+1] == '0' || str[i+2] == '0') ;
        else if ((str[i] == '1' && str[i+1] >= '1') || (str[i] == '2' && (str[i+1] <= '6' && str[i+1] >= '1')))
        {
            int temp = w1;
            w1 = w1 + w2;
            w2 = temp;
            continue;
        }
        w2 = w1;
    }
    printf("%llu\n", w1);
}

int main()
{
    char input[5004] = {0};

    while(fgets(input, 5002, stdin) != NULL)
    {
        if(input[0] == '0') exit(0);
        input[strcspn(input, "\n")] = 0;
        decode(input);
    }
}
