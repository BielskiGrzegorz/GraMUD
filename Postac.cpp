#include "Postac.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void wypisz(string tekst, int predkosc)
{
	for (int i = 0; i < tekst.size(); i++)
	{
		cout << tekst[i];
		Sleep(predkosc);
	}
}

void Postac::zapisz()
{
	ofstream plik(dane);
	
	plik << login << " " << nickname << " " << klasa << " " << dane << " " << x << " " << y << endl;

	plik.close();

}

void Postac::stworz()
{
	char kl;
	if (nickname == "puste")
	{
		string tekst;
		wypisz("Podaj Swe imie, dzielny rycerzu... \n", 75);
		cin >> nickname;
		wypisz("\nKimze jestes wedrowcze? \nWedrownym 'Mag'iem, zagubionym 'Wojownik'iem, dzielnym 'Palladyn'em, a moze niecnym 'Zlodziej'aszkiem??", 50);
		wypisz("\nHmm... \n", 300);
		cin >> klasa;
		cout << endl;
		if (klasa == "Mag") kl = '1'; if (klasa == "Wojownik") kl = '2'; if (klasa == "Palladyn") kl = '3'; if (klasa == "Zlodziej") kl = '4';
		switch (kl)
		{
		case '1' :
		{
			wypisz("Wiedzialem zes nie byle kto... po pierwszym wejrzeniu zem widzial, ze ty czlowiek oczytany... ", 75);
		}
		break;
		case '2':
		{
			wypisz("Ha! Zaiste zbedne pytanie, przecie widac ze chlop po byku!", 75);
		}
		break;
		case '3':
		{
			wypisz("Wiedzialem... szczena kwadratowa, a z krzyzem u boku chodzi... ", 75);
		}
		break;
		case '4':
		{
			wypisz("Dziwny to czlek, co para sie szemranym interesem i ludziom o tym rozpowiada...", 75);
			wypisz("\n... ja to Tobie w sekrecie tez cos zdradze bom nie z tych co zycie prawe wioda... Czasem tez se podkradne czeresni z drzewa Pana.. ", 125);
		}
		default :
		break;
		}
	}
}

void Postac::wczytajGre()
{
	ifstream plik(dane);

	plik >> login >> nickname >> klasa >> dane >> x >> y;
	
	plik.close();
}