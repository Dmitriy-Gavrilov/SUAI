#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    Time t1(21, 30);
    Time t2(2,45);
    cout << "Исходные моменты времени t1 и t2:" << endl;
    t1.print();
    t2.print();

    Time t3 = t1 - t2;
    cout << "Разность t1 и t2:" << endl;
    t3.print();

    Time t4 = t1 + 40;
    cout << "Результат сложения t1 и заданного количества минут: " << endl;
    t4.print();

    cout << "Совпадение моментов времени t1 и t2: " << (t1 == t2) << endl;
    cout << "Несовпадение моментов времени t1 и t2: " << (t1 != t2) << endl;


    return 0;
}