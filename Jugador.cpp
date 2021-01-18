//---------------------------------------------------------------------------

#pragma hdrstop

#include "Jugador.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Jugador::Jugador() {}

Jugador::Jugador(int id, const TipoJugador &tipoJugador, char marca, bool iniciaJuego) : id(id),
                                                                                         tipoJugador(tipoJugador),
                                                                                         marca(marca),
                                                                                         iniciaJuego(iniciaJuego) {}

int Jugador::getId() const {
   return id;
}

const TipoJugador &Jugador::getTipoJugador() const {
   return tipoJugador;
}

void Jugador::setTipoJugador(const TipoJugador &tipoJugador) {
   Jugador::tipoJugador = tipoJugador;
}

char Jugador::getMarca() const {
   return marca;
}

void Jugador::setMarca(char marca) {
   Jugador::marca = marca;
}

bool Jugador::getIniciaJuego() const {
   return iniciaJuego;
}

void Jugador::setIniciaJuego(bool iniciaJuego) {
   Jugador::iniciaJuego = iniciaJuego;
}
