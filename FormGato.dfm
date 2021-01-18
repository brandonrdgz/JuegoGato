object fmPrincipal: TfmPrincipal
  Left = 0
  Top = 0
  Caption = 'Gato'
  ClientHeight = 329
  ClientWidth = 518
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = mmPrincipal
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LabelTextoTurno: TLabel
    Left = 184
    Top = 8
    Width = 49
    Height = 19
    Caption = 'Turno:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelTurno: TLabel
    Left = 236
    Top = 8
    Width = 5
    Height = 19
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Tablero: TStringGrid
    Left = 144
    Top = 31
    Width = 242
    Height = 242
    ColCount = 3
    DefaultColWidth = 78
    DefaultRowHeight = 78
    DrawingStyle = gdsClassic
    Enabled = False
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 0
    OnDrawCell = TableroDrawCell
    OnSelectCell = TableroSelectCell
  end
  object btnJugar: TButton
    Left = 158
    Top = 279
    Width = 75
    Height = 25
    Caption = 'Jugar'
    TabOrder = 1
    OnClick = btnJugarClick
  end
  object ButtonTerminar: TButton
    Left = 302
    Top = 279
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 2
    OnClick = ButtonTerminarClick
  end
  object sbGato: TStatusBar
    Left = 0
    Top = 310
    Width = 518
    Height = 19
    Panels = <
      item
        Text = 'Modalidad de Juego: Jugador vs CPU'
        Width = 230
      end
      item
        Text = 'Simbolo: X'
        Width = 70
      end
      item
        Text = 'Dificultad: Media'
        Width = 100
      end
      item
        Text = 'Empieza: Jugador'
        Width = 50
      end>
  end
  object mmPrincipal: TMainMenu
    Left = 56
    Top = 96
    object miConfiguracion: TMenuItem
      Caption = 'Configuraci'#243'n'
      OnClick = miConfiguracionClick
    end
    object miAcercaDe: TMenuItem
      Caption = 'Acerca de'
      OnClick = miAcercaDeClick
    end
  end
end
