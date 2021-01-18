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


void __fastcall TfmConfiguracion::btnAceptarClick(TObject *Sender)
{
   this->Close();
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------
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
