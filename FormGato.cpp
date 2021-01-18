//---------------------------------------------------------------------------

#include <vcl.h>
#include <climits>
#include <string.h>
#pragma hdrstop

#include "FormGato.h"
#include "Celda.h"
#include "IAGato.h"
#include "Turno.h"
#include "FormConfiguracion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define VACIO ""

TfmPrincipal *fmPrincipal;
//---------------------------------------------------------------------------
__fastcall TfmPrincipal::TfmPrincipal(TComponent* Owner)
	: TForm(Owner)
{
   filas = Tablero->RowCount;
   columnas = Tablero->ColCount;
   tablero = new char*[filas];

   for (int fila = 0; fila < filas; fila++) {
      tablero[fila] = new char[columnas];
   }
}
//---------------------------------------------------------------------------

void TfmPrincipal::inicializaTablero() {
   inicializaGrid();
   inicializaMatriz();
   iniListaCeldasDisponibles();
}

void TfmPrincipal::inicializaGrid() {   
   for (int fila = 0; fila < filas; fila++) {
      for (int columna = 0; columna < columnas; columna++) {
         Tablero->Cells[columna][fila] = VACIO;
      }
   }
}

void TfmPrincipal::inicializaMatriz() {
   for (int fila = 0; fila < filas; fila++) {
      for (int columna = 0; columna < columnas; columna++) {
         tablero[fila][columna] = CHAR_MIN;
      }
   }
}

void TfmPrincipal::iniListaCeldasDisponibles() {
   listaCeldasDisponibles.clear();
   
   for (int fila = 0; fila < filas; fila++) {
      for (int columna = 0; columna < columnas; columna++) {
         listaCeldasDisponibles.push_back(Celda(fila, columna));
      }
   }
}

void TfmPrincipal::inicializaJuego() {
   inicializaTablero();
   inicializaJugadores();

   if (jugador1.getIniciaJuego()) {
      jugadorActual = jugador1;
   }
   else {
      jugadorActual = jugador2;
   }

   if (jugadorActual.getTipoJugador() == TipoJugador::MAQUINA) {
      realizaJugada(jugadorActual, Celda(-1, -1));
   }
}

void TfmPrincipal::inicializaJugadores() {
   jugador1.setTipoJugador(fmConfiguracion->getTipoJugador1());
   jugador1.setMarca(fmConfiguracion->getMarcaJugador1());
   jugador1.setIniciaJuego(fmConfiguracion->getEmpiezaJugador1());

   jugador2.setTipoJugador(fmConfiguracion->getTipoJugador2());
   jugador2.setMarca(fmConfiguracion->getMarcaJugador2());
   jugador2.setIniciaJuego(fmConfiguracion->getEmpiezaJugador2());
}

void TfmPrincipal::realizaJugada(Jugador jugador, Celda celda) {
   if (jugador.getTipoJugador() == TipoJugador::MAQUINA) {
      celda = calculaCelda();
   }

   marcaCeldaTablero(celda, jugador.getMarca());
   manejaEstatusJuego(jugador);
}

void TfmPrincipal::manejaEstatusJuego(Jugador jugador) {
   bool jugadaExitosa = IAGato::esGanador(tablero, jugador.getMarca());
   String mensaje;

   if (jugadaExitosa == true) {
      mensaje = "El jugador " + IntToStr(jugador.getId()) + " es el ganador.";
   }
   else if (listaCeldasDisponibles.empty() == true) {
      mensaje = "Es un empate.";
   }
   else {
      mensaje = "";
   }

   if (mensaje != "") {
      ShowMessage(mensaje);
      inicializaTablero();
      inicializaControlesFinJuego();
   }   
   else {
      actualizaTurno();      
   }
}

void TfmPrincipal::actualizaTurno() {
   if (jugadorActual.getId() == 1) {
      jugadorActual = jugador2;
   }
   else {
      jugadorActual = jugador1;
   }
}

Celda TfmPrincipal::calculaCelda() {
   movimiento = IAGato::mejorMovimiento(
      filas,
      columnas,
      tablero,
      jugador2.getMarca(),
      jugador1.getMarca(),
      fmConfiguracion->getDificultad()
   );

   return movimiento.getCelda();
}

void TfmPrincipal::marcaCeldaTablero(Celda celda, char marca) {
   tablero[celda.getFila()][celda.getColumna()] = marca;
   Tablero->Cells[celda.getColumna()][celda.getFila()] = marca;
   eliminaCeldaDeDisponibles(celda);
}

void TfmPrincipal::eliminaCeldaDeDisponibles(Celda celda) {
   for (int i = 0; i < listaCeldasDisponibles.size(); i++) {
      if (
         listaCeldasDisponibles[i].getFila() == celda.getFila() &&
         listaCeldasDisponibles[i].getColumna() == celda.getColumna()
      ) {
         listaCeldasDisponibles.erase(listaCeldasDisponibles.begin() + i);
      }
   }
}

void __fastcall TfmPrincipal::TableroSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{

	String valorCelda = Tablero->Cells[ACol][ARow];

	if(valorCelda != VACIO) {
      return;
   }

   realizaJugada(jugadorActual, Celda(ARow, ACol));

   if (jugadorActual.getTipoJugador() == TipoJugador::MAQUINA) {
      realizaJugada(jugadorActual, Celda(-1, -1));
   }
}
//---------------------------------------------------------------------------
void __fastcall TfmPrincipal::btnJugarClick(TObject *Sender)
{
   inicializaControles();
   inicializaJuego();
}
//---------------------------------------------------------------------------

void __fastcall TfmPrincipal::miAcercaDeClick(TObject *Sender)
{
   Application->MessageBox(L"Instituto Tecnológico de Toluca\nMateria: Simulación\n\
Profesora: Maribel Miranda Estevez\nAlumno: Brandon Ivan Rodriguez Duarte\n\
Proyecto: Juego del gato\nSemestre: AGOSTO-DICIEMBRE 2020", L"Acerca de", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TfmPrincipal::ButtonTerminarClick(TObject *Sender)
{
   Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TfmPrincipal::miConfiguracionClick(TObject *Sender)
{
   fmConfiguracion->Show();
}
//---------------------------------------------------------------------------

void TfmPrincipal::inicializaControlesFinJuego() {
   btnJugar->Enabled = true;
   miConfiguracion->Enabled = true;
   LabelTurno->Caption = "";
   Tablero->Enabled = false;
}

void TfmPrincipal::inicializaControlesInicioJuego() {
   Tablero->Enabled = true;
   btnJugar->Enabled = false;
   miConfiguracion->Enabled = false;
}

//Centrar el texto de la celdas
void __fastcall TfmPrincipal::TableroDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
   Tablero->Canvas->FillRect(Rect);
   AnsiString texto(Tablero->Cells[ACol][ARow]);
   wchar_t *dest = new wchar_t[2];
   RECT RText = static_cast<RECT>(Rect);
   InflateRect(&RText, -3, -3);

   DrawText(Tablero->Canvas->Handle, texto.WideChar(dest, 2), texto.Length(), &Rect,
      DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//---------------------------------------------------------------------------
void __fastcall TfmPrincipal::FormShow(TObject *Sender)
{
   jugador1 = Jugador(
      1,
      fmConfiguracion->getTipoJugador1(),
      fmConfiguracion->getMarcaJugador1(),
      fmConfiguracion->getEmpiezaJugador1()
   );
   
   jugador2 = Jugador(
      2,
      fmConfiguracion->getTipoJugador2(),
      fmConfiguracion->getMarcaJugador2(),
      fmConfiguracion->getEmpiezaJugador2()
   );   
}
//---------------------------------------------------------------------------
