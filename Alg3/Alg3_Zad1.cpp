#include <iostream>

using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* L = new int[size1];
    int* R = new int[size2];

    for (int i = 0; i < size1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < size2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortRecursive(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge_sort(int* arr, int size) {
    mergeSortRecursive(arr, 0, size - 1);
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

    merge_sort(arr, size);

    cout << "Отсортированный массив: ";
    printArray(arr, size);

    return 0;
}