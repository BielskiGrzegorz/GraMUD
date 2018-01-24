#include "GameManager.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "Npc.h"
using namespace std;
void gotoxy(int x, int y)
{
	COORD cord;
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

void GameManager::wczytajMape(string s)
{
	ifstream wczyt(s);
	for (int i = 0; i<1000; i++)
	{
		for (int j = 0; j<10000; j++)
		{
			wczyt >> mapa[i][j];
		}
	}
	wczyt.close();
}
void GameManager::wyswietlMape(int x, int y)
{
	char s;
	s = 219;
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{

			if (mapa[i][j] == '.') 
				cout << ' ';
			else
				cout << s;
		}
		cout << endl;
	}
}

void GameManager::poruszanie(int *x, int *y,Postac *postac)
{
	Npc npc;
	npc.wczytaj();
	string tabnpc[40][40];

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			tabnpc[i][j] = " ";
		}
	}
	tabnpc[1][1] = "Andrzej";
	
	char c='b';
	int _x, _y;
	for (;;)
	{
		_x = *x;
		_y = *y;
		gotoxy(0, 0);
		wyswietlMape(*x, *y);
		gotoxy(_y, _x);
		cout << ' ';
		switch (c)
		{
		case 'a':
		{
			if (mapa[*x][*y - 1] != 'x')
				*y = *y - 1;

		}
		break;
		case 'd':
		{
			if (mapa[*x][*y + 1] != 'x')
				*y = *y + 1;

		}
		break;
		case 'w':
		{
			if (mapa[*x - 1][*y] != 'x')
				*x = *x - 1;

		}
		break;
		case 's':
		{
			if (mapa[*x + 1][*y] != 'x')
				*x = *x + 1;

		}
		break;
		case 'p':
		{
			postac->x = *x;
			postac->y = *y;
			postac->zapisz();

		}
		break;
		}
		if (tabnpc[*x][*y] != " ")
		{
			
			gotoxy(41, 2);
			npc.rozmowa(tabnpc[*x][*y]);
		}
		gotoxy(*y, *x);
		cout << 'O';
		c = _getch();
	}
}
