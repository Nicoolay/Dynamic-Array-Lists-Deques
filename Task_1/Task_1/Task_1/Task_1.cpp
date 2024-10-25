#include <iostream>
#include <string>
#include <windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: "<<"\n";
    for (int i = 0; i < logical_size; i++) {
         std::cout << arr[i] <<" ";
              
    }
    for (int i = (logical_size); i < actual_size; i++) {
        std::cout << "_" << " ";
        
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

    delete[] dynamic_array;
}
