#include "BazaDanych.h"
#include "GameManager.h"
#include "Klasa.h"
#include<iostream>
#include<string>
#include"Postac.h"
#include<conio.h>
#include <windows.h>

using namespace std;


int main()
{
	BazaDanych baza;
	Postac postac;
	GameManager manager;
	Wojownik woj;
	Mag mag;
	Zlodziej zlo;
	Palladyn pal;
	Klasa *wsk;
	wsk = &mag;
	string map = "dane/Mapy/mapa.txt";
	manager.wczytajMape(map);
	baza.wczytaj("dane/BazaDanych.txt");
	char wybor,c='b';
	
	for (;;)
	{
		system("cls");
		cout << "c===|[::::::::> Fallen Kingdom XII <::::::::]|===c\n\n                    ~~MENU~~                      \n\n        c=|[::>   1) New Game      <::]|=c        \n\n        c=|[::>   2) Continue      <::]|=c        \n";
		cin >> wybor;
		switch (wybor)
		{
		case '1':
		{
			baza.rejestracja();
			system("cls");
			baza.zapisz("dane/BazaDanych.txt");
			postac.stworz();
			postac.zapisz();
			wybor = 's';
		}
		break;
		case '2':
		{
			system("cls");
			baza.zaloguj(&postac.login, &postac.dane);
			postac.wczytajGre();
			wybor = 's';
		}
		break;
		default:
			break;
		}
		if (wybor == 's') break;
	}
	system("cls");
	////////////////////////////////////////
	if (postac.klasa == "Mag") wsk = &mag;
	if (postac.klasa == "Wojownik") wsk = &woj;
	if (postac.klasa == "Palladyn") wsk = &pal;
	if (postac.klasa == "Zlodziej") wsk = &zlo;
	manager.poruszanie(&postac.x, &postac.y,&postac);

	
	_getch();
	return 0;
}