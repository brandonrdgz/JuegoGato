//---------------------------------------------------------------------------

#ifndef CeldaH
#define CeldaH
//---------------------------------------------------------------------------
class Celda {
private:
   int fila;
   int columna;

public:
   Celda();

   Celda(int fila, int columna);

   int getFila() const;
   void setFila(int fila);
   int getColumna() const;
   void setColumna(int columna);
};
#endif
