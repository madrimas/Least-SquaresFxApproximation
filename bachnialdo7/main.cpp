#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

double* wynik(double *tabX, double *tabY, int size, int stopien);
double** wsp(double *tabX, double *tabY, int size, int stopien);


int main()
{
	int size = 10;
	double tabX[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 5 };
	double tabY[] = { -110, -60, -20, -10, -1.5, 2, 7, 18, 50, 170 };

	int stopien;
	cout << "Podaj stopien wielomianu: ";
	cin >> stopien;
	cout << endl;

	double *tabWynik = new double[stopien + 1];

	tabWynik = wynik(tabX, tabY, size, stopien);

	for (int i = 0; i <= stopien; i++)
	{
		cout << tabWynik[i] << endl;
	}

	double **tabWsp = new double*[stopien + 1];
	for (int i = 0; i <= stopien; i++)
	{
		tabWsp[i] = new double[stopien + 1];
	}

	tabWsp = wsp(tabX, tabY, size, stopien);

	for (int i = 0; i <= stopien; i++)
	{
		for (int j = 0; j <= stopien; j++)
		{
			cout << " + (" << tabWsp[i][j] << "*a" << j << ")";

		}
		cout << " = " << tabWynik[i] << endl;
	}

	delete [] tabWynik;
	for (int i = 0; i <= stopien; i++) 
	{
		delete [] tabWsp[i];
	}
	delete [] tabWsp;

	system("pause");
	return 0;
}


double *wynik(double *tabX, double *tabY, int size, int stopien)
{
	double *tab = new double[stopien + 1];

	for (int i = 0; i <= stopien; i++)
	{
		tab[i] = 0;
		for (int j = 0; j < size; j++)
		{
			tab[i] += tabY[j] * (pow(tabX[j], i));
		}
	}
	return tab;
}

double **wsp(double *tabX, double *tabY, int size, int stopien)
{
	double **tab = new double*[stopien + 1];
	for (int i = 0; i <= stopien; i++)
	{
		tab[i] = new double[stopien + 1];
	}

	for (int i = 0; i <= stopien; i++)
	{
		for (int j = i; j <= stopien; j++)
		{
			tab[i][j] = 0;
			for (int k = 0; k < size; k++)
			{
				tab[i][j] += pow((tabX[k]), (j + i));
			}
			tab[j][i] = tab[i][j];
		}
	}

	return tab;
}