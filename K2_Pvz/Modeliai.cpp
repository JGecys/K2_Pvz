#include "Modeliai.h"

Modeliai::Modeliai(Modeliai & kitas) : pr(NULL), pb(NULL), dd(NULL) {
	for (kitas.dd = kitas.pr; kitas.dd != NULL; kitas.dd = kitas.dd->kitas){
		Prideti(kitas.dd->info);
	}
}

Modeliai Modeliai::operator = (Modeliai & kitas){

	if (this == &kitas){ //Ar tai yra taspats objektas??
		return *this;
	}
	Naikinti();

	for (kitas.dd = kitas.pr; kitas.dd != NULL; kitas.dd = kitas.dd->kitas){
		Prideti(kitas.dd->info);
	}

	return *this;
}

void Modeliai::Naikinti(){
	while (pr != NULL){
		Mazgas * t = pr;
		pr = pr->kitas;
		delete t;
	}
	dd = pb = pr;
}

void Modeliai::Prideti(const Auto & duom){
	Mazgas *dd = new Mazgas(duom);
	if (!pr){ //Jei sarasas dar tuscias
		pr = pb = dd;
	}
	else{ //Jei turi bent viena elementa, deda i gala.
		pb->kitas = dd;
		pb = dd;
	}
}


void Modeliai::Surykiuoti(){
	if (pr == NULL) // Jei tuscias nerykiuoti nieko
		return;

	bool yra = true; Mazgas * d, *d1;
	while (yra){ //Kol antras ciklas bent karta sukeite reiksmes
		yra = false;
		d = d1 = pr; //Abu prasideda pradzioje
		while (d1->kitas != NULL){
			d1 = d1->kitas;
			if (d->info < d1->info){ //Rykiavimo Salyga
				Auto temp = d1->info;
				d1->info = d->info;
				d->info = temp;
				yra = true;
			}
			d = d1;
		}
	}
}

void Modeliai::SurykiuotiPagalKaina(){
	if (pr == NULL) // Jei tuscias nerykiuoti nieko
		return;

	bool yra = true; Mazgas * d, *d1;
	while (yra){ //Kol antras ciklas bent karta sukeite reiksmes
		yra = false;
		d = d1 = pr; //Abu prasideda pradzioje
		while (d1->kitas != NULL){
			d1 = d1->kitas;
			if (d->info > d1->info){ //Rykiavimo Salyga
				Auto temp = d1->info;
				d1->info = d->info;
				d->info = temp;
				yra = true;
			}
			d = d1;
		}
	}
}