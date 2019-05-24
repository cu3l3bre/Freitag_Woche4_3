#include <iostream>
#include <string>
#include <vector>

using namespace std;



// abstrakete Klasse die nur zur Vererbung genutzt wird
class GeometrischesObjekt
{
public:
	// abstrakte Klasse, weil eine Methode gleich 0 gesetzt wird
	// dient dann nur zur Verebung !!!
	// es kann dann kein Objekt / Instanz mehr erstellt werden
	virtual double flaecheBerechnen() = 0;

	virtual double umfangBerechnen() = 0;
};

// da die methode in einer abstrakten klasse ist,  MUSS die Methode in jeder abgeleiteten Klasse neu defniert werden !!!!!!

class Rechteck : public GeometrischesObjekt
{
public:

	double seiteA;
	double seiteB;

	double flaecheBerechnen()
	{
		double flaecheninhalt = seiteA * seiteB;
		return flaecheninhalt;
	}

	double umfangBerechnen()
	{
		double umfang = (2*seiteA) + (2*seiteB);
		return umfang;
	}


};


class Kreis : public GeometrischesObjekt
{
public:

	double radius;

	double flaecheBerechnen()
	{
		double flaecheninhalt = 3.14 * radius*radius;
		return flaecheninhalt;
	}


	double umfangBerechnen()
	{
		double umfang = 2 * radius * 3.14;
		return umfang;
	}
};





int main()
{
	cout << "Programm zu Freitag Woche4 Nr: 3" << endl << endl;

	// es kann kein Objekt einer abstrakten KLasse erstellt werden
	//GeometrischesObjekt geoObjekt;


	Rechteck rechteck1;
	rechteck1.seiteA = 2;
	rechteck1.seiteB = 3;
//	cout << rechteck1.flaecheBerechnen() << endl;

	Kreis kreis1;
	kreis1.radius = 10;
//	cout << kreis1.flaecheBerechnen() << endl;


	vector<GeometrischesObjekt*> formen;

	formen.push_back(&rechteck1);
	formen.push_back(&kreis1);


	for (int i = 0; i < formen.size(); i++)
	{
		cout << "Flaeche: " << formen[i]->flaecheBerechnen() << endl;
		cout << "Umfang: " << formen[i]->umfangBerechnen() << endl;
	}


	system("pause");
	return 0;
}