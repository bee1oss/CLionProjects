#include<iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

#define M2 2
//#define M 2

using namespace std;

void solution(double matrix[][2 * M2], double xx[M2 + 1])
{

    int N = 3;
    for (int i = 0; i < N; i++)
    {
        double tmp = matrix[i][i];
        for (int j = N; j >= i; j--)
            matrix[i][j] /= tmp;
        for (int j = i + 1; j < N; j++)
        {
            tmp = matrix[j][i];
            for (int k = N; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }

    xx[N - 1] = matrix[N - 1][N];
    for (int i = N - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][N];
        for (int j = i + 1; j < N; j++)
            xx[i] -= matrix[i][j] * xx[j];
    }
}
int main()
{
    const int M = 2;
    const int N = 11;
    int xtable[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double ytable[N] = { 3, 87, 156, 210, 238, 252, 239, 211, 158, 90, -5 };
    int A[M + 1][M + 1] = { 0 };
    int m = 2 * M;
    for (int i = 0; i < M + 1; ++i)
    {
        for (int j = 0; j < M + 1; ++j)
        {
            A[i][j] = m;
            --m;
        }
        m += 2;
    }
    //matr x sum
    double SUMX[M + 1][M + 2] = { 0 };
    for (int i = 0; i < M + 1; ++i)
    {
        for (int j = 0; j < M + 1; ++j)
        {
            for (int k = 0; k < N; ++k)
                SUMX[i][j] += pow(xtable[k], A[i][j]);
        }
    }
    //vect y
    int p = M;
    double vect[M + 1] = { 0 };
    for (int i = 0; i < M + 1; ++i)
    {
        for (int k = 0; k < N; ++k)
            vect[i] += pow(xtable[k], p) * ytable[k];
        --p;
    }
    for (int i = 0; i < M + 1; ++i)
    {
        SUMX[i][M + 1] = vect[i];
    }

    for (int i = 0; i < M + 1; ++i)
    {
        for (int j = 0; j < M + 2; ++j)
            cout << setw(8) << SUMX[i][j] << ' ';
        cout << endl;
    }
    for (int i = 0; i < M + 1; ++i)
        cout << vect[i] << ' ';
    cout <<endl;

    // a0 a1 ...
    double xx[M + 1] = { 0 };

    solution(SUMX, xx);
    //show2
    cout << endl << "polinom:" << endl;
    for (int i = 0; i < M + 1; ++i)
        cout << xx[M - i] << "*x^" << i << "   ";
    cout << endl << endl;

    cout << 'x' << endl;
    for (int i = 0; i < N; ++i)
        cout << setw(8) << xtable[i] << ' ';
    cout << endl;
    cout << 'y' << endl;
    for (int i = 0; i < N; ++i)
        cout << setw(8) << ytable[i] << ' ';
    cout << endl;

    cout << "2nd y" << endl;
    double ytable2[N] = { 0 };
    p = 0;
    for (int i = 0; i < N; ++i)
    {
        ytable2[i] = xx[2] + xx[1] * xtable[i] + xx[0] * xtable[i] * xtable[i];
        cout << setw(8) << ytable2[i] << ' ';
    }
    cout << endl << endl;

    return 0;
}

