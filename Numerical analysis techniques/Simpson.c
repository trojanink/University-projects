#include <math.h>
#include <stdio.h>

double f(const double x)
{
    return exp(-x / 2) + cos(3.5 * x) - 3 / (x - 4);
}

double I(const int n, const double a, const double b)
{
    int i;
    const double h = (b - a) / n;
    double I = 0;
    for (i = 0; i <= n; ++i) {
        if (i == 0 || i == n) {
            I += f(a + i * h);
        } else if (i % 2 == 0) {
            I += 2 * f(a + i * h);
        } else {
            I += 4 * f(a + i * h);
        }
    }
    I *= h / 3;
    return I;
}

main()
{
    FILE *fPtr = fopen("AA.DAT", "w");
    double I1 = I(50, 1, 2), I2 = I(100, 1, 2);
    printf("a=%f b=%f\nn=%3d apot=%10.8f\nn=%3d apot=%10.8f\nerror=%.10f\n", 1., 2., 50, I1, 100, I2, fabs(I1 - I2));
    if (fPtr) {
        fprintf(fPtr, "a=%f b=%f\nn=%3d apot=%10.8f\nn=%3d apot=%10.8f\nerror=%.10f\n", 1., 2., 50, I1, 100, I2, fabs(I1 - I2));
    }
    fclose(fPtr);
    return 0;
}
