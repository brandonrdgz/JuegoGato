//---------------------------------------------------------------------------

#ifndef MovimientoH
#define MovimientoH
//---------------------------------------------------------------------------
#include "Celda.h"

class Movimiento {
private:
   Celda celda;
   int puntaje;

public:
   Movimiento();

   const Celda &getCelda() const;

   void setCelda(const Celda &celda);

   int getPuntaje() const;

   void setPuntaje(int puntaje);
};
#endif
