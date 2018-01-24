#ifndef BazaDanych_h
#define BazaDanych_h

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

//!  BazaDanych class. 
/*!
Przechowuje dane zwiazane z kontem uzytkownika: login, haslo i sciezke do ktorej beda zapisywany postepy postaci uzytkownika
*/
class BazaDanych
{
public:
	std::vector<BazaDanych> baza;
	std::string login, haslo, dane;
	BazaDanych() {};
	BazaDanych(std::string _login, std::string _haslo, std::string _dane);
	/**
	* wczytaj
	wczytuje konta z pliku
	*/
	void wczytaj(std::string s);
	/**
	* zapisz
	zapisuje konta dopliku
	*/
	void zapisz(std::string s);
	/**
	* zaloguj
	sprawdza czy taki uzytkownik istnieje
	jezeli tak to zamienia login i dane w klasie postac
	*/
	void zaloguj(std::string *_podmianaLogin,std::string *_podmianaDane);
	/**
	* ilosc
	zwraca ilosc zarejestrowanych uzytkownikow
	*/
	int ilosc();
	/**
	* rejestracja
	rejestruje uzytkownika
	*/
	void rejestracja();

};
#endif // !BazaDanych_h
