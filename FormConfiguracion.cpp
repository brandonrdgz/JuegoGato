//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormConfiguracion.h"
#include "FormGato.h"
#include "TipoJugador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmConfiguracion *fmConfiguracion;
//---------------------------------------------------------------------------
__fastcall TfmConfiguracion::TfmConfiguracion(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfmConfiguracion::FormClose(TObject *Sender, TCloseAction &Action) {
   actualizaConfEnBarraEstado();
}

void __fastcall TfmConfiguracion::btnAceptarClick(TObject *Sender)
{
   this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfmConfiguracion::rgTipoJugador2Click(TObject *Sender) {
   int tipoJugador = rgTipoJugador2->ItemIndex;

   if (tipoJugador == 0) {
      rgDificultad->Enabled = false;
   }
   else {
      rgDificultad->Enabled = true;
   }
}

void __fastcall TfmConfiguracion::rgMarcaJugador1Click(TObject *Sender)
{
   int marca = rgMarcaJugador1->ItemIndex;

   if (marca == 0) {
      rgMarcaJugador2->ItemIndex = 1;
   }
   else {
      rgMarcaJugador2->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfmConfiguracion::rgEmpiezaJugador1Click(TObject *Sender)
{
   int empieza = rgEmpiezaJugador1->ItemIndex;

   if (empieza == 0) {
      rgEmpiezaJugador2->ItemIndex = 1;
   }
   else {
      rgEmpiezaJugador2->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfmConfiguracion::rgMarcaJugador2Click(TObject *Sender)
{
   int marca = rgMarcaJugador2->ItemIndex;

   if (marca == 0) {
      rgMarcaJugador1->ItemIndex = 1;
   }
   else {
      rgMarcaJugador1->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfmConfiguracion::rgEmpiezaJugador2Click(TObject *Sender)
{
   int empieza = rgEmpiezaJugador2->ItemIndex;

   if (empieza == 0) {
      rgEmpiezaJugador1->ItemIndex = 1;
   }
   else {
      rgEmpiezaJugador1->ItemIndex = 0;
   }
}

void TfmConfiguracion::actualizaConfEnBarraEstado() {
   TStatusPanels *panels = fmPrincipal->sbGato->Panels;
   int iTipoJugador2 = rgTipoJugador2->ItemIndex;
   int iMarcaJugador1 = rgMarcaJugador1->ItemIndex;
   bool bEmpiezaJugador1 = rgEmpiezaJugador1->ItemIndex == 0;
   int iDificultad = rgDificultad->ItemIndex;
   String modalidadJuego;
   String marcaJugador1;
   String dificultad;
   String jugadorQueEmpieza;

   if (iTipoJugador2 == 0) {
      modalidadJuego = "Modalidad de juego: Jugador vs Jugador";
      marcaJugador1 = "";
      dificultad = "";
      jugadorQueEmpieza = "";
   }
   else {
      modalidadJuego = "Modalidad de juego: Jugador vs CPU";
      marcaJugador1 = "Marca: " + rgMarcaJugador1->Items->Strings[iMarcaJugador1];
      dificultad = "Dificultad: " + rgDificultad->Items->Strings[iDificultad];
      jugadorQueEmpieza = "Empieza: ";

      if ( bEmpiezaJugador1 == true) {
         jugadorQueEmpieza += "Jugador1";
      }
      else {
         jugadorQueEmpieza += "Jugador2";
      }
   }

   panels->Items[0]->Text = modalidadJuego;
   panels->Items[1]->Text = marcaJugador1;
   panels->Items[2]->Text = dificultad;
   panels->Items[3]->Text = jugadorQueEmpieza;
}

TipoJugador TfmConfiguracion::getTipoJugador1() {
   TipoJugador tipoJugador;
   int iTipo = rgTipoJugador1->ItemIndex;

   if (iTipo == 0) {
      tipoJugador = TipoJugador::HUMANO;
   }
   else {
      tipoJugador = TipoJugador::MAQUINA;
   }

   return tipoJugador;
}

char TfmConfiguracion::getMarcaJugador1() {
   int iMarca = rgMarcaJugador1->ItemIndex;
   char marca;

   if (iMarca == 0) {
      marca = 'X';
   }
   else {
      marca = 'O';
   }

   return marca;
}

bool TfmConfiguracion::getEmpiezaJugador1() {
   int iEmpieza = rgEmpiezaJugador1->ItemIndex;

   return iEmpieza == 0;
}

TipoJugador TfmConfiguracion::getTipoJugador2() {
   TipoJugador tipoJugador;
   int iTipo = rgTipoJugador2->ItemIndex;

   if (iTipo == 0) {
      tipoJugador = TipoJugador::HUMANO;
   }
   else {
      tipoJugador = TipoJugador::MAQUINA;
   }

   return tipoJugador;
}

char TfmConfiguracion::getMarcaJugador2() {
   int iMarca = rgMarcaJugador2->ItemIndex;
   char marca;

   if (iMarca == 0) {
      marca = 'X';
   }
   else {
      marca = 'O';
   }

   return marca;
}

bool TfmConfiguracion::getEmpiezaJugador2() {
   int iEmpieza = rgEmpiezaJugador2->ItemIndex;

   return iEmpieza == 0;
}

int TfmConfiguracion::getDificultad() {
   return rgDificultad->ItemIndex;
}
