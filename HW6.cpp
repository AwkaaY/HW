#include <iostream>
using namespace std;

void qSort(int* A, int nStart, int nEnd)
{
    int L, R, c, X;
    if (nStart >= nEnd) return; 
    L = nStart; R = nEnd;
    X = A[(L + R) / 2];
    while (L <= R) { 
        while (A[L] < X) L++;
        while (A[R] > X) R--;
        if (L <= R) {
            c = A[L]; A[L] = A[R]; A[R] = c;

            L++; R--;
        } 

            qSort(A, nStart, R); 

    }

    qSort(A, L, nEnd); 
}
void task1()
{
    const int size = 15;
    int mass[size] = { 40, 12, 21, 74, 132, 20, 5, -7, -23,-13, 17,222, 4, 0, -34 };

    cout << "Первоначальный массив: ";
    int counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
        if (mass[i] < 20 && mass[i] > -20)
        {
            counter++;
        }
    }
    cout << endl;

    int* mass20 = new int[counter];
    int* other = new int[size - counter];
    int x20 = 0;
    int oth = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (mass[i] < 20 && mass[i] > -20)
        {
            mass20[x20] = mass[i];
            x20++;
        }
        else
        {
            other[oth] = mass[i];
            oth++;
        }
    }

    qSort(mass20, 0, counter - 1);
    qSort(other, 0, size - counter - 1);
    int temp = other[0];
    other[0] = mass20[counter - 1];
    mass20[counter - 1] = temp;

    cout << "Первый массив: ";
    for (size_t i = 0; i < counter; i++)
    {
        cout << mass20[i] << " ";
    }
    cout << endl;
    cout << "Второй массив: ";
    for (size_t i = 0; i < size - counter; i++)
    {
        cout << other[i] << " ";
    }
    cout << endl;
}
void task2()
{
    int mass[14];
    int counter = 0;
    int maxAbs = 0;


    cout << "Изначальный массив: ";
    for (size_t i = 0; i < 14; i++)
    {
        mass[i] = -20 + rand() % 40;
        cout << mass[i] << " ";
        if (mass[i] > -5 && mass[i] <= 10)
        {
            counter++;
        }
        if (abs(mass[i]) > abs(maxAbs))
        {
            maxAbs = mass[i];
        }
    }

    cout << "\nМаксимальное по модулю число: " << maxAbs << endl;

    int* arr = new int[counter];
    int xArr = 0;
    for (size_t i = 0; i < 14; i++)
    {
        if (mass[i] > -5 && mass[i] <= 10) 
        {
            arr[xArr] = mass[i];
            xArr++;
        }
    }
    
    cout << "Второй массив: ";
    for (size_t i = 0; i < counter; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
int main()
{ 
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    bool start = true;
    int choice;
    while (start)
    {
        cout << "Какое задание вас интересует?\n1 - Первое\n2 - Второе\n3 - Выход\nВаш выбор: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            task2();
            break;
        case 2:
            task1(); 
            break;
        case 3:
            start = false;
            break;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}


