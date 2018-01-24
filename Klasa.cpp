#include "Klasa.h"
using namespace std;



void Wojownik::lvlUp(int i) //i - poziom
{
	atak = atak + i*0.5;
	atakM = atakM + i*0.1;
	obrona = obrona + i*0.3;
	obronaM = obronaM + i*0.1;

} 
double Wojownik::atakuj(double bron,double bronM)
{
	double _obrazenia;
	_obrazenia = bron + bronM + atak + atakM;
	return _obrazenia;
}
double Wojownik::obron(double _obrazenia)
{
	double obrazenia;
	obrazenia = _obrazenia - obrona - obronaM;
	return obrazenia;
}


void Mag::lvlUp(int i) //i - poziom
{
	atak = atak + i*0.1;
	atakM = atakM + i*0.5;
	obrona = obrona + i*0.3;
	obronaM = obronaM + i*0.1;

}
double Mag::atakuj(double bron, double bronM)
{
	double _obrazenia;

	_obrazenia = bron + bronM + atak + atakM;
	return _obrazenia;
}
double Mag::obron(double _obrazenia)
{
	double obrazenia;
	obrazenia = _obrazenia - obrona - obronaM;
	return obrazenia;
}

void Zlodziej::lvlUp(int i) //i - poziom
{
	atak = atak + i*0.2;
	atakM = atakM + i*0.2;
	obrona = obrona + i*0.3;
	obronaM = obronaM + i*0.3;

}
double Zlodziej::atakuj(double bron, double bronM)
{
	double _obrazenia;
	_obrazenia = bron + bronM + atak + atakM;
	return _obrazenia;
}
double Zlodziej::obron(double _obrazenia)
{
	double obrazenia;
	obrazenia = _obrazenia - obrona - obronaM;
	return obrazenia;
}

void Palladyn::lvlUp(int i) //i - poziom
{
	atak = atak + i*0.2;
	atakM = atakM + i*0.1;
	obrona = obrona + i*0.1;
	obronaM = obronaM + i*0.3;

}
double Palladyn::atakuj(double bron, double bronM)
{
	double _obrazenia;
	_obrazenia = bron + bronM + atak + atakM;
	return _obrazenia;
}
double Palladyn::obron(double _obrazenia)
{
	double obrazenia;
	obrazenia = _obrazenia - obrona - obronaM;
	return obrazenia;
}



