#include <iostream>

using namespace std;

class B1 {
private:
	int p;
public:

	B1(int inp) {
		p = inp;
		cout << "Работает конструктор B1. Параметр: " << p << endl;
	}

	void show_B1() {
		cout << "B1 = " << p << endl;
	}

	~B1() {
		cout << "Сработал деструктор B1" << endl;
	};
};

class B2 {
int p;
public:

	B2(int inp) {
		p = inp;
		cout << "Работает конструктор B2. Параметр: " << p << endl;
	}

	void show_B2() {
		cout << "B2 = " << p << endl;
	}

	~B2() {
		cout << "Сработал деструктор B2" << endl;
	};
};

class D1 : virtual protected B1, virtual public B2
{
private:
	int p;
public:
	D1(int inp, int x, int y) : B1(x), B2(y)
	{
		p = inp;
		cout << "Работает конструктор D1. Параметр: " << p << endl;

	}

	void show_D1() {
		cout << "D1 = " << p << endl;
		show_B1();
		show_B2();
	}

	~D1() {
		cout << "Сработал деструктор D1" << endl;
	};
};

class D2 :virtual protected B2, virtual public B1
{
private:
	int p;
public:
	D2(int inp, int x, int y) : B2(x), B1(y)
	{
		p = inp;
		cout << "Работает конструктор D2. Параметр: " << p << endl;

	}

	void show_D2() {
		cout << "D2 = " << p << endl;
		show_B2();
		show_B1();
	}

	~D2() {
		cout << "Сработал деструктор D2" << endl;
	}
};

class D3 : protected D1, public D2
{
private:
	int p;
public:
	D3(int inp, int x, int y, int i, int j, int g, int h) : D1(x, y, i), D2(j, g, h), B1(y), B2(i)
	{
		p = inp;
		cout << "Работает конструктор D3. Параметр: " << p << endl;

	}

	void show_D3() {
		cout << "D3 = " << p << endl;
		show_D1();
		show_D2();
	}

	~D3() {
		cout << "Сработал деструктор D3" << endl;
	};
};

class D4 : public D3
{
private:
	int p;
public:
	D4(int inp, int x, int y, int i, int j, int g, int h, int r) : D3(x, y, i, j, g, h, r)
	{
		p = inp;
		cout << "Работает конструктор D3. Параметр: " << p << endl;

	}

	void show_D4() {
		cout << "D4 = " << p << endl;
		show_D3();
	}

	~D3() {
		cout << "Сработал деструктор D4" << endl;
	};
};

int main()
{
	setlocale(LC_ALL, "Ru");
	cout << "D3 d3(1, 2, 3, 4, 5, 6, 7)" << endl;
	cout << "Следуя иерархии класса D3:" << endl;
	D3 d3(1, 2, 3, 4, 5, 6, 7);
	
	d3.show_D3();

	return 0;
}