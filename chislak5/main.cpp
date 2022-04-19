#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const double e = 1e-3;
double F1Var1(double x)
{
    return pow((1 + x * x * x), 0.5);
}
double a1 = 0.8;
double b1 = 1.762;
double F2Var4(double x)
{
    return (1 + x * x) / (1 + x * x * x);
}
double a2 = 3.0;
double b2 = 4.254;
double F3Var31(double x, double y)
{
    return x*x + 2*y;
}
double a3 = 0;
double b3 = 2;
double c3 = 0;
double d3 = 1;
int main()
{
    cout << setprecision(15);
    cout << "Trap method (Var 1):\n";
    double h1 = (b1 - a1) / 100;
    double I1_h = 0;
    double I1_h2 = 0;
    int counter = 1;
    while (true)
    {
        double tempSum = 0;
        for (double tempX = a1 + h1; tempX < b1; tempX += h1)
        {
            tempSum += F1Var1(tempX);
        }
        I1_h =((F1Var1(a1) + 2 * tempSum + F1Var1(b1)) * h1 / 2);
        if (abs(I1_h - I1_h2) > 3 * e)
        {
            I1_h2 = I1_h;
            h1 /= 2;
            cout << "Step" << counter++ << " = " << h1 << endl;
            continue;
        }
        else
            break;
    }
    cout << "I = " << I1_h << endl << endl;
    cout << "Simpson method:\n";
    double h2 = (b2 - a2) / 100;
    double I2_h = 0;
    double I2_h2 = 0;
    counter = 1;
    while (true)
    {
        double tempSumNechet = 0;
        for (double tempX = a2 + h2; tempX < b2; tempX += 2 * h2)
        {
            tempSumNechet += F2Var4(tempX);
        }
        double tempSumChet = 0;
        for (double tempX = a2 + 2 * h2; tempX < (b2 - h2); tempX += 2 * h2)
        {
            tempSumChet += F2Var4(tempX);
        }

        I2_h = ((F2Var4(a2) + 4 * tempSumNechet + 2 * tempSumChet + F1Var1(b2)) * h2 / 3);
        if (abs(I2_h - I2_h2) > 15 * e)
        {
            I2_h2 = I2_h;
            h2 /= 2;
            cout << "Step" << counter++ << " = " << h2 << endl;
            continue;
        }
        else
            break;
    }
    cout << "I = " << I2_h << endl << endl;

    cout << "Simpsony: " << endl;
    counter = 0;
    int N = 10;
    int M = 10;
    double I3_h = 0;
    double I3_h2 = 0;
    while (true)
    {
        double hx = (b3 - a3) / (2 * N);
        double hy = (d3 - c3) / (2 * M);
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                I3_h += F3Var31((2 * i)*hx, (2 * j)*hy);
                I3_h += 4 * F3Var31((2 * i + 1)*hx, (2 * j)*hy);
                I3_h += F3Var31((2 * i + 2)*hx, (2 * j)*hy);
                I3_h += 4 * F3Var31((2 * i)*hx, (2 * j + 1)*hy);
                I3_h += 16 * F3Var31((2 * i + 1)*hx, (2 * j + 1)*hy);
                I3_h += 4 * F3Var31((2 * i + 2)*hx, (2 * j + 1)*hy);
                I3_h += F3Var31((2 * i)*hx, (2 * j + 2)*hy);
                I3_h += 4 * F3Var31((2 * i + 1)*hx, (2 * j + 2)*hy);
                I3_h += F3Var31((2 * i + 2)*hx, (2 * j + 2)*hy);
            }
        }
        I3_h *= (hx * hy / 9);

        if (true)
        {
            int a = 1;
        }
        if (abs(I3_h - I3_h2) > 15*e)
        {
            I3_h2 = I3_h;
            I3_h = 0;
            N *= 2;
            M *= 2;
            cout << "Step:" << counter++ << " hx = " << hx << " hy = " << hy << endl;
            continue;
        }
        else
            break;
    }
    cout << "I = " << I3_h << endl << endl;
}



