#include <iostream>
#include <string>

using namespace std;

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_element(int* arr, int index) {
    int level = 0;
    int temp = index;

    while (temp > 0) {
        temp = (temp - 1) / 2;
        level++;
    }

    if (index == 0) {
        cout << level << " root " << arr[index];
    }
    else {
        int parent = (index - 1) / 2;

        if (index % 2 == 1) {
            cout << level << " left(" << arr[parent]
                << ") " << arr[index];
        }
        else {
            cout << level << " right(" << arr[parent]
                << ") " << arr[index];
        }
    }
}

void print_pyramid(int* arr, int size) {
    cout << "Пирамида:" << endl;

    for (int i = 0; i < size; i++) {
        print_element(arr, i);
        cout << endl;
    }
}


bool get_parent(int index, int& parent_index) {
    if (index == 0) {
        return false;
    }

    parent_index = (index - 1) / 2;
    return true;
}


bool get_left_child(int index, int size, int& child_index) {
    child_index = 2 * index + 1;

    if (child_index >= size) {
        return false;
    }

    return true;
}


bool get_right_child(int index, int size, int& child_index) {
    child_index = 2 * index + 2;

    if (child_index >= size) {
        return false;
    }

    return true;
}

int main() {
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    print_array(arr, size);

    print_pyramid(arr, size);

    int current_index = 0;
    string command;

    do {
        cout << "Вы находитесь здесь: ";
        print_element(arr, current_index);
        cout << endl;

        cout << "Введите команду: ";
        cin >> command;

        int new_index;

        if (command == "up") {

            if (get_parent(current_index, new_index)) {
                current_index = new_index;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }

        }
        else if (command == "left") {

            if (get_left_child(current_index, size, new_index)) {
                current_index = new_index;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }

        }
        else if (command == "right") {

            if (get_right_child(current_index, size, new_index)) {
                current_index = new_index;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }

        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Ошибка! Неизвестная команда" << endl;
        }

    } while (command != "exit");

    return 0;
}