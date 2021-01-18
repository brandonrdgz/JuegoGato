//---------------------------------------------------------------------------

#ifndef IAGatoH
#define IAGatoH
//---------------------------------------------------------------------------

#include <vector>
#include "Celda.h"
#include "Movimiento.h"

class IAGato {
private:
   static const Celda posGanadoras[8][3];
   static Movimiento minimax(int filas, int columnas, char **tablero, char IA, char humano, char jugador);
   static Movimiento movimientoAleatorio(int filas, int columnas, char **tablero);

public:
   static std::vector<Celda> celdasVacias(int filas, int columnas, char **tablero);
   static Movimiento mejorMovimiento(int filas, int columnas, char **tablero, char IA, char humano, int dificultad);
   static bool esGanador(char **tablero, char jugador);
};

#endif
