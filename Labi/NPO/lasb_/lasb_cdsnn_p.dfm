object lasb_cdsnn: Tlasb_cdsnn
  Left = 847
  Top = 233
  Width = 871
  Height = 637
  Caption = 'lasb_cdsnn'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lasb_cdsnn_xxprg_l: TLabel
    Left = 592
    Top = 32
    Width = 73
    Height = 13
    Caption = '=lasb_cdsnn='
  end
  object lasb_cdsnn_firma_l: TLabel
    Left = 80
    Top = 160
    Width = 81
    Height = 13
    Caption = 'Lasb_название фирмы'
  end
  object lasb_cdsnn_xxfio_l: TLabel
    Left = 24
    Top = 32
    Width = 63
    Height = 13
    Caption = '=Луд А.С.='
  end
  object lasb_cdsnn_xxtitle_l: TLabel
    Left = 264
    Top = 88
    Width = 101
    Height = 13
    Caption = 'lasb_настройка АРМа'
  end
  object lasb_cdsnn_1_b: TBevel
    Left = 48
    Top = 144
    Width = 537
    Height = 73
  end
  object lasb_cdsnn_firma_e: TDBEdit
    Left = 256
    Top = 160
    Width = 121
    Height = 21
    DataField = 'lasb_cd_firma'
    DataSource = lasb_data.lasb_cdds
    TabOrder = 0
  end
  object lasb_cdsnn_exit_c: TButton
    Left = 568
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Выход'
    TabOrder = 1
    OnClick = lasb_cdsnn_exit_cClick
  end
end
