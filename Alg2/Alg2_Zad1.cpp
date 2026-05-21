#include <iostream>

using namespace std;

int fibon(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibon(n - 1) + fibon(n - 2);
}

int main()
{
    int n;

    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;

    cout << "Число Фибоначчи: " << fibon(n) << endl;

    return 0;
}