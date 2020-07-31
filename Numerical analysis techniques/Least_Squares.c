#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double ** initSquareArray(const int n);
void freeSquareArray(double **A, const int n);
double ** cofactor(const double **A, const int n, const int row, const int col);
double determinant(const double **A, const int n);

double leftSum(const double *X, const int n, const double power);
double ** leftMatrix(const double *A, const int n, const int degree);
double rightSum(const double *X, const double *Y, const int n, const double power);
double * rightVector(const double *X, const double *Y, const int n, const int degree);
double ** replaceColumn(const int nCol, const double **A, const double *col, const int n);

double ** initSquareArray(const int n)
{
    double **A = 0;
    if (A = (double **)calloc(n, sizeof(*A))) {
        int i;
        for (i = 0; i < n; ++i) {
            if (!(A[i] = (double *)calloc(n, sizeof(**A)))) {
                freeSquareArray(A, n);
                return 0;
            }
        }
    }
    return A;
}
void freeSquareArray(double **A, const int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        free(A[i]);
        A[i] = 0;
    }
    free(A);
}

double ** cofactor(const double **A, const int n, const int row, const int col)
{
    double **co = 0;
    if (co = initSquareArray(n - 1)) {
        int i, j, r, c;
        for (i = 0, r = 0; i < n; ++i) {
            if (i == row) {
                continue;
            }
            for (j = 0, c = 0; j < n; ++j) {
                if (j == col) {
                    continue;
                }
                co[r][c] = A[i][j];
                c++;
            }
            r++;
        }
    }
    return co;
}
double determinant(const double **A, const int n)
{
    int i, j;
    double det = 0;
    if (n < 1) {
        printf("Invalid matrix dimension: %d\n", n);
    } else if (n == 1) {
        det = A[0][0];
    } else if (n == 2) {
        det = A[0][0] * A[1][1] - A[1][0] * A[0][1];
    } else {
        i = 0;
        for (j = 0; j < n; ++j) {
            double **co = 0;
            if (co = cofactor(A, n, i, j)) {
                det += pow(-1, (i + 1) + (j + 1)) * A[i][j] * determinant(co, n - 1);
                freeSquareArray(co, n - 1);
            } else {
                freeSquareArray(co, n - 1);
                return 0;
            }
        }
    }
    return det;
}

double leftSum(const double *X, const int n, const double power)
{
    int i;
    double S = 0;
    for (i = 0; i < n; ++i) {
        S += pow(X[i], power);
    }
    return S;
}
double ** leftMatrix(const double *A, const int n, const int degree)
{
    double **m = 0;
    if (m = initSquareArray(degree + 1)) {
        int i, j;
        for (i = 0; i <= 2 * degree; ++i) {
            double S = leftSum(A, n, i);
            for (j = 0; j <= i; ++j) {
                if (j < degree + 1 && i - j < degree + 1) {
                    m[j][i - j] = S;
                }
            }
        }
    }
    return m;
}
double rightSum(const double *X, const double *Y, const int n, const double power)
{
    int i;
    double S = 0;
    for (i = 0; i < n; ++i) {
        S += pow(X[i], power) * Y[i];
    }
    return S;
}
double * rightVector(const double *X, const double *Y, const int n, const int degree)
{
    double *v = 0;
    if (v = (double *)calloc(degree + 1, sizeof(*v))) {
        int i;
        for (i = 0; i <= degree; ++i) {
            v[i] = rightSum(X, Y, n, i);
        }
    }
    return v;
}
double ** replaceColumn(const int nCol, const double **A, const double *col, const int n)
{
    double **m = 0;
    if (m = initSquareArray(n)) {
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                m[i][j] = (j == nCol ? col[i] : A[i][j]);
            }
        }
    }
    return m;
}

main()
{
    FILE *fPtr = fopen("AA.DAT", "w");
    const double X[9] = {2.3, 2.5, 2.8, 3.1, 3.5, 3.8, 4, 4.3, 4.6};
    const double Y[9] = {39, 39, 42, 43.4, 43, 44, 45, 43, 43.5};
    const int degree = 1;
    double **left = leftMatrix(X, 9, degree);
    double *right = rightVector(X, Y, 9, degree);
    double D = determinant(left, degree + 1);
    int i;
    for (i = 0; i <= degree; ++i) {
        double **leftI = replaceColumn(i, left, right, degree + 1);
        printf("a%d=%f\n", i, determinant(leftI, degree + 1) / D);
        if (fPtr) {
            fprintf(fPtr, "a%d=%f\n", i, determinant(leftI, degree + 1) / D);
        }
        freeSquareArray(leftI, degree + 1);
        leftI = 0;
    }
    double R = (9 * rightSum(X, Y, 9, 1) - leftSum(X, 9, 1) * leftSum(Y, 9, 1)) / sqrt((9 * leftSum(X, 9, 2) - pow(leftSum(X, 9, 1), 2)) * (9 * leftSum(Y, 9, 2) - pow(leftSum(Y, 9, 1), 2)));
    printf("R=%f\n", R);
    if (fPtr) {
        fprintf(fPtr, "R=%f\n", R);
    }
    free(right);
    right = 0;
    freeSquareArray(left, degree + 1);
    left = 0;
    fclose(fPtr);
    return 0;
}
