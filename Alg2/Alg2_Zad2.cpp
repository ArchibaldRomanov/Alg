#include <iostream>

using namespace std;

int fibon(int n, int* memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = fibon(n - 1, memo) + fibon(n - 2, memo);

    return memo[n];
}

int main()
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;

    int* memo = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    memo[0] = 0;

    if (n > 0)
    {
        memo[1] = 1;
    }

    cout << "Число Фибоначчи: "<< fibon(n, memo) << endl;
    delete[] memo;

    return 0;
}