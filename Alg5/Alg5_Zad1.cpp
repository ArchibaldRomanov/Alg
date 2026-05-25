#include <iostream>

using namespace std;

void print_pyramid(int* arr, int size) {
    cout << "Пирамида:" << endl;

    for (int i = 0; i < size; i++) {

        int level = 0;
        int index = i;

        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }

        if (i == 0) {
            cout << level << " root " << arr[i] << endl;
        }
        else {
            int parent_index = (i - 1) / 2;

            if (i % 2 == 1) {
                cout << level << " left("
                    << arr[parent_index] << ") "
                    << arr[i] << endl;
            }
            else {
                cout << level << " right("
                    << arr[parent_index] << ") "
                    << arr[i] << endl;
            }
        }
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size = sizeof(arr) / sizeof(arr1[0]);

    cout << "Исходный массив: ";
    print_array(arr, size);

    print_pyramid(arr, size);

    cout << endl;



    return 0;
}