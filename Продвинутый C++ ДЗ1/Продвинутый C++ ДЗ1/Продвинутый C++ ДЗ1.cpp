// Продвинутый C++ ДЗ1.cpp : 

/*
# Задача 1.  программа должна считать два одномерных целочисленных массива из входного файла `in.txt` и записать их в выходной файл `out.txt` с небольшими изменениями.

Во входящем файле `in.txt` на первой строке находится целое неотрицательное число `N` — количество элементов в первом массиве. После этого идут элементы массива, разделённые пробелом, в количестве `N`. Затем идёт целое неотрицательное число `M` — количество элементов во втором массиве. После него находятся элементы второго массива, их количество равняется `M`.

В выходной файл оба массива должны быть записаны в другом порядке — сначала массив `M`, потом массив `N`. При этом элементы в массиве `M`, изначально второй по счёту массив, должны быть сдвинуты на один элемент **вправо** с переносом последнего элемента на место первого, а элементы в массиве `N`, изначально первый по счёту массив, должны быть сдвинуты на один элемент **влево** с переносом первого элемента на место последнего.

Перед каждым массивом в выходном файле должен быть записан его размер.

### Пример работы программы
#### Входной файл `in.txt`
```
5
1 2 3 4 5
6
10 20 30 40 50 60
```
#### Выходной файл `out.txt`
```
6
60 10 20 30 40 50
5
2 3 4 5 1
```
*/




#include <iostream>
#include <fstream>
#include <string>




int* create_dim(int line) // создание динамического массива
{
    int* arr = new int [line];
    
    return arr;
}
void save_file(int* arr1, int size1, int* arr2, int size2) // сохранения результата
{
    int livers = 0;
    std::ofstream fout("out.txt");
    fout << size2 << std::endl;
    for (int i = 0; i < size2; ++i)
    {
        fout << arr2[i] << ' ';
    }
    fout << std::endl;
    fout << size1 << std::endl;
    for (int i = 0; i < size1; ++i)
    {
        fout << arr1[i] << ' ';
    }
    fout << std::endl;

    fout.close();
}
    
void step_arr_left(int* arr, int size) // сдвиг массива на 1 шаг в лево последовательный, при необходимости юольшего сдвига можно моместить в цикл.
{
    int a = arr[0];
    for (int i = 1; i < size; ++i)
    {
        arr[i - 1] = arr[i];
    }
    arr[size - 1] = a;
}
void step_arr_right(int* arr, int size)
{
    int a = arr[size-1];

    for (int i = size-1; i > 0; --i)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = a;
}





int main()
{
    int arr1, arr2;
    std::ifstream file("in.txt");
    if (file.is_open())
    {
        std::string size_ar1;
        file >> size_ar1;
        arr1 = std::stoi(size_ar1);// можно добавить проверку на не отрицательный и не нулевой размер массива "ошибка при вводе данных в фаил"
        int* mass1 = create_dim(arr1); 
        for (int i = 0; i < arr1; ++i)
        {
            file >> size_ar1;
            mass1[i] = std::stoi(size_ar1);
        }
        std::string size_ar2;
        file >> size_ar2;
        arr2 = std::stoi(size_ar2); // можно добавить проверку на не отрицательный и не нулевой размер массива "ошибка при вводе данных в фаил"
        int* mass2 = create_dim(arr2);
        for (int i = 0; i < arr2; ++i)
        {
            file >> size_ar2;
            mass2[i] = std::stoi(size_ar2);
        }
        file.close();
        step_arr_left(mass1, arr1);
        step_arr_right(mass2, arr2);
        save_file(mass1, arr1, mass2, arr2);
        delete[] mass1;
        delete[] mass2;
    }
    else
    {
        std::cout << "Ошибка! Фаил начальных условий не найден! Код ошибки: -1" << std::endl;
        return 0;
    }

    




}

