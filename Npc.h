#ifndef Npc_h
#define Npc_h
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
//!  Npc class. 
/*!
Klasa odpowiada za interakcje z Npc ktore mozna napotkac przemierzajadz mapke wyswietlana graficznie
*/
class Npc
{
public:
	std::vector<Npc> npc;
	std::string imie, tekst1, tekst2, tekst3, tekst4, tekst5;
	Npc() {};
	Npc(std::string _imie, std::string _tekst1, std::string _tekst2, std::string _tekst3, std::string _tekst4, std::string _tekst5);
	/**
	* wczytaj 
	* wczytuje dane dotyczace NPC'tow 
	*/
	void wczytaj();
	/**
	* rozmowa
	* inicjuje rozmowe z napotkanym NPC'tem
	*/
	void rozmowa(std::string s);
	/**
	* ilosc
	* zwraca ilosc NPC'tow
	*/
	int ilosc();

};


#endif // !Npc_h
