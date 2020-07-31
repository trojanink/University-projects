#include <math.h>
#include <stdio.h>

double factorial(const int x);
double L(const double *X, const int k, const int n, const double x);
double E(const double *X, const int xi, const int n, const double x);

double factorial(const int x)
{
    int i;
    double fact = 1;
    for (i = 1; i <= x; ++i) {
        fact *= i;
    }
    return fact;
}
double L(const double *X, const int k, const int n, const double x)
{
    int i;
    double P = 1;
    for (i = 0; i <= n; ++i) {
        if (i != k) {
            P *= (x - X[i]) / (X[k] - X[i]);
        }
    }
    return P;
}
double E(const double *X, const int xi, const int n, const double x)
{
    int i;
    double P = cos(xi + (n + 1) * M_PI / 2) / factorial(n + 1);
    for (i = 0; i <= n; ++i) {
        P *= x - X[i];
    }
    return P;
}

main()
{
    FILE *fPtr = fopen("AA.DAT", "w");
    const double X[4] = {0, M_PI / 4, M_PI / 3, M_PI / 2};
    const double Y[4] = {1, sqrt(2) / 2, 1. / 2, 0};
    int i;
    double S = 0, fE = 0;
    for (i = 0; i < 4; ++i) {
        double fEi = fabs(E(X, X[i], 3, M_PI / 12));
        if (fE < fEi) {
            fE = fEi;
        }
        S += L(X, i, 3, M_PI / 12) * Y[i];
    }
    printf("cos(pi/12)=%f\n", S);
    if (fPtr) {
        fprintf(fPtr, "cos(pi/12)=%f\n", S);
    }
    printf("|E|<=%f\n", fE);
    if (fPtr) {
        fprintf(fPtr, "|E|<=%f\n", fE);
    }
    fclose(fPtr);
    return 0;
}
