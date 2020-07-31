#include <stdio.h>
#include <math.h>

#define N 10.

double f1k(double x1, double x2, int k)
{
    return pow(x1, 3) + 2 * x2 - 21 * (1 - k / N);
}
double f2k(double x1, double x2, int k)
{
    return 7 * x1 + pow(x2, 2) - 30;
}

main()
{
    const double akr = 0.5 * pow(10, -5);
    double x1 = 3., x2 = -3., dx1, dx2;
    int k;
    FILE *fPtr = fopen("AA.DAT", "w");
    for (k = 1; k <= N; ++k) {
        printf("K = %d:\n", k);
        int i = 0;
        do {
            i += 1;
            dx1 = (2 * f2k(x1, x2, k) - 2 * x2 * f1k(x1, x2, k)) / (6 * pow(x1, 2) * x2 - 14);
            dx2 = (7 * f1k(x1, x2, k) - 3 * pow(x1, 2) * f2k(x1, x2, k)) / (6 * pow(x1, 2) * x2 - 14);
            x1 += dx1;
            x2 += dx2;
            printf("  %3d  %10.5f  %10.5f  %10.5f  %10.5f  %10.5f  %10.5f\n", i, x1, x2, dx1, dx2, f1k(x1, x2, k), f2k(x1, x2, k));
            if (fPtr) {
                fprintf(fPtr, "  %3d  %10.5f  %10.5f  %10.5f  %10.5f  %10.5f  %10.5f\n", i, x1, x2, dx1, dx2, f1k(x1, x2, k), f2k(x1, x2, k));
            }
        } while (fabs(dx1) >= akr || fabs(dx2) >= akr);
    }
    return 0;
}
