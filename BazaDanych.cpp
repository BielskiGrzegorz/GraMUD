#include "BazaDanych.h"
#include <iostream>
#include <Windows.h>

using namespace std;

BazaDanych::BazaDanych(string _login, string _haslo, string _dane)
{
	login = _login;
	haslo = _haslo;
	dane = _dane;
}

void BazaDanych::wczytaj(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczytaj(linie);
		string _login, _haslo, _dane;
		wczytaj >> _login;
		wczytaj.ignore();
		wczytaj >> _haslo;
		wczytaj.ignore();
		wczytaj >> _dane;
		wczytaj.ignore();
		
		baza.push_back(BazaDanych(_login, _haslo, _dane));
	}
	plik.close();
}

void BazaDanych::zapisz(string s)
{
	ofstream plik(s);
	for (int i = 0; i < ilosc(); i++)
	{
		plik << baza[i].login << " " << baza[i].haslo << " " << baza[i].dane << endl;
	}
	plik.close();
}

void BazaDanych::rejestracja()
{
	string nowyLogin, noweHaslo, noweDane="-";
	char tn, nope='c';
	for (;;)
	{
		system("cls");
		cout << "Podaj login : ";
		cin >> nowyLogin;
		for (int i = 0; i < ilosc(); i++)
		{
			if (nowyLogin == baza[i].login)
			{
				nope = 'n';
				break;
			}
		}
		if (nope == 'n')
		{
			cout << "\nTen Login jest juz zajety, czy chcesz sprobowac ponownie? t/n \n";
			cin >> tn;
			if (tn == 'n')	exit(0);
			nope = 'c';
		}
		else
		{
			break;
		}

	}
	cout << "Podaj haslo : ";
	cin >> noweHaslo;
	noweDane = "dane/Save/" + nowyLogin + ".txt";
	baza.push_back(BazaDanych(nowyLogin, noweHaslo, noweDane));
}

void BazaDanych::zaloguj(string *_podmianaLogin, string *_podmianaDane)
{
		string _login, _haslo, _dane;
		cout << "Login : ";
		cin >> _login;
		bool a = false, b = false;

		for (int i = 0; i < ilosc(); i++)
		{
			if (_login == baza[i].login)
			{
				a = true;
				cout << endl << "Haslo : ";
				cin >> _haslo;

				if (_haslo == baza[i].haslo)
				{
					b = true;
					_dane = baza[i].dane;
					break;
				}

			}
		}
		switch (a)
		{
		case true:
		{
			if (b = true)
			{
				cout << "Logowanie Prawidlowe." << endl;
				Sleep(1000);
				*_podmianaLogin  = _login;
				*_podmianaDane = _dane;
			}
			else
			{
				cout << "Nieprawidlowe haslo." << endl;
				Sleep(1000);
				exit(0);
			}
		}
		break;
		case false:
		{
			cout << "Taki uzytkownik nie istnieje" << endl;
			Sleep(1000);
			exit(0);
		}
		break;
		}
}



int BazaDanych::ilosc()
{
	return baza.size();
}