//---------------------------------------------------------------------------

#ifndef FormGatoH
#define FormGatoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <vector>
#include "Jugador.h"
#include "Movimiento.h"
//---------------------------------------------------------------------------
class TfmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Tablero;
   TButton *btnJugar;
   TLabel *LabelTextoTurno;
   TLabel *LabelTurno;
   TMainMenu *mmPrincipal;
   TButton *ButtonTerminar;
   TMenuItem *miAcercaDe;
   TStatusBar *sbGato;
   TMenuItem *miConfiguracion;
	void __fastcall TableroSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall btnJugarClick(TObject *Sender);
   void __fastcall miAcercaDeClick(TObject *Sender);
   void __fastcall ButtonTerminarClick(TObject *Sender);
   void __fastcall miConfiguracionClick(TObject *Sender);
   void __fastcall TableroDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
   void __fastcall FormShow(TObject *Sender);



private:	// User declarations
   int filas;
   int columnas;
	char **tablero;
   std::vector<Celda> listaCeldasDisponibles;
   Jugador jugadorActual;
   Jugador jugador1;
   Jugador jugador2;
   Movimiento movimiento;
   void inicializaTablero();
   void inicializaGrid();
   void inicializaMatriz();
   void iniListaCeldasDisponibles();
   void inicializaJuego();
   void inicializaJugadores();
   void realizaJugada(Jugador jugador, Celda celda);
   void manejaEstatusJuego(Jugador jugador);
   void actualizaTurno();
   Celda calculaCelda();
   void marcaCeldaTablero(Celda celda, char marca);
   void eliminaCeldaDeDisponibles(Celda celda);
   void inicializaControlesFinJuego();
   void inicializaControlesInicioJuego();

public:		// User declarations
	__fastcall TfmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmPrincipal *fmPrincipal;
//---------------------------------------------------------------------------
#endif
