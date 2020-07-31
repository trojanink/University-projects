#include <math.h>
#include <stdio.h>

double F(const double t)
{
    return exp(-(t + 3) / 4) + cos(7 * (t + 3) / 4) - 6 / (t - 5);
}

main()
{
    FILE *fPtr = fopen("AA.DAT", "w");
    double I2 = (1. * F(0.577350269189626) + 1. * F(-0.577350269189626)) / 2;
    double I3 = (0.888888888888889 * F(0) + 0.555555555555556 * F(0.774596669241483) + 0.555555555555556 * F(-0.774596669241483)) / 2;
    double I5 = (0.568888888888889 * F(0) + 0.478628670499366 * F(0.538469310105683) + 0.478628670499366 * F(-0.538469310105683) + 0.236926885056189 * F(0.906179845938664) + 0.236926885056189 * F(-0.906179845938664)) / 2;
    printf("n=2 apot=%10.8f\nn=3 apot=%10.8f\nn=5 apot=%10.8f\n", I2, I3, I5);
    if (fPtr) {
        fprintf(fPtr, "n=2 apot=%10.8f\nn=3 apot=%10.8f\nn=5 apot=%10.8f\n", I2, I3, I5);
    }
    fclose(fPtr);
    return 0;
}
