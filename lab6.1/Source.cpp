#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

void Create(int* a, const int size, const int Min, const int Max, int i)
{
	a[i] = Min + rand() % (Max - Min + 1);

	if (i < size - 1) 
	{
		Create(a, size, Min, Max, i + 1);
	}

}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Kilkist(int* a, const int size, int i, int k)
{
	
	if ((a[i] < 0) || (a[i] > 0 && (a[i] % 2 == 1)))
	{
		k++;
	}
	

	if (i < size - 1)
	{
		Kilkist(a, size, i + 1, k);
	}
	else return k;

}

int Suma(int* a, const int size, int i, int sum)
{

	if ((a[i] < 0) || (a[i] > 0 && (a[i] % 2 == 1)))
	{
		sum += a[i];
	}


	if (i < size - 1)
	{
		Suma(a, size, i + 1, sum);
	}
	else return sum;

}

void Сriteria(int* a, const int size, int i)
{
	if ((a[i] < 0) || (a[i] > 0 && (a[i] % 2 == 1)))
	{
		a[i] = 0;
	}

	if (i < size - 1)
	{
		Сriteria(a, size, i + 1);
	}
}



int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int a[n];
	const int Min = -50;
	const int Max = 15;
	int kil, sum;
	
	Create(a, n, Min, Max, 0);
	Print(a, n, 0);
	kil = Kilkist(a, n, 0, 0);
	sum = Suma(a, n, 0, 0);
	Сriteria(a, n, 0);
	cout << "kilkist elementiv kryteriy = " << kil << endl;
	cout << "suma elementiv kryteriy = " << sum << endl;
	Print(a, n, 0);

}