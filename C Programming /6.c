#include <stdio.h>
int fun(int n, int *f_p)
{
    int t, f;
    printf("\nn, *f_p: %d, %d: ",n,*f_p);
    if (n <= 1)
    {
        *f_p = 1;
        printf("\ninside (n<=1) *f_p: %d",*f_p);
        return 1;
    }
    t = fun(n - 1, f_p);
    printf("\nt: %d ",t);
    f = t + *f_p;
    printf("\nf: %d",f);
    *f_p = t;
    printf("\n*f_p: %d",*f_p);
    return f;
}
int main()
{
    int x = 15;
    printf("\n output: %d",fun(5, &x));
    return 0;
}