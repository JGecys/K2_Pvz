#pragma once

#include "Auto.h"

class Modeliai
{
private:
	struct Mazgas{
		Mazgas() : info(Auto()), kitas(NULL) {}
		Mazgas(Auto info) : info(info), kitas(NULL){}
		Auto info;
		Mazgas *kitas;
	};

	Mazgas * pr, * pb, * dd;

public:
	Modeliai() : pr(NULL), pb(NULL), dd(NULL) {}
	Modeliai(Modeliai & kitas);
	~Modeliai(){ Naikinti(); }
	void Naikinti();
	void Prideti(const Auto & duom);
	void Pradzia(){ dd = pr; }
	bool Yra(){ return dd != NULL; }
	void Kitas(){ dd = dd->kitas; }
	Auto Imti(){ return dd->info; }

	/**Surykiuoja abeceliskai*/
	void Surykiuoti();
	/**Surykiuoja pagal kaina*/
	void SurykiuotiPagalKaina();

	Modeliai operator = (Modeliai & kitas);

};

