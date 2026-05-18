#include <iostream>

using namespace std;

int countGreater(const int arr[], int size, int point)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] <= point)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }

    return size - left;
}

int main()
{
    const int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    const int size = sizeof(arr) / sizeof(arr[0]);

    int point;

    cout << "Введите точку отсчёта: ";
    cin >> point;

    int result = countGreater(arr, size, point);

    cout << "Количество элементов в массиве больших, чем "
        << point << ": " << result << endl;

    return 0;
}