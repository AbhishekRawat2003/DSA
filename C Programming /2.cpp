#include <stdio.h>
int main()
{
    int i, j, k = 0;
    j = 2 * 3 / 4 + 2.0 / 5 + 8 / 5;
    printf("J: %d",j);
    k -= --j;
    for (i = 0; i < 5; i++)
    {
        switch (i + k)
        {
        case 1:
        case 2:
            printf("\n%d", i + k);
        case 3:
            printf("\n%d", i + k);
        default:
            printf("\n%d", i + k);
        }
    }
    return 0;
}