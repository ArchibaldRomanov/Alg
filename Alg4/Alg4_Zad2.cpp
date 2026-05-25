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

int* append_to_dynamic_array(int* arr,
    int& logical_size,
    int& actual_size,
    int value) {
    if (logical_size < actual_size) {
        arr[logical_size] = value;
        logical_size++;
        return arr;
    }

    int new_actual_size = actual_size * 2;
    int* new_arr = new int[new_actual_size];

    for (int i = 0; i < logical_size; i++) {
        new_arr[i] = arr[i];
    }

    new_arr[logical_size] = value;
    logical_size++;

    actual_size = new_actual_size;

    delete[] arr;

    return new_arr;
}

int main() {
    int actual_size;
    int logical_size;

    cout << "Введите фактический размер массива: ";
    cin >> actual_size;

    cout << "Введите логический размер массива: ";
    cin >> logical_size;

    if (logical_size > actual_size) {
        cout << "Ошибка! Логический размер массива не может превышать фактический!";
        return 0;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++) {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    int value;

    while (true) {
        cout << "Введите элемент для добавления: ";
        cin >> value;

        if (value == 0) {
            break;
        }

        arr = append_to_dynamic_array(arr,
            logical_size,
            actual_size,
            value);

        cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
    }

    cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;

    return 0;
}