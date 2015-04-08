#include "Modeliai.h"

#include <fstream>
#include <iomanip>

using namespace std;

const string CDuom = "Duomenys.txt";
const string CRez = "Rezultatai.txt";

const double CProc = 0.25;

void Nuskaityti(Modeliai & M);
double DidKaina(Modeliai & M);
Modeliai Atrinkti(Modeliai & M);

void SpausdintiPradiniusDuomenis(const string & duom, const string & rez);
void Spausdinti(const string & rez, Modeliai & M, const string & Komentaras);

int main(){

	Modeliai A;
	Nuskaityti(A);
	SpausdintiPradiniusDuomenis(CDuom, CRez);

	Spausdinti(CRez, A, "Pradiniai duomenys lenteleje");
	Modeliai B = Atrinkti(A);
	Spausdinti(CRez, B, "Atrinkti duomenys");
	B.Surykiuoti();
	Spausdinti(CRez, B, "Surykiuoti duomenys pagal pavadinima ir modeli");
	B.SurykiuotiPagalKaina();
	Spausdinti(CRez, B, "Surykiuoti duomenys pagal Kaina");

	return 0;
}

void Nuskaityti(Modeliai & M){
	ifstream fi(CDuom);
	string pav, mod;
	double k;
	while (!fi.eof()){
		getline(fi, pav, ',');
		fi >> ws;
		getline(fi, mod, ',');
		fi >> k;
		M.Prideti(Auto(pav, mod, k));
		fi.ignore(80, '\n');
	}
	fi.close();
}


double DidKaina(Modeliai & M){
	double k = -1;
	for (M.Pradzia(); M.Yra(); M.Kitas()){
		if (k < M.Imti().ImtiKaina()){
			k = M.Imti().ImtiKaina();
		}
	}
	return k;
}

Modeliai Atrinkti(Modeliai & M){
	double kaina = DidKaina(M) * (1 - CProc);

	Modeliai naujas;

	for (M.Pradzia(); M.Yra(); M.Kitas()){
		Auto info = M.Imti();
		if (info.ImtiKaina() >= kaina){
			naujas.Prideti(info);
		}
	}

	return naujas;
}

void SpausdintiPradiniusDuomenis(const string & duom, const string & rez){
	ifstream fi(duom);
	ofstream fo(rez);

	fo << "Pradiniai Duomenys" << endl;
	fo << string(80, '-') << endl;

	while (!fi.eof()){
		string line;
		getline(fi, line);
		fo << line << endl;
	}
	fo << endl << endl;

	fo.close();
	fi.close();
}

void Spausdinti(const string & rez, Modeliai & M, const string & Komentaras){
	ofstream fo(rez, ios::app);

	fo << Komentaras << endl;
	fo << string(80, '-') << endl;
	fo << setw(40) << " Pavadinimas " << setw(20) << " Modelis " << setw(20) << " Kaina " << endl;
	fo << string(80, '-') << endl;
	for (M.Pradzia(); M.Yra(); M.Kitas()){
		Auto t = M.Imti();
		fo << setw(40) << t.ImtiPavadinima() << setw(20) << t.ImtiModeli() << setw(20) << t.ImtiKaina() << endl;
	}
	fo << string(80, '-') << endl;
	fo << endl << endl;
	fo.close();
}