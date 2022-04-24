#include <stdio.h>
#include <math.h>
int main()
{
    unsigned long long x, y;
    while (1)
    {
        scanf("%llu %llu", &x, &y);
        if (x == -1)
            return 0;
        unsigned long long w = log2(x);
        unsigned long long KK = 2 * x - (w + 1) * 2;
        if (y <= KK)
            printf("Y\n");
        else
            printf("N\n");
    }
}
