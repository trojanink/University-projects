#include <math.h>
#include <stdio.h>

double det(double a00, double a01, double a02, double a03, double a10, double a11, double a12, double a13, double a20, double a21, double a22, double a23, double a30, double a31, double a32, double a33)
{
    return a00 * (a11 * (a22 * a33 - a23 * a32) - a12 * (a21 * a33 - a23 * a31) + a13 * (a21 * a32 - a22 * a31)) - a01 * (a10 * (a22 * a33 - a23 * a32) - a12 * (a20 * a33 - a23 * a30) + a13 * (a20 * a32 - a22 * a30)) + a02 * (a10 * (a21 * a33 - a23 * a31) - a11 * (a20 * a33 - a23 * a30) + a13 * (a20 * a31 - a21 * a30)) - a03 * (a10 * (a21 * a32 - a22 * a31) - a11 * (a20 * a32 - a22 * a30) + a12 * (a20 * a31 - a21 * a30));
}
double f1(double x1, double x2, double x3, double x4)
{
    return 3 * x2 + x3 * x4 - 7.9;
}
double f2(double x1, double x2, double x3, double x4)
{
    return x1 + 2 * x2 + x3 + 4 * x4 - 20.7;
}
double f3(double x1, double x2, double x3, double x4)
{
    return pow(x1, 3) + pow(x3, 3) + x4 - 21.218;
}
double f4(double x1, double x2, double x3, double x4)
{
    return pow(x1, 2) + 2 * x1 * x2 + pow(x4, 3) - 15.88;
}

main()
{
    const double akr = 0.5 * pow(10, -5);
    double x1 = 1, x2 = 1, x3 = 1, x4 = 1, dx1, dx2, dx3, dx4;
    int i = 0;
    FILE *fPtr = fopen("AA.DAT", "w");
    do {
        i += 1;
        double detA = det((f1(x1 + akr, x2, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2 + akr, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3 + akr, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3, x4 + akr) - f1(x1, x2, x3, x4)) / akr, (f2(x1 + akr, x2, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2 + akr, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3 + akr, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3, x4 + akr) - f2(x1, x2, x3, x4)) / akr, (f3(x1 + akr, x2, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2 + akr, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3 + akr, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3, x4 + akr) - f3(x1, x2, x3, x4)) / akr, (f4(x1 + akr, x2, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2 + akr, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3 + akr, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3, x4 + akr) - f4(x1, x2, x3, x4)) / akr);
        dx1 = det(-f1(x1, x2, x3, x4), (f1(x1, x2 + akr, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3 + akr, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3, x4 + akr) - f1(x1, x2, x3, x4)) / akr, -f2(x1, x2, x3, x4), (f2(x1, x2 + akr, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3 + akr, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3, x4 + akr) - f2(x1, x2, x3, x4)) / akr, -f3(x1, x2, x3, x4), (f3(x1, x2 + akr, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3 + akr, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3, x4 + akr) - f3(x1, x2, x3, x4)) / akr, -f4(x1, x2, x3, x4), (f4(x1, x2 + akr, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3 + akr, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3, x4 + akr) - f4(x1, x2, x3, x4)) / akr) / detA;
        dx2 = det((f1(x1 + akr, x2, x3, x4) - f1(x1, x2, x3, x4)) / akr, -f1(x1, x2, x3, x4), (f1(x1, x2, x3 + akr, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3, x4 + akr) - f1(x1, x2, x3, x4)) / akr, (f2(x1 + akr, x2, x3, x4) - f2(x1, x2, x3, x4)) / akr, -f2(x1, x2, x3, x4), (f2(x1, x2, x3 + akr, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3, x4 + akr) - f2(x1, x2, x3, x4)) / akr, (f3(x1 + akr, x2, x3, x4) - f3(x1, x2, x3, x4)) / akr, -f3(x1, x2, x3, x4), (f3(x1, x2, x3 + akr, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3, x4 + akr) - f3(x1, x2, x3, x4)) / akr, (f4(x1 + akr, x2, x3, x4) - f4(x1, x2, x3, x4)) / akr, -f4(x1, x2, x3, x4), (f4(x1, x2, x3 + akr, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3, x4 + akr) - f4(x1, x2, x3, x4)) / akr) / detA;
        dx3 = det((f1(x1 + akr, x2, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2 + akr, x3, x4) - f1(x1, x2, x3, x4)) / akr, -f1(x1, x2, x3, x4), (f1(x1, x2, x3, x4 + akr) - f1(x1, x2, x3, x4)) / akr, (f2(x1 + akr, x2, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2 + akr, x3, x4) - f2(x1, x2, x3, x4)) / akr, -f2(x1, x2, x3, x4), (f2(x1, x2, x3, x4 + akr) - f2(x1, x2, x3, x4)) / akr, (f3(x1 + akr, x2, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2 + akr, x3, x4) - f3(x1, x2, x3, x4)) / akr, -f3(x1, x2, x3, x4), (f3(x1, x2, x3, x4 + akr) - f3(x1, x2, x3, x4)) / akr, (f4(x1 + akr, x2, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2 + akr, x3, x4) - f4(x1, x2, x3, x4)) / akr, -f4(x1, x2, x3, x4), (f4(x1, x2, x3, x4 + akr) - f4(x1, x2, x3, x4)) / akr) / detA;
        dx4 = det((f1(x1 + akr, x2, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2 + akr, x3, x4) - f1(x1, x2, x3, x4)) / akr, (f1(x1, x2, x3 + akr, x4) - f1(x1, x2, x3, x4)) / akr, -f1(x1, x2, x3, x4), (f2(x1 + akr, x2, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2 + akr, x3, x4) - f2(x1, x2, x3, x4)) / akr, (f2(x1, x2, x3 + akr, x4) - f2(x1, x2, x3, x4)) / akr, -f2(x1, x2, x3, x4), (f3(x1 + akr, x2, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2 + akr, x3, x4) - f3(x1, x2, x3, x4)) / akr, (f3(x1, x2, x3 + akr, x4) - f3(x1, x2, x3, x4)) / akr, -f3(x1, x2, x3, x4), (f4(x1 + akr, x2, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2 + akr, x3, x4) - f4(x1, x2, x3, x4)) / akr, (f4(x1, x2, x3 + akr, x4) - f4(x1, x2, x3, x4)) / akr, -f4(x1, x2, x3, x4)) / detA;
        x1 += dx1;
        x2 += dx2;
        x3 += dx3;
        x4 += dx4;
        printf("  %3d  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f   %15.5f  %15.5f  %15.5f  %15.5f\n", i, x1, x2, x3, x4, dx1, dx2, dx3, dx4, f1(x1, x2, x3, x4), f2(x1, x2, x3, x4), f3(x1, x2, x3, x4), f4(x1, x2, x3, x4));
        if (fPtr) {
            fprintf(fPtr, "  %3d  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f  %15.5f   %15.5f  %15.5f  %15.5f  %15.5f\n", i, x1, x2, x3, x4, dx1, dx2, dx3, dx4, f1(x1, x2, x3, x4), f2(x1, x2, x3, x4), f3(x1, x2, x3, x4), f4(x1, x2, x3, x4));
        }
    } while (fabs(dx1) >= akr || fabs(dx2) >= akr || fabs(dx3) >= akr || fabs(dx4) >= akr);
    fclose(fPtr);
    return 0;
}
