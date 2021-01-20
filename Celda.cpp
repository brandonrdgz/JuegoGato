#pragma hdrstop

#include "Celda.h"

#pragma package(smart_init)

Celda::Celda() {}

Celda::Celda(int fila, int columna) : fila(fila), columna(columna) {}

int Celda::getFila() const {
   return fila;
}

void Celda::setFila(int fila) {
   Celda::fila = fila;
}

int Celda::getColumna() const {
   return columna;
}

void Celda::setColumna(int columna) {
   Celda::columna = columna;
}