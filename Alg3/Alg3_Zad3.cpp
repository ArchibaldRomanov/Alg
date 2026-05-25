#include <iostream>

using namespace std;

void count_sort(int* arr, int size) {
    const int MIN = 10;
    const int MAX = 24;

    int count[MAX - MIN + 1] = { 0 };

    for (int i = 0; i < size; i++) {
        count[arr[i] - MIN]++;
    }

    int index = 0;

    for (int i = 0; i <= MAX - MIN; i++) {
        while (count[i] > 0) {
            arr[index] = i + MIN;
            index++;
            count[i]--;
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {
        19, 14, 22, 22, 17, 22, 13, 21, 20, 24,
        18, 10, 17, 16, 17, 20, 22, 11, 20, 16,
        14, 13, 10, 22, 18, 14, 16, 24, 19, 17
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, size);

    count_sort(arr, size);

    cout << "Отсортированный массив: ";
    printArray(arr, size);

    return 0;
}