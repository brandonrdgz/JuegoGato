//---------------------------------------------------------------------------

#pragma hdrstop

#include "Movimiento.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Movimiento::Movimiento() {}

const Celda &Movimiento::getCelda() const {
   return celda;
}

void Movimiento::setCelda(const Celda &celda) {
   Movimiento::celda = celda;
}

int Movimiento::getPuntaje() const {
   return puntaje;
}

void Movimiento::setPuntaje(int puntaje) {
   Movimiento::puntaje = puntaje;
}