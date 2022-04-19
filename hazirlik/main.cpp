/*#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double* Gauss(double** Array_A, double* Array_B, int n)
{
	double* X = new double[n];  
	for (int k = 0; k < n; k++) 
	{
		for (int i = k + 1; i < n; i++)
		{
			if (abs(Array_A[i][k]) > abs(Array_A[k][k]))
			{
				swap(Array_A[i], Array_A[k]);  
				swap(Array_B[i], Array_B[k]);   
			}
		}
		double A_Main = Array_A[k][k];
		if (A_Main == 0)
		{
			cout << "error\n";
			system("pause");
			exit(0);
		}
		for (int i = k; i < n; i++)
		{
			Array_A[k][i] /= A_Main;
		}
		Array_B[k] /= A_Main;
		for (int i = k + 1; i < n; i++)
		{
			double s = Array_A[i][k];
			for (int j = k; j < n; j++)
			{
				Array_A[i][j] -= s * Array_A[k][j];
			}
			Array_B[i] -= s * Array_B[k];
		}
	}
	for (int k = n - 1; k >= 0; k--)  
	{
		X[k] = Array_B[k];
		for (int i = n - 1; i > k; i--)
		{
			X[k] -= Array_A[k][i] * X[i];
		}
	}
	return X;
}

int main()
{
	setlocale(LC_ALL, "rus");*/
//15 вариант
/*const double N = 16;
const double m = 3;
double x[16] = { 37.8, 40.6, 43.3, 46.1, 49.4, 55.6, 62.2, 67.2, 72.8, 81.7, 88.3, 95.0, 100.0, 107.8, 113.9, 121.7 };
double y[16] = { 3.71, 3.81, 3.86, 3.93, 3.96, 4.20, 4.34, 4.51, 4.73, 5.35, 6.14, 6.51, 6.98, 7.44, 7.76 };
double* POWERX = new double[2 * m];
for (int k = 0; k < 2 * m; k++)
{
    POWERX[k] = 0;
    for (int i = 0; i < N; i++)
    {
        POWERX[k] += pow(x[i], k + 1);
    }
}

double** SUMX = new double* [m + 1];
for (int i = 0; i < m + 1; i++)
{
    SUMX[i] = new double[m + 1];
}
for (int l = 0; l < m + 1; l++)
{
    for (int j = 0; j < m + 1; j++)
    {
        if (j + l)
        {
            SUMX[l][j] = POWERX[l + j - 1];
        }
        else
        {
            SUMX[l][j] = N;
        }
    }
}
double* PRAW = new double[m + 1];
for (int l = 0; l < m + 1; l++)
{
    PRAW[l] = 0;
    for (int i = 0; i < N; i++)
    {
        PRAW[l] += y[i] * pow(x[i], l);
    }
}
double* a = Gauss(SUMX, PRAW, m + 1);
double S2 = 0;
for (int i = 0; i < N; i++)
{
    double sum = y[i];
    for (int j = 0; j < m + 1; j++)
    {
        sum -= a[j] * pow(x[i], j);
    }
    S2 += pow(sum, 2);
}
S2 /= N - m - 1;
double sigma = sqrt(S2);
cout << "Коэфициенты a: " << endl;
for (int i = 0; i < m + 1; i++)
{
    cout << a[i] << " ";
}
cout << "\nCреднеквадратическое отклонение: " << sigma << endl;
//3 вариант
/*const double N = 11;
const double m = 2;
double x[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double y[11] = { 3, 87, 156, 210, 238, 252, 239, 211, 158, 90, -5};
double* POWERX = new double[2 * m];
for (int k = 0; k < 2 * m; k++)
{
    POWERX[k] = 0;
    for (int i = 0; i < N; i++)
    {
        POWERX[k] += pow(x[i], k + 1);
    }
}

double** SUMX = new double* [m + 1];
for (int i = 0; i < m + 1; i++)
{
    SUMX[i] = new double[m + 1];
}
for (int l = 0; l < m + 1; l++)
{
    for (int j = 0; j < m + 1; j++)
    {
        if (j + l)
        {
            SUMX[l][j] = POWERX[l + j - 1];
        }
        else
        {
            SUMX[l][j] = N;
        }
    }
}
double* PRAW = new double[m + 1];
for (int l = 0; l < m + 1; l++)
{
    PRAW[l] = 0;
    for (int i = 0; i < N; i++)
    {
        PRAW[l] += y[i] * pow(x[i], l);
    }
}
double* a = Gauss(SUMX, PRAW, m + 1);
double S2 = 0;
for (int i = 0; i < N; i++)
{
    double sum = y[i];
    for (int j = 0; j < m + 1; j++)
    {
        sum -= a[j] * pow(x[i], j);
    }
    S2 += pow(sum, 2);
}
S2 /= N - m - 1;
double sigma = sqrt(S2);
cout << "Коэфициенты a: " << endl;
for (int i = 0; i < m + 1; i++)
{
    cout << a[i] << " ";
}
cout << "\nCреднеквадратическое отклонение: " << sigma << endl;*/
/*system("pause");
return 0;*/
//}

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "iomanip"

#define M2 2
//#define M 2

using namespace std;

void solution(double matrix[][2 * M2], double xx[M2 + 1]) {

    int N = 3;
    for (int i = 0; i < N; i++) {
        double tmp = matrix[i][i];
        for (int j = N; j >= i; j--)
            matrix[i][j] /= tmp;
        for (int j = i + 1; j < N; j++) {
            tmp = matrix[j][i];
            for (int k = N; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }

    xx[N - 1] = matrix[N - 1][N];
    for (int i = N - 2; i >= 0; i--) {
        xx[i] = matrix[i][N];
        for (int j = i + 1; j < N; j++)
            xx[i] -= matrix[i][j] * xx[j];
    }
}

int main() {
    //bariant 3
    const int M = 2;
    const int N = 11;
    int xtable[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double ytable[N] = {3, 87, 156, 210, 238, 252, 239, 211, 158, 90, -5};
    int A[M + 1][M + 1] = {0};
    int m = 2 * M;
    for (int i = 0; i < M + 1; ++i) {
        for (int j = 0; j < M + 1; ++j) {
            A[i][j] = m;
            --m;
        }
        m += 2;
    }
    //matr x sum
    double SUMX[M + 1][M + 2] = {0};
    for (int i = 0; i < M + 1; ++i) {
        for (int j = 0; j < M + 1; ++j) {
            for (int k = 0; k < N; ++k)
                SUMX[i][j] += pow(xtable[k], A[i][j]);
        }
    }
    //vect y
    int p = M;
    double vect[M + 1] = {0};
    for (int i = 0; i < M + 1; ++i) {
        for (int k = 0; k < N; ++k)
            vect[i] += pow(xtable[k], p) * ytable[k];
        --p;
    }
    for (int i = 0; i < M + 1; ++i) {
        SUMX[i][M + 1] = vect[i];
    }

    for (int i = 0; i < M + 1; ++i) {
        for (int j = 0; j < M + 2; ++j)
            cout << setw(8) << SUMX[i][j] << ' ';
        cout << endl;
    }
    for (int i = 0; i < M + 1; ++i)
        cout << vect[i] << ' ';
    cout << endl;

    // a0 a1 ...
    double xx[M + 1] = {0};

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
    double ytable2[N] = {0};
    p = 0;
    for (int i = 0; i < N; ++i) {
        ytable2[i] = xx[2] + xx[1] * xtable[i] + xx[0] * xtable[i] * xtable[i];
        cout << setw(8) << ytable2[i] << ' ';
    }
    cout << endl << endl;
    return 0;
}

