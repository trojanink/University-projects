#include "stdio.h"
#include "math.h"

double f(const double x)
{
    return x + exp(-10. * pow(x, 2)) * cos(x);
}

main()
{
    const double akr = 0.5 * pow(10, -10);
    double x_1 = -0.69, x0 = -0.7, x, err;
    int i = 0;
    FILE *fPtr = fopen("AA.DAT", "w");
    do {
        x = x0 - (x0 - x_1) / (f(x0) - f(x_1)) * f(x0);
        err = fabs(x - x0);
        i = i + 1;
        printf("  %4d  %15.10f  %15.10f  %15.10f\n", i, x, f(x), x - x0);
        if (fPtr) {
            fprintf(fPtr, "  %4d  %15.10f  %15.10f  %15.10f\n", i, x, f(x), x - x0);
        }
        x_1 = x0;
        x0 = x;
    } while (err >= akr);
    fclose(fPtr);
    return 0;
}
