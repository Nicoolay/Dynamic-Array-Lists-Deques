#include <iostream>
#include <string>
#include <windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: " << "\n";
    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";

    }
    for (int i = (logical_size); i < actual_size; i++) {
        std::cout << "_" << " ";
    }
   std::cout<< std::endl;
}



void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size) {
    int element_new=-1;

    while (element_new != 0) {
        if (element_new == 0) {
            std::cout << "Спасибо!";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        std::cout << "Введите элемент для добавления: ";
        std::cin >> element_new;

        if (logical_size == actual_size) {
            int new_size = actual_size * 2;
            int* arrx2 = new int[new_size];

            for (int i = 0; i < logical_size; i++) {
                arrx2[i] = arr[i];
            }
            delete[] arr;
            arr = arrx2;
            actual_size = new_size;
        }
        if (logical_size < actual_size) {
            arr[logical_size] = element_new;
            logical_size++;
            print_dynamic_array(arr, logical_size, actual_size);
        }

    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int logical_size{};
    int actual_size{};
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    while (true) {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;

        if (logical_size > actual_size) {
            std::cerr << "Ошибка: Логический размер не может быть больше фактического!" << std::endl;
        }
        else {
            break;
        }
    }
    int* dynamic_array = new int[actual_size];
    for (int i = 0; i < logical_size; i++) {
        std::cout << "Введите arr[" << i << "]:";
        std::cin >> dynamic_array[i];
    }
    print_dynamic_array(dynamic_array, logical_size, actual_size);
    append_to_dynamic_array (dynamic_array, logical_size, actual_size);

    delete[] dynamic_array;
}
