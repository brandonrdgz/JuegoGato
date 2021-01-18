//---------------------------------------------------------------------------

#pragma hdrstop

#include <climits>
#include "IAGato.h"
#include "static_block.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const Celda IAGato::posGanadoras[8][3] {
      {Celda(0, 0), Celda(0, 1), Celda(0, 2)},
      {Celda(1, 0), Celda(1, 1), Celda(1, 2)},
      {Celda(2, 0), Celda(2, 1), Celda(2, 2)},
      {Celda(0, 0), Celda(1, 0), Celda(2, 0)},
      {Celda(0, 1), Celda(1, 1), Celda(2, 1)},
      {Celda(0, 2), Celda(1, 2), Celda(2, 2)},
      {Celda(0, 0), Celda(1, 1), Celda(2, 2)},
      {Celda(0, 2), Celda(1, 1), Celda(2, 0)}
};

static_block {
   srand(time(0));
}

std::vector<Celda> IAGato::celdasVacias(int filas, int columnas, char **tablero) {
   std::vector<Celda> celdasVacias;

   for (int fila = 0; fila < filas; fila++) {
      for (int columna = 0; columna < columnas; columna++) {
         if (tablero[fila][columna] == CHAR_MIN) {
            celdasVacias.push_back(Celda(fila, columna));
         }
      }
   }

   return celdasVacias;
}

bool IAGato::esGanador(char **tablero, char jugador) {
   int ganador = jugador * 3;
   int combActual = 0;
   bool esGanador = false;
   int filas = sizeof(posGanadoras) / sizeof(posGanadoras[0]);
   int columnas = sizeof(posGanadoras[0]) / sizeof(posGanadoras[0][0]);
   Celda celda;

   for(int fila = 0; fila < filas; fila++) {
      for (int columna = 0; columna < columnas; columna++) {
         celda = posGanadoras[fila][columna];
         combActual += tablero[celda.getFila()][celda.getColumna()];
      }

      if (combActual == ganador) {
         esGanador = true;
         break;
      }

      combActual = 0;
   }

   return esGanador;
}

Movimiento IAGato::minimax(int filas, int columnas, char **tablero, char IA, char humano, char jugador) {
   std::vector<Celda> celdasVacias = IAGato::celdasVacias(filas, columnas, tablero);
   Movimiento movimiento = Movimiento();

   if(esGanador(tablero, IA)) {
      movimiento.setPuntaje(10);
      return movimiento;
   }
   else if(esGanador(tablero, humano)) {
      movimiento.setPuntaje(-10);
      return movimiento;
   }
   else if(celdasVacias.empty()) {
      movimiento.setPuntaje(0);
      return movimiento;
   }

   std::vector<Movimiento> movimientos;

   for(Celda celda : celdasVacias) {
      movimiento = Movimiento();
      movimiento.setCelda(celda);
      tablero[celda.getFila()][celda.getColumna()] = jugador;

      if(jugador == IA) {
         movimiento.setPuntaje(minimax(filas, columnas, tablero, IA, humano, humano).getPuntaje());
      }
      else {
         movimiento.setPuntaje(minimax(filas, columnas, tablero, IA, humano, IA).getPuntaje());
      }

      tablero[celda.getFila()][celda.getColumna()] = CHAR_MIN;
      movimientos.push_back(movimiento);
   }

   Movimiento mejorMovimiento = Movimiento();
   int mejorPuntaje;

   if(jugador == IA) {
      mejorPuntaje = INT_MIN;

      for (Movimiento movimientoActual : movimientos) {
         if(movimientoActual.getPuntaje() > mejorPuntaje) {
            mejorPuntaje = movimientoActual.getPuntaje();
            mejorMovimiento = movimientoActual;
         }
      }
   }
   else {
      mejorPuntaje = INT_MAX;

      for(Movimiento movimientoActual : movimientos) {
         if(movimientoActual.getPuntaje() < mejorPuntaje) {
            mejorPuntaje = movimientoActual.getPuntaje();
            mejorMovimiento = movimientoActual;
         }
      }
   }

   return mejorMovimiento;
}

Movimiento IAGato::movimientoAleatorio(int filas, int columnas, char **tablero) {
   std::vector<Celda> celdasVacias = IAGato::celdasVacias(filas, columnas, tablero);
   int indCeldaVacia = rand() % celdasVacias.size();
   Movimiento movimiento;
   movimiento.setCelda(celdasVacias[indCeldaVacia]);

   return movimiento;
}

Movimiento IAGato::mejorMovimiento(int filas, int columnas, char **tablero, char IA, char humano, int dificultad) {
   Movimiento movimiento;
   int indJugada;

   if (dificultad == 0) {
      movimiento = movimientoAleatorio(filas, columnas, tablero);
   }
   else if(dificultad == 1) {
      indJugada = rand() % 2;

      if (indJugada == 0) {
         movimiento = movimientoAleatorio(filas, columnas, tablero);
      }
      else {
         movimiento = minimax(filas, columnas, tablero, IA, humano, IA);
      }
   }
   else {
      movimiento = minimax(filas, columnas, tablero, IA, humano, IA);
   }

   return movimiento;
}