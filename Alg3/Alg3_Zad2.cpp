#include <iostream>

using namespace std;

int partition(int* arr, int left, int right) {
    int pivot = arr[right]; 
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

void quickSortRecursive(int* arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSortRecursive(arr, left, pivotIndex - 1);
        quickSortRecursive(arr, pivotIndex + 1, right);
    }
}

void quick_sort(int* arr, int size) {
    quickSortRecursive(arr, 0, size - 1);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59,
                 0, 7, 59, 90, 84, 60, 95, 62 };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, size);

    quick_sort(arr, size);

    cout << "Отсортированный массив: ";
    printArray(arr, size);

    return 0;
}