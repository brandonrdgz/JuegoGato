//---------------------------------------------------------------------------

#ifndef FormConfiguracionH
#define FormConfiguracionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TipoJugador.h"
//---------------------------------------------------------------------------
class TfmConfiguracion : public TForm
{
__published:	// IDE-managed Components
   TRadioGroup *rgDificultad;
   TButton *btnAceptar;
   TRadioGroup *rgMarcaJugador1;
   TRadioGroup *rgMarcaJugador2;
   TLabel *Label1;
   TLabel *Label2;
   TRadioGroup *rgEmpiezaJugador1;
   TRadioGroup *rgTipoJugador1;
   TRadioGroup *rgTipoJugador2;
   TRadioGroup *rgEmpiezaJugador2;
   void __fastcall btnAceptarClick(TObject *Sender);
   void __fastcall rgMarcaJugador1Click(TObject *Sender);
   void __fastcall rgEmpiezaJugador1Click(TObject *Sender);
   void __fastcall rgMarcaJugador2Click(TObject *Sender);
   void __fastcall rgEmpiezaJugador2Click(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall rgTipoJugador2Click(TObject *Sender);
private:	// User declarations
   int modalidad;
   int simbolo;
	int dificultad;
	bool turnoHumano;
   void actualizaConfEnBarraEstado();
public:		// User declarations
   __fastcall TfmConfiguracion(TComponent* Owner);
   TipoJugador getTipoJugador1();
   char getMarcaJugador1();
   bool getEmpiezaJugador1();
   TipoJugador getTipoJugador2();
   char getMarcaJugador2();
   bool getEmpiezaJugador2();
   int getDificultad();
};
//---------------------------------------------------------------------------
extern PACKAGE TfmConfiguracion *fmConfiguracion;
//---------------------------------------------------------------------------
#endif
