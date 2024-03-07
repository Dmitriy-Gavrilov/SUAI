#include <iostream>
#include "TestClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    
    cout << "Объект типа int:" << endl;
    TestClass<int> array;
    
    array.print();
    cout << "Сумма чисел в массиве: " << array.summ() << endl;

    array(2, 5);
    cout << "Массив после применения формулы к элементам: ";
    array.print();

    array.change_array();
    cout << "Массив после замены элементов: ";
    array.print();

    cout << endl << "Объект типа double:" << endl;

    TestClass<double> array1;

    array1.print();
    cout << "Сумма чисел в массиве: " << array1.summ() << endl;

    array1(2, 5);
    cout << "Массив после применения формулы к элементам: ";
    array1.print();

    array1.change_array();
    cout << "Массив после замены элементов: ";
    array1.print();

    return 0;
}

