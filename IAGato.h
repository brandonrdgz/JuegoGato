#ifndef IAGatoH
#define IAGatoH

#include <vector>
#include "Celda.h"
#include "Movimiento.h"

class IAGato {
private:
   static Movimiento movimientoAleatorio(std::vector<Celda> celdasDisponibles);
   static Movimiento minimax(
      char **tablero,
      std::vector<Celda> celdasDisponibles,
      int filasPosGanadoras,
      int columnasPosGanadoras,
      Celda **posGanadoras,
      char marcaIA,
      char marcaHumano,
      char marcaJugador
   );

   template <typename T>
   static std::vector<T> copiaVector(std::vector<T> vectorOrigen, int indInicio, int indFin);

   static Movimiento mejorMovimiento(std::vector<Movimiento> listaMovimientos, char marcaJugadorActual, char marcaIA);

public:
   static Movimiento calculaMovimiento(
      char **tablero,
      std::vector<Celda> celdasDisponibles,
      int filasPosGanadoras,
      int columnasPosGanadoras,
      Celda **posGanadoras,
      char marcaIA,
      char marcaHumano,
      int dificultad
   );
   static bool esGanador(char **tablero, int filasPosGanadoras, int columnasPosGanadoras, Celda **posGanadoras, char marcaJugador);
};

#endif
