#ifndef GameManager_h
#define GameManager_h
#include <iostream>
#include <fstream>
#include <string>
#include "Postac.h"
//!  GameManager class. 
/*!
Klasa odpowiada za wyswietlanie mapy i wczytywanie mapy, jest tutaj skonstruowany system poruszania sie
*/
class GameManager
{
public:
	GameManager() {};
	/**
	* tablica do ktorej bedzie wczytana mapa
	*/
	char mapa[40][40];
	int x, y;
	/**
	* wczytajMape.
	* wczytuje mape z pliku textowego
	*/
	void wczytajMape(std::string s);
	/**
	* wyswietlMape
	* wyswietla mape
	*/
	void wyswietlMape(int x, int y);

	/**
	* poruszanie
	* Poruszanie
	*/
	void poruszanie(int *x, int *y, Postac *postac);

};

#endif // !Manager_h
