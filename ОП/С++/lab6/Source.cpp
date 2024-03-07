#include "Array.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	Array arr1;

	cout << "Массив: ";
	arr1.print_array();

	cout << "Произведение элементов, стоящих на четных позициях: " << arr1.product() << endl;

	try
	{
		cout << "Сумма чисел между первым и последним нулевыми элементами: " << arr1.summ_between_zeros() << endl;
	}
	catch (ArrayException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.GetCode() << endl;
	}

	arr1.transform();
	arr1.print_array();

	return 0;
}
