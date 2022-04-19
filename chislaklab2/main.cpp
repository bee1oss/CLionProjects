#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const double eps = 1e-9;
const int NIT = 100;

double fun1(double x1, double x2, double x3) //burasi ilk fonksiyounun oldugu yer
{
    return x1+x1*x1-2*x2*x3-0.1;
}

double fun2(double x1, double x2, double x3)//ikinci fonksiyonun oldugu yer
{
    return x2-x2*x2+3*x1*x3+0.2;

}

double fun3(double x1, double x2, double x3)//ucuncu fonksiyonun oldugu yer
{
    return x3+x3*x3+2*x1*x2-0.3;
}

void vectF(double* F, double* x, int n)
/* F(x)=0 */
{
    F[0] = fun1(x[0], x[1], x[2]);
    F[1] = fun2(x[0], x[1], x[2]);
    F[2] = fun3(x[0], x[1], x[2]);
}



void Jacobi(double** J, double* x)
/* dfi/dfj */
{
    J[0][0] = 1 + 2*x[0];
    J[0][1] = -2*x[2];
    J[0][2] = -2*x[1];

    J[1][0] = 3*x[2];
    J[1][1] = 1 - 2*x[1];
    J[1][2] = 3 * x[1];

    J[2][0] = 2 * x[1];
    J[2][1] = 2 * x[0];
    J[2][2] = 1 + 2*x[2];
}

void Gauss(double** a, double* b, double* x, int n) /* burada method gauss hesaplaniyor*/
{
    for (int k = 0; k < n; k++)
    {
        if (a[k][k] == 0)
        {
            int k1 = k + 1;
            while (k1 < n && a[k1][k1] == 0)
            {
                k1++;
            }

            if (k1 == n)
            {
                cout << "result not found" << endl;
                exit(0);
            }
            else
            {
                swap(a[k], a[k1]);
                swap(b[k], b[k1]);
            }
        }

        b[k] /= a[k][k];//burada yakbyn hesaplaniyor ve bu ilk adimi
        for (int i = n - 1; i >= k; i--)
        {
            a[k][i] /= a[k][k];
        }

        for (int i = k + 1; i < n; i++)
        {
            b[i] -= b[k] * a[i][k];
            for (int j = n - 1; j >= k; j--)
            {
                a[i][j] -= a[k][j] * a[i][k];
            }
        }
    }

    for (int k = n - 1; k >= 0; k--)
    {
        double d = 0;
        double s = 0;
        for (int j = k + 1; j < n; j++)
        {
            s = a[k][j] * x[j];
            d = d + s;
        }
        x[k] = (b[k] - d) / a[k][k];
    }
}

int main()
{

    double M;
    int n = 3;
    cout << "Metod Diff: " << endl;
    for (int c = 0; c < 3; c++)
    {
        if (c == 0)
        {
            M = 0.01;
        }
        else if (c == 1)
        {
            M = 0.05;
        }
        else
        {
            M = 0.1;
        }
        cout << M << endl;
        cout << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "delta1" << setw(15) << "delta2" << setw(5) << "k" << endl;

        double* x = new double[n];
        x[0] = 0; x[1] = 0; x[2] = 0; /* baslangic yakinsama nerde x(0)=? */
        int k1;
        for (k1 = 1; k1 < NIT; k1++)
        {

            double* F = new double[n];
            vectF(F, x, n);

            double** J = new double* [n];
            for (int i = 0; i < n; i++)
            {
                J[i] = new double[n];
            }
            Jacobi(J, x);

            double* delta_x = new double[n];

            double* minusF = new double[n];
            for (int i = 0; i < n; i++)/* burada 0-Fvector'u cikariyoruz*/
            {
                minusF[i] = -F[i];
            }
            Gauss(J, minusF, delta_x, n);/* resheniya metoda gaussa*/
            for (int i = 0; i < n; i++)/* utochnit resheniniye*/
            {
                x[i] += delta_x[i];
            }
            double delta1;
            double temp1 = abs(fun1(x[0], x[1], x[2]));
            double temp2 = abs(fun2(x[0], x[1], x[2]));
            double temp3 = abs(fun3(x[0], x[1], x[2]));

            delta1 = temp1;
            if (delta1 < temp2) /* b1 */
            {
                delta1 = temp2;
            }
            if (delta1 < temp3)
            {
                delta1 = temp3;
            }

            double delta2 = 0;
            for (int i = 0; i < n; i++)/* b2 */
            {
                if (x[i] + delta_x[i] < 1)
                {
                    if (abs(x[i] + delta_x[i] - x[i]) > delta2)
                    {
                        delta2 = abs(x[i] + delta_x[i] - x[i]);
                    }
                }
                else
                {
                    if (abs((x[i] + delta_x[i] - x[i]) / (x[i] + delta_x[i])) > delta2)
                    {
                        delta2 = abs((x[i] + delta_x[i] - x[i]) / (x[i] + delta_x[i]));
                    }
                }
            }

            cout << setw(15) << x[0] << setw(15) << x[1] << setw(15) << x[2] << setw(15) << delta1 << setw(15) << delta2 << setw(5) << k1 << endl;



            if (delta1 <= eps && delta2 <= eps)/* b1 <= e u b2 <= e */
            {
                break;
            }
        }
        if (k1 >= NIT)
        {
            cout << "IER 2" << endl;
        }
        cout << endl << endl;
    }

    return 0;
}