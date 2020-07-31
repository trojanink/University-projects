#include <math.h>
#include <stdio.h>

double f(const double x, const double y)
{
    return -100 * y + 5 * pow(x, 3. / 2) * (1 + 40 * x);
}
double K1(const double h, const double x, const double y)
{
    return h * f(x, y);
}
double K2(const double h, const double x, const double y, const double x1)
{
    return h * f(x1, y + K1(h, x, y));
}

main()
{
    int i, ih0, ih1, ih2;
    double x, yh0, yh1, yh2;
    const double h0 = sqrt(0.0004), h1 = h0 / 2, h2 = h0 / 4, AKR = 0.5 * pow(10, -3);
    FILE *fPtr = fopen("AA.DAT", "w");
    for (i = ih0 = ih1 = ih2 = 0, x = 0, yh0 = yh1 = yh2 = 0; x <= 1; x+= h2, ++i) {
        printf("%f %2d %f %3d %f %d %3d %f %d\n", x, ih0, yh0, ih1, yh1, (fabs(yh0 - yh1) < AKR ? 0 : 1), ih2, yh2, (fabs(yh1 - yh2) < AKR ? 0 : 1));
        if (fPtr) {
            fprintf(fPtr, "%f %2d %f %3d %f %d %3d %f %d\n", x, ih0, yh0, ih1, yh1, (fabs(yh0 - yh1) < AKR ? 0 : 1), ih2, yh2, (fabs(yh1 - yh2) < AKR ? 0 : 1));
        }
        if (i % 1 == 0) {
            yh2 = yh2 + (K1(h2, x, yh2) + K2(h2, x, yh2, x + h2)) / 2;
            ++ih2;
        }
        if (i % 2 == 0) {
            yh1 = yh1 + (K1(h1, x, yh1) + K2(h1, x, yh1, x + h1)) / 2;
            ++ih1;
        }
        if (i % 4 == 0) {
            yh0 = yh0 + (K1(h0, x, yh0) + K2(h0, x, yh0, x + h0)) / 2;
            ++ih0;
        }
    }
    printf("%f %2d %f %3d %f %d %3d %f %d\n", x, ih0, yh0, ih1, yh1, (fabs(yh0 - yh1) < AKR ? 0 : 1), ih2, yh2, (fabs(yh1 - yh2) < AKR ? 0 : 1));
    if (fPtr) {
        fprintf(fPtr, "%f %2d %f %3d %f %d %3d %f %d\n", x, ih0, yh0, ih1, yh1, (fabs(yh0 - yh1) < AKR ? 0 : 1), ih2, yh2, (fabs(yh1 - yh2) < AKR ? 0 : 1));
    }
    fclose(fPtr);
    return 0;
}
