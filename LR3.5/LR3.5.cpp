// Лабораторная работа №3
// Вариант 5
// Создать класс bMoney, 
// в котором необходимо перегрузить арифметические операторы для работы с денежным форматом.
// Перегрузить два оператора следующим образом:
// long double* bMoney // умножить число на деньги
// long double / bMoney // делить число на деньги
// Эти операторы требуют наличия дружественных функций,
// т.к.справа от оператора находится объект, а слева – обычное число.
// Необходимо убедиться, что main() позволяет пользователю ввести две денежные строки и число с плавающей запятой, 
// а затем корректно выполнить все семь арифметических действий с соответствующими парами значений.

#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

class bMoney
{
private:
	double money;

public:
	bMoney(double mc);

	double operator+(double a)
	{
		return money + a;
	}

	double operator-(double a)
	{
		return money - a;
	}
	
	double operator*(double a)
	{
		return money * a;
	}

	double operator/(double a)
	{
		return money / a;
	}

	int operator%(int a)
	{
		return fmod(money,a);
	}

	friend double operator*(long t, bMoney m);
	friend double operator/(long t, bMoney m);

};

bMoney::bMoney(double mc = 0)
{
	money = mc;
}

double operator*(long l, bMoney m)
{
	return m.money * l;
}

double operator/(long t, bMoney m)
{
	return t / m.money;
}

int main()
{
	double m;
	double a;
	bMoney result;
	setlocale(LC_ALL, "");
    cout << "Введите значение money ";
	cin >> m;
	cout << "Введите значение a ";
	cin >> a;
	result = bMoney(m);
	cout << result + a << endl;
	cout << result - a << endl;
	cout << result * a << endl;
	cout << result / a << endl;
	cout << result % a << endl;
	cout << a * result << endl;
	cout << a / result << endl;

}
