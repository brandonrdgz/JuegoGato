#include <vcl.h>
#pragma hdrstop
#include <tchar.h>

#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("FormConfiguracion.cpp", fmConfiguracion);
USEFORM("FormGato.cpp", fmPrincipal);

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Windows10 Dark");
      Application->CreateForm(__classid(TfmPrincipal), &fmPrincipal);
      Application->CreateForm(__classid(TfmConfiguracion), &fmConfiguracion);
      Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
