#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

class Tour
{
protected:
	double price;
	int ticket;
	char rn[30];
public:
	void Init(double a, int b, char* r);
	void Display();
	double Total();
	void Read();

};

void Tour::Init(double a, int b, char* r)
{
	price = a;
	ticket = b;
	strcpy(rn, r);
}


void Tour::Display()
{
	cout << rn[0] << endl;
	cout << "Цена за тур: " << price << endl;
	cout << "Кол-во билетов: " << ticket << endl;
}
double Tour::Total()
{
	return price * ticket;
}
void Tour::Read()
{
	cout << "Цена за тур? - ";
	cin >> price;
	cout << "Кол-во билетов? - ";
	cin >> ticket;
}

class BurningTicket : public Tour
{
protected:
	int type = 0;
public:
	void Type(double a, int b, char* r, int t);
	double Total(int t);
};

void BurningTicket::Type(double a, int b, char* r, int t)
{
	Init(a, b, r);
	this->type = t;
}

double BurningTicket::Total(int t)
{
	if (this->type = t == 0)
	{
		return price * ticket;
	}
	else
	{
		if (this->type = t == 1)
		{
			return price * ticket - ((price * ticket * 30) / 100);
		}
		else
		{
			cout << "Такого вида путёвки нет!";
			return 0;
		}
	}
}

class Agency
{
private:
	Tour* item1;
	BurningTicket* item2;
	int percentage_ticket1, percentage_ticket2;

public:
	Agency(Tour* firstTour, BurningTicket* secondTour);
	void Read();
	double AllPrise();
};

Agency::Agency(Tour* firstTour, BurningTicket* secondTour)
{
	this->item1 = firstTour;
	this->item2 = secondTour;
}

void Agency::Read()
{
	cout << "Первый тур" << endl;
	item1->Read();
	cout << "Второй тур" << endl;
	item2->Read();
	cout << endl;

}

double Agency::AllPrise()
{
	int n;
	cout << "Реальный процент купленных путевок первого тура? - ";
	cin >> percentage_ticket1;
	cout << "Реальный процент купленных путевок второго тура? - ";
	cin >> percentage_ticket2;
	cout << "Типы путёвок: 1 - горящая путевка / 0 - обычная путёвка" << endl;
	cout << "Введите тип путёвки: ";
	cin >> n;
	double total = item1->Total() * percentage_ticket1 / 100 + item2->Total(n) * percentage_ticket2 / 100;
	return total;
}

int main(int arec, char const* argv[])
{
	setlocale(LC_ALL, ".1251");
	Tour* item1 = new Tour();
	BurningTicket* item2 = new BurningTicket();
	Agency* trip = new Agency(item1, item2);
	trip->Read();
	double result = trip->AllPrise();
	cout << "Сумма денег от продаж = " << result;
}
