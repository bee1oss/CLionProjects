// Gauss
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print_matrix(double** matrix, double* matrix_answers, int n)
{
    for (int i = 0; i < n; i++)  //Вывели на экран матрицу
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << matrix_answers[i];
        cout << endl;
    }
}

void metod(double** matrix, double* matrix_answers, int n, int l)
{
    for (int j = 0; j < n; j++)   //прямой метод Гаусса
    {
        double number = 0;
        for (int i = j; i < n; i++)
        {                                        //поиск наибольшего числа в столбике
            if (abs(matrix[i][j]) > abs(number)) //abs-модуль
            {
                number = matrix[i][j];
                l = i;
            }
        }

        swap(matrix[j], matrix[l]); // меняем местами строки первую и с наибольшим числом в столбце
        swap(matrix_answers[j], matrix_answers[l]);//меняем также и столбец с ответами

        if (matrix[j][j] == 0)//если значение ведущего элемента 0, то прекращаем программу
        {
            delete[] matrix_answers;
            for (int i = 0; i < n; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            cout << "error";
        }

        double denominator = matrix[j][j]; //на эту переменную будем делить строку с наибольшим числом

        for (int i = j; i < n; i++) // делим
        {
            matrix[j][i] = matrix[j][i] / denominator;
        }

        matrix_answers[j] = matrix_answers[j] / denominator; //не забываем поделить и ответ

        double* constant = new double[n];

        for (int i = 0; i < n; i++) //создаем динамический массив, куда сохраняем столбец [j] до обнуления нижних строк
        {
            constant[i] = matrix[i][j];
        }

        for (int i = j; i < n; i++) //отнимаем строку с наибольшим числом, поделенную на это число и умноженную на число ниже, с нижними строками
        {

            for (int k = j; k < n; k++)
            {
                if ((k + 1) >= n)
                {
                    break;
                }
                matrix[k + 1][i] = (matrix[j][i] * (-constant[k + 1]) + (matrix[k + 1][i]));
            }

            if ((i + 1) >= n)
            {
                break;
            }
            matrix_answers[i + 1] = (matrix_answers[j] * (-constant[i + 1]) + matrix_answers[i + 1]);
        }

        delete[] constant;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк = столбцов" << endl << "n = ";
    int n;
    cin >> n;

    //1)метод Гаусса
    double** matrix = new double* [n]; //создали двумерный динамический массив
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];

    vector<vector<double>> A(n); //создаем для определения нормы

    for (int i = 0; i < n; i++)  //Заполненили матрицу
    {
        A[i].resize(n); //добавляем в вектор
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            A[i][j] = matrix[i][j];
        }
        cout << endl;
    }

    cout << "Введите колонку ответов" << endl;

    vector <double> b(n);

    double* matrix_answers = new double[n];  //создали одномерный динамичекий массив

    for (int i = 0; i < n; i++) //массив ответов
    {
        cin >> matrix_answers[i];
        b[i] = matrix_answers[i];
    }
    cout << endl;

    int l = 0;

    metod(matrix, matrix_answers, n, l);

    print_matrix(matrix, matrix_answers, n);

    double* answers = new double[n];//создаем матрицу ответов

    for (int i = n - 1; i >= 0; i--)// обратный
    {
        if (i + 1 == n)
        {
            answers[i] = matrix_answers[i] / matrix[i][i];
        }
        else
        {
            double sum = 0;
            for (int j = n - 1; j > i; j--) {
                sum += matrix[i][j] * answers[j];
            }
            answers[i] = (matrix_answers[i] - sum) / matrix[i][i];
        }
    }

    for (int i = 0; i < n; i++) //выводим х
    {
        cout << "x" << i << " = " << answers[i] << endl;
    }

    //2)норма

    vector <double> F(n);
    cout<<"считаем векторы невязки:"<<endl;
    for (int i = 0; i < n; i++)//считаем векторы невязки
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += A[i][j] * answers[j];
        }
        F[i] = sum - b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "F" << i << " = " << F[i] << endl;
    }

    double number = 0;
    cout<<"считаем норму:"<<endl;
    for (int i = 0; i < n; i++) // считаем норму
    {
        if (abs(F[i]) > abs(number)) //abs-модуль
        {
            number = F[i];
        }
    }

    cout << " norm = " << (abs(number)) << endl;//норма

    //3)счет погрешности
    cout<<"считаем погрешности:"<<endl;
    for (int i = 0; i < n; i++) //считаем новую b; с помощью вектора восстанавливаем изначальные значения матрицы
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = A[i][j];//восстанавливаем матрицу
            sum += A[i][j] * answers[j];
        }
        matrix_answers[i] = sum;
    }
    l = 0;

    print_matrix(matrix, matrix_answers, n);

    metod(matrix, matrix_answers, n, l);//снова вызываем метод гаусса для новой матрицы

    for (int i = n - 1; i >= 0; i--)// обратный для новой матрицы
    {
        if (i + 1 == n)
        {
            b[i] = matrix_answers[i] / matrix[i][i];
        }
        else
        {
            double sum = 0;
            for (int j = n - 1; j > i; j--) {
                sum += matrix[i][j] * b[j];
            }
            b[i] = (matrix_answers[i] - sum) / matrix[i][i]; //новые х
        }
    }

    for (int i = 0; i < n; i++) //выводим новые х
    {
        cout << "x" << i << " = " << b[i] << endl;
    }

    number = 0;


    for (int i = 0; i < n; i++)
    {
        if (abs(answers[i]) > abs(number)) //abs-модуль
        {
            number = answers[i];
        }
    }

    double number_1 = 0;

    for (int i = 0; i < n; i++)
    {
        cout<<abs(b[i])<<"-"<<abs(answers[i])<<">"<<abs(number_1)<<endl;
        if (abs(b[i] - answers[i]) > abs(number_1)) //abs-модуль
        {
            cout<<number_1<<"="<<b[i]<<"-"<<answers[i];
            number_1 = b[i] - answers[i];
        }
    }

    double delta = abs(number_1) / abs(number);

    cout <<endl<< "delta = " << delta;

    delete[] answers;
    delete[] matrix_answers;

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}