#pragma hdrstop

#include <climits>
#include "IAGato.h"
#include "static_block.hpp"

#pragma package(smart_init)

static_block {
   srand(time(0));
}

Movimiento IAGato::calculaMovimiento(
      char **tablero,
      std::vector<Celda> celdasDisponibles,
      int filasPosGanadoras,
      int columnasPosGanadoras,
      Celda **posGanadoras,
      char marcaIA,
      char marcaHumano,
      int dificultad
   ) {
   Movimiento movimiento;
   int indJugada;

   if (dificultad == 0) {
      movimiento = movimientoAleatorio(celdasDisponibles);
   }
   else if(dificultad == 1) {
      indJugada = rand() % 2;

      if (indJugada == 0) {
         movimiento = movimientoAleatorio(celdasDisponibles);
      }
      else {
         movimiento = minimax(
               tablero,
               celdasDisponibles,
               filasPosGanadoras,
               columnasPosGanadoras,
               posGanadoras,
               marcaIA,
               marcaHumano,
               marcaIA
         );
      }
   }
   else {
      movimiento = minimax(
            tablero,
            celdasDisponibles,
            filasPosGanadoras,
            columnasPosGanadoras,
            posGanadoras,
            marcaIA,
            marcaHumano,
            marcaIA
      );
   }

   return movimiento;
}

Movimiento IAGato::movimientoAleatorio(std::vector<Celda> celdasDisponibles) {
   int indCeldaDisponible = rand() % celdasDisponibles.size();
   Movimiento movimiento;
   movimiento.setCelda(celdasDisponibles[indCeldaDisponible]);

   return movimiento;
}

Movimiento IAGato::minimax(
      char **tablero,
      std::vector<Celda> celdasDisponibles,
      int filasPosGanadoras,
      int columnasPosGanadoras,
      Celda **posGanadoras,
      char marcaIA,
      char marcaHumano,
      char marcaJugador
   ) {
   Movimiento movimiento;

   if(esGanador(tablero, filasPosGanadoras, columnasPosGanadoras, posGanadoras, marcaIA)) {
      movimiento.setPuntaje(10);
      return movimiento;
   }
   else if(esGanador(tablero, filasPosGanadoras, columnasPosGanadoras, posGanadoras, marcaHumano)) {
      movimiento.setPuntaje(-10);
      return movimiento;
   }
   else if(celdasDisponibles.empty()) {
      movimiento.setPuntaje(0);
      return movimiento;
   }

   std::vector<Movimiento> movimientos;

   for(int i = 0; i < celdasDisponibles.size(); i++) {
      movimiento = Movimiento();
      Celda celdaActual = celdasDisponibles[i];
      movimiento.setCelda(celdaActual);
      tablero[celdaActual.getFila()][celdaActual.getColumna()] = marcaJugador;
      std::vector<Celda> copiaCeldasDisponibles = copiaCeldasDisponiblesSinElemento(celdasDisponibles, i);

      if(marcaJugador == marcaIA) {
         movimiento.setPuntaje(
               minimax(
                     tablero,
                     copiaCeldasDisponibles,
                     filasPosGanadoras,
                     columnasPosGanadoras,
                     posGanadoras,
                     marcaIA,
                     marcaHumano,
                     marcaHumano
               )
            .getPuntaje()
         );
      }
      else {
         movimiento.setPuntaje(
               minimax(
                     tablero,
                     copiaCeldasDisponibles,
                     filasPosGanadoras,
                     columnasPosGanadoras,
                     posGanadoras,
                     marcaIA,
                     marcaHumano,
                     marcaIA
               )
            .getPuntaje()
         );
      }

      tablero[celdaActual.getFila()][celdaActual.getColumna()] = CHAR_MIN;
      movimientos.push_back(movimiento);
   }

   return mejorMovimiento(movimientos, marcaJugador, marcaIA);
}

bool IAGato::esGanador(char **tablero, int filasPosGanadoras, int columnasPosGanadoras, Celda **posGanadoras, char marcaJugador) {
   int combGanadora = marcaJugador * 3;
   int combActual = 0;
   bool esGanador = false;
   Celda celda;

   for(int fila = 0; fila < filasPosGanadoras; fila++) {
      for (int columna = 0; columna < columnasPosGanadoras; columna++) {
         celda = posGanadoras[fila][columna];
         combActual += tablero[celda.getFila()][celda.getColumna()];
      }

      if (combActual == combGanadora) {
         esGanador = true;
         break;
      }

      combActual = 0;
   }

   return esGanador;
}

std::vector<Celda> IAGato::copiaCeldasDisponiblesSinElemento(std::vector<Celda> celdasDisponibles, int indElementoEliminar) {
   std::vector<Celda> copiaCeldasDisponibles;

   for (Celda celda : celdasDisponibles) {
      copiaCeldasDisponibles.push_back(celda);
   }

   copiaCeldasDisponibles.erase(copiaCeldasDisponibles.begin() + indElementoEliminar);

   return copiaCeldasDisponibles;
}

Movimiento IAGato::mejorMovimiento(std::vector<Movimiento> listaMovimientos, char marcaJugadorActual, char marcaIA) {
   Movimiento mejorMovimiento;
   int mejorPuntaje;

   if(marcaJugadorActual == marcaIA) {
      mejorPuntaje = INT_MIN;

      for (Movimiento movimientoActual : listaMovimientos) {
         if(movimientoActual.getPuntaje() > mejorPuntaje) {
            mejorPuntaje = movimientoActual.getPuntaje();
            mejorMovimiento = movimientoActual;
         }
      }
   }
   else {
      mejorPuntaje = INT_MAX;

      for(Movimiento movimientoActual : listaMovimientos) {
         if(movimientoActual.getPuntaje() < mejorPuntaje) {
            mejorPuntaje = movimientoActual.getPuntaje();
            mejorMovimiento = movimientoActual;
         }
      }
   }

   return mejorMovimiento;
}
