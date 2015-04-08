#include "Auto.h"


bool Auto::operator <(const Auto & kitas){
	return Pav > kitas.Pav || Pav == kitas.Pav && kitas.Mod > kitas.Mod;
}

bool Auto::operator >(const Auto & kitas){
	return Kaina < kitas.Kaina;
}