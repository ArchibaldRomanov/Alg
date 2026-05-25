#include <iostream>

using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) {
            cout << arr[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    int actual_size;
    int logical_size;

    cout << "¬ведите фактический размер массива: ";
    cin >> actual_size;

    cout << "¬ведите логический размер массива: ";
    cin >> logical_size;

    if (logical_size > actual_size) {
        cout << "ќшибка! Ћогический размер массива не может превышать фактический!";
        return 0;
    }


    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++) {
        cout << "¬ведите arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "ƒинамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);


    delete[] arr;

    return 0;
}