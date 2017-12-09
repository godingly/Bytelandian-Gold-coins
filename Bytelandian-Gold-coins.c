#include <stdio.h>

unsigned array[31][20] = {0};

//Calc value of num, where num = original_num divided by 2 for nthDiv2 times, and by 3 for nthDiv3 times
unsigned value(unsigned num, unsigned nthDiv2, unsigned nthDiv3)
{
    // if value of n when divided by nthDiv2 and nthDiv3 is already calculated just return it from table
    if (array[nthDiv2][nthDiv3] != 0)
        return array[nthDiv2][nthDiv3];
    // Base case - If trying to calculate value of number smaller than 12, return num
    else if (num < 12)
        return num;

    // notice that for all numbers >= 12, dividing the coin is better strategy than keeping it as it is
    // else - calculate the value we can get by splitting the coin into the coins num/2, num/3, and num/4
    else {
        unsigned result = value(num/2, nthDiv2+1, nthDiv3) +
                value(num/3, nthDiv2, nthDiv3+1) + value(num/4, nthDiv2+2, nthDiv3);
        // Memoize result - save it to our array, so we won't have to recompute it
        array[nthDiv2][nthDiv3] = result;
        return result;
    }
}

int main(void)
{
    unsigned original_num = 0;
    while (scanf("%u", &original_num) != EOF) {
        for (char i = 0; i < 31; i++)
            for (char j = 0; j < 20; j++)
                array[i][j] = 0;
        printf("%u\n", value(original_num, 0, 0));
    }
    return 0;
}
