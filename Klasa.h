#ifndef Klasa_h
#define Klasa_h

//!  Klasa class. 
/*!
Klasa odpowiada za mnoznik ataku, obrony ,ataku magicznego oraz obrony magicznej dla kazdej klasy postaci
podlicza tez obrazenia za wyprowadzony atak, i oblicza otrzymane obrazenia z uwzglednieniem obony postaci
zastosowano tutaj polimorfizm po klasie abstrakcyjnej twarzacy swego rodzaju interface
aby kazda nastepna dodana klasa postaci nie odbiegala od ogolnego wzorca
*/

class Klasa
{
public :
	/**
	*lvlUp
	* mnoznik ataku i obrony
	*/
	void virtual lvlUp(int i) = 0;
	/**
	* atakuj
	wyprowadza atak
	*/
	double virtual atakuj(double bron, double bronM) = 0;
	/**
	* obron 
	oblicza obrazenia
	*/
	double virtual obron(double _obrazenia) = 0;
};

class Wojownik : public Klasa
{
public:
	double atak, atakM, obrona, obronaM;
	void virtual lvlUp(int i);
	double virtual atakuj(double bron, double bronM);
	double virtual obron(double _obrazenia);
};

class Mag : public Klasa
{
public:
	double atak, atakM, obrona, obronaM;
	void virtual lvlUp(int i);
	double virtual atakuj(double bron, double bronM);
	double virtual obron(double _obrazenia);
};

class Zlodziej : public Klasa
{
public:
	double atak, atakM, obrona, obronaM;
	void virtual lvlUp(int i);
	double virtual atakuj(double bron, double bronM);
	double virtual obron(double _obrazenia);
};

class Palladyn : public Klasa
{
public:
	double atak, atakM, obrona, obronaM;
	void virtual lvlUp(int i);
	double virtual atakuj(double bron, double bronM);
	double virtual obron(double _obrazenia);
};


#endif // !Klasa
