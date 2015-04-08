#pragma once

#include <string>

using namespace std;

class Auto
{
private:
	string Pav;
	string Mod;
	double Kaina;
public:
	Auto(string Pavadinimas = "", string Modelis = "", double Kaina = 0.0) : Pav(Pavadinimas), Mod(Modelis), Kaina(Kaina) {}
	~Auto() {}
	string ImtiPavadinima() const{ return Pav; }
	string ImtiModeli() const{ return Mod; }
	double ImtiKaina() const{ return Kaina; }

	/**Pavadinimu palyginimas*/
	bool operator <(const Auto & kitas);
	/**Kainu palyginimas*/
	bool operator >(const Auto & kitas);
};

