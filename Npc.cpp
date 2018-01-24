#include "Npc.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Npc::Npc(string _imie, string _tekst1, string _tekst2, string _tekst3, string _tekst4, string _tekst5)
{
	imie = _imie; tekst1 = _tekst1; tekst2 = _tekst2; tekst3 = _tekst3; tekst4 = _tekst4; tekst5 = _tekst5;
}

void Npc::wczytaj()
{
	ifstream plik("dane/Npc.txt");
	string _imie, _tekst1, _tekst2, _tekst3, _tekst4, _tekst5, linie;
	while (getline(plik, linie))
	{
		stringstream wczytaj(linie);
		wczytaj >> _imie;
		wczytaj.ignore();
		wczytaj >> _tekst1;
		wczytaj.ignore();
		wczytaj >> _tekst2;
		wczytaj.ignore();
		wczytaj >> _tekst3;
		wczytaj.ignore();
		wczytaj >> _tekst4;
		wczytaj.ignore();
		wczytaj >> _tekst5;
		wczytaj.ignore();

		npc.push_back(Npc(_imie, _tekst1, _tekst2, _tekst3, _tekst4, _tekst5));
	}
	plik.close();
}

void Npc::rozmowa(string s)
{
	int i = 0;
	for (int j = 0; j < ilosc(); j++)
	{
		if (s == npc[j].imie)
		{
			i = j;
		}
	}
	string slowoklucz;
	system("cls");
	cout << npc[i].imie <<": Witaj!!"<< endl;
	cout << npc[i].tekst1;
	for (;;)
	{
		cin >> slowoklucz;
		if (slowoklucz == "zadanie")
		{
			cout << npc[i].tekst2;
		}
		if (slowoklucz == "handel")
		{
			cout << npc[i].tekst3;
		}
		if (slowoklucz == "walka")
		{
			cout << npc[i].tekst4;
		}
		if (slowoklucz == "bywaj")
		{
			cout << npc[i].tekst5;
			Sleep(1500);
			system("cls");
			break;
		}
	}
}
int Npc::ilosc()
{
	return npc.size();
}