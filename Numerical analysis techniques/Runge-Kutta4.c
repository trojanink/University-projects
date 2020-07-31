#include <math.h>
#include <stdio.h>

double f(const double x, const double y1, const double y2)
{
    return y2;
}
double g(const double x, const double y1, const double y2)
{
    return -y1 / pow(x, 2) - 3 * y2 / x;
}

main()
{
    double x, y1, y2, K1, K2, K3, K4, L1, L2, L3, L4;
    const double h = 0.0005;
    FILE *fPtr = fopen("AA.DAT", "w");
    for (x = 1, y1 = 2, y2 = -2; x <= 2; x+= h) {
        printf("%.8f %.8f %.8f\n", x, y1, y2);
        if (fPtr) {
            fprintf(fPtr, "%.8f %.8f %.8f\n", x, y1, y2);
        }
        K1 = h * f(x, y1, y2);
        L1 = h * g(x, y1, y2);
        K2 = h * f(x + h / 2, y1 + K1 / 2, y2 + L1 / 2);
        L2 = h * g(x + h / 2, y1 + K1 / 2, y2 + L1 / 2);
        K3 = h * f(x + h / 2, y1 + K2 / 2, y2 + L2 / 2);
        L3 = h * g(x + h / 2, y1 + K2 / 2, y2 + L2 / 2);
        K4 = h * f(x + h, y1 + K3, y2 + L3);
        L4 = h * g(x + h, y1 + K3, y2 + L3);
        y1 = y1 + (K1 + 2 * K2 + 2 * K3 + K4) / 6;
        y2 = y2 + (L1 + 2 * L2 + 2 * L3 + L4) / 6;
    }
    fclose(fPtr);
    return 0;
}