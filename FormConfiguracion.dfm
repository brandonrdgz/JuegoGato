object fmConfiguracion: TfmConfiguracion
  Left = 0
  Top = 0
  Caption = 'Configuraci'#243'n'
  ClientHeight = 297
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 80
    Height = 19
    Caption = 'Jugador 1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 128
    Top = 8
    Width = 80
    Height = 19
    Caption = 'Jugador 2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object rgDificultad: TRadioGroup
    Left = 243
    Top = 34
    Width = 113
    Height = 105
    Caption = 'Dificultad'
    ItemIndex = 1
    Items.Strings = (
      'Baja'
      'Media'
      'Alta')
    TabOrder = 0
  end
  object btnAceptar: TButton
    Left = 281
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = btnAceptarClick
  end
  object rgMarcaJugador1: TRadioGroup
    Left = 8
    Top = 104
    Width = 89
    Height = 64
    Caption = 'Marca'
    ItemIndex = 0
    Items.Strings = (
      'X'
      'O')
    TabOrder = 2
    OnClick = rgMarcaJugador1Click
  end
  object rgMarcaJugador2: TRadioGroup
    Left = 128
    Top = 104
    Width = 89
    Height = 64
    Caption = 'Marca'
    ItemIndex = 1
    Items.Strings = (
      'X'
      'O')
    TabOrder = 3
    OnClick = rgMarcaJugador2Click
  end
  object rgEmpiezaJugador1: TRadioGroup
    Left = 8
    Top = 191
    Width = 89
    Height = 65
    Caption = 'Empieza Juego'
    ItemIndex = 0
    Items.Strings = (
      'SI'
      'NO')
    TabOrder = 4
    OnClick = rgEmpiezaJugador1Click
  end
  object rgTipoJugador1: TRadioGroup
    Left = 8
    Top = 34
    Width = 89
    Height = 64
    Caption = 'Tipo'
    Enabled = False
    ItemIndex = 0
    Items.Strings = (
      'HUMANO'
      'MAQUINA')
    TabOrder = 5
  end
  object rgTipoJugador2: TRadioGroup
    Left = 128
    Top = 34
    Width = 89
    Height = 64
    Caption = 'Tipo'
    ItemIndex = 1
    Items.Strings = (
      'HUMANO'
      'MAQUINA')
    TabOrder = 6
    OnClick = rgTipoJugador2Click
  end
  object rgEmpiezaJugador2: TRadioGroup
    Left = 128
    Top = 191
    Width = 89
    Height = 65
    Caption = 'Empieza Juego'
    ItemIndex = 1
    Items.Strings = (
      'SI'
      'NO')
    TabOrder = 7
    OnClick = rgEmpiezaJugador2Click
  end
end
