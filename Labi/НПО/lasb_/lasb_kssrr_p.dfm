object lasb_kssrr: Tlasb_kssrr
  Left = 587
  Top = 155
  Width = 967
  Height = 618
  Caption = 'lasb_kssrr'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clRed
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = lasb_kssrr_next_cClick
  PixelsPerInch = 96
  TextHeight = 13
  object lasb_kssrr_xxprg_l: TLabel
    Left = 592
    Top = 32
    Width = 66
    Height = 13
    Caption = '=lasb_kssrr='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lasb_kssrr_xxlas_l: TLabel
    Left = 24
    Top = 32
    Width = 63
    Height = 13
    Caption = '=Луд А.С.='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lasb_kssrr_xxtitle_l: TLabel
    Left = 256
    Top = 72
    Width = 122
    Height = 13
    Caption = 'lasb_книга счетов(КС)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lasb_kssrr_dokk_l: TLabel
    Left = 80
    Top = 152
    Width = 73
    Height = 13
    Caption = 'lasb_документ'
  end
  object lasb_kssrr_b1: TBevel
    Left = 40
    Top = 96
    Width = 609
    Height = 249
  end
  object lasb_kssrr_to_l: TLabel
    Left = 80
    Top = 208
    Width = 67
    Height = 13
    Caption = 'lasb_операция'
  end
  object lasb_kssrr_s_l: TLabel
    Left = 128
    Top = 256
    Width = 52
    Height = 13
    Caption = 'lasb_счет'
  end
  object lasb_kssrr_ks_l: TLabel
    Left = 392
    Top = 256
    Width = 74
    Height = 13
    Caption = 'lasb_Корр счет'
  end
  object lasb_kssrr_dokd_l: TLabel
    Left = 352
    Top = 152
    Width = 9
    Height = 13
    Caption = 'от'
  end
  object lasb_kssrr_rubdb_l: TLabel
    Left = 88
    Top = 312
    Width = 77
    Height = 13
    Caption = 'lasb_сумма ДБ'
  end
  object lasb_kssrr_data_l: TLabel
    Left = 80
    Top = 112
    Width = 87
    Height = 13
    Caption = 'lasb_дата операции'
  end
  object lasb_kssrr_rubkr_l: TLabel
    Left = 320
    Top = 312
    Width = 77
    Height = 13
    Caption = 'lasb_сумма КР'
  end
  object lasb_kssrr_exit_c: TButton
    Left = 576
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Выход'
    TabOrder = 0
    OnClick = lasb_kssrr_exit_cClick
  end
  object lasb_kssrr_dokk_e: TDBEdit
    Left = 176
    Top = 144
    Width = 65
    Height = 21
    DataField = 'lasb_ks_dokk'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 1
  end
  object lasb_kssrr_back_c: TButton
    Left = 104
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Назад'
    TabOrder = 2
    OnClick = lasb_kssrr_back_cClick
  end
  object lasb_kssrr_next_c: TButton
    Left = 192
    Top = 397
    Width = 75
    Height = 25
    Caption = 'Вперед'
    TabOrder = 3
    OnClick = lasb_kssrr_next_cClick
  end
  object lasb_kssrr_grid_c: TButton
    Left = 24
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Выбрать'
    TabOrder = 4
    OnClick = lasb_kssrr_grid_cClick
  end
  object lasb_kssrr_to_e: TDBEdit
    Left = 176
    Top = 208
    Width = 121
    Height = 21
    DataField = 'lasb_ks_to'
    DataSource = lasb_data.lasb_ksds
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
  end
  object lasb_kssrr_s_e: TDBEdit
    Left = 184
    Top = 248
    Width = 41
    Height = 21
    DataField = 'lasb_ks_s'
    DataSource = lasb_data.lasb_ksds
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
  end
  object lasb_kssrr_sn_e: TDBEdit
    Left = 232
    Top = 248
    Width = 121
    Height = 21
    DataField = 'lasb_ks_sn'
    DataSource = lasb_data.lasb_ksds
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
  end
  object lasb_kssrr_kr_e: TDBEdit
    Left = 464
    Top = 248
    Width = 41
    Height = 21
    DataField = 'lasb_ks_ks'
    DataSource = lasb_data.lasb_ksds
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
  end
  object lasb_kssrr_ksn_e: TDBEdit
    Left = 512
    Top = 248
    Width = 121
    Height = 21
    DataField = 'lasb_ks_ksn'
    DataSource = lasb_data.lasb_ksds
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
  end
  object lasb_kssrr_dokn_e: TDBEdit
    Left = 248
    Top = 144
    Width = 81
    Height = 21
    DataField = 'lasb_ks_dokn'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 11
  end
  object lasb_kssrr_dokd_e: TDBEdit
    Left = 376
    Top = 144
    Width = 81
    Height = 21
    DataField = 'lasb_ks_dokd'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 13
  end
  object lasb_kssrr_rubdb_e: TDBEdit
    Left = 176
    Top = 304
    Width = 121
    Height = 21
    DataField = 'lasb_ks_rubdb'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 10
  end
  object lasb_kssrr_data_e: TDBEdit
    Left = 176
    Top = 112
    Width = 81
    Height = 21
    DataField = 'lasb_ks_data'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 12
  end
  object fiof_kssrr_rubkr_e: TDBEdit
    Left = 400
    Top = 304
    Width = 121
    Height = 21
    DataField = 'lasb_ks_rubkr'
    DataSource = lasb_data.lasb_ksds
    TabOrder = 14
  end
end
