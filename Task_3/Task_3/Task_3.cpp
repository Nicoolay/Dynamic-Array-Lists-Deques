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
    std::cout << std::endl;
}


void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    int choice{};
    while (choice!=2) {
        std::cout << "Удалить первый элемент?" << "\n 1. Да \n 2. Нет" << std::endl;
        
        std::cin >> choice;
        int third_of_actual_size = actual_size / 3;
      if(choice!=2&&choice!=1){
            std::cout << "Неверный ввод. Нужно выбрать Да(1) или Нет(2)" << std::endl;        
            continue;
            }
    
      if (choice == 1) {
          if (actual_size == 1) {
              std::cout << "Массив пуст!" << std::endl;
              break;
          }

      if ((logical_size-1) > third_of_actual_size) {
                for (int i = 0; i < (logical_size-1); i++) {
                    arr[i] = arr[i + 1];                   
                }
                logical_size--;
                print_dynamic_array(arr, logical_size, actual_size);
                continue;
            }

            if ((logical_size - 1) <= third_of_actual_size&& third_of_actual_size > 0 ) {
                
                int* arrx2 = new int[third_of_actual_size];
                for (int i = 0; i < logical_size-1 ; i++) {
                    arrx2[i] = arr[i+1];
                }
                logical_size--;
                delete[] arr;
                arr = arrx2;
                actual_size = third_of_actual_size;                          
                print_dynamic_array(arr, logical_size, actual_size);            
                
                continue;
            }                 
               
            }            
        
       if(choice==2){
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;

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
    remove_dynamic_array_head(dynamic_array, logical_size, actual_size);

    delete[] dynamic_array;
}
