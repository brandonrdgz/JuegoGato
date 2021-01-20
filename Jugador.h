#ifndef JugadorH
#define JugadorH

#include "TipoJugador.h"

class Jugador {
private:
   int id;
   TipoJugador tipoJugador;
   char marca;
   bool iniciaJuego;

public:
   Jugador();
   Jugador(int id, const TipoJugador &tipoJugador, char marca, bool iniciaJuego);

   int getId() const;

   const TipoJugador &getTipoJugador() const;
   void setTipoJugador(const TipoJugador &tipoJugador);

   char getMarca() const;
   void setMarca(char marca);

   bool getIniciaJuego() const;
   void setIniciaJuego(bool iniciaJuego);
};
#endif
