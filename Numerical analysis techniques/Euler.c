#include <math.h>
#include <stdio.h>

double f(const double x, const double y)
{
    return -100 * y + 5 * pow(x, 3. / 2) * (1 + 40 * x);
}

main()
{
    int i;
    double x, y;
    const double h = 0.0227;
    FILE *fPtr = fopen("AA.DAT", "w");
    for (i = 0, x = 0, y = 0; x <= 1; ++i, x += h) {
        y = y + f(x, y) * h;
        printf("%2d %f %f\n", i, x, y);
        if (fPtr) {
            fprintf(fPtr, "%2d %f %f\n", i, x, y);
        }
    }
    fclose(fPtr);
    return 0;
}
