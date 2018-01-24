#ifndef Postac_h
#define Postac_h

#include<iostream>
#include<string>
//!  Postac class. 
/*!
Klasa odpowiada za wczytanie postaci, kazda postac ma nick(nazwe postaci gracza, punkty zycia, klase)
*/
class Postac
{
public:
	double zycie;
	
	std::string login, nickname, klasa, dane;
	int x, y;
	/**
	* konstruktor podstawowej postaci
	*/
	Postac() { nickname = "puste"; x = 7; y = 1; zycie = 100; };
	/**
	* stworz
	tworzy postac
	*/
	void stworz();
	/**
	* zapisz zapisuje postac, wraz z polozeniem
	*/
	void zapisz();
	/**
	* wczytajGre
	wczytuje zapis
	*/
	void wczytajGre();
	
};
#endif // !Postac_h
