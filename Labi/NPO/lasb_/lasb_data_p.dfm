�
 TLASB_DATA 0�  TPF0
Tlasb_data	lasb_dataLeft�Top�Width�Height�Caption	lasb_dataColor	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OldCreateOrderScaledPixelsPerInch`
TextHeight 	TDatabase	lasb_data	AliasNamelasbDatabaseName	lasb_dataSessionNameDefaultLeft Top  TTable
lasb_totblDatabaseName	lasb_data	TableName
lasb_to.DBLeft� Top  TTable
lasb_pdtblDatabaseName	lasb_data	TableName
lasb_pd.DBLeftHTop  TTable
lasb_rjtblDatabaseName	lasb_data	TableName
lasb_rj.DBLeft�Top  TTable
lasb_kstblDatabaseName	lasb_data	TableName
lasb_ks.DBLeftTop  TTable
lasb_cdtblDatabaseName	lasb_data	TableName
lasb_cd.DBLeftXTop  TDataSource	lasb_cddsDataSet
lasb_cdtblLeftxTop  TDataSource	lasb_todsDataSet
lasb_totblLeft� Top  TDataSource	lasb_pddsDataSet
lasb_pdtblLefthTop  TDataSource	lasb_rjdsDataSet
lasb_rjtblLeft�Top  TDataSource	lasb_ksdsDataSet
lasb_kstblLeft0Top  TQuery
lasb_ksqooAutoRefresh	DatabaseName	lasb_data
DataSource	lasb_ksdsSQL.StringswSELECT * FROM lasb_ks.db, lasb_cd.db WHERE lasb_ks_s=lasb_cd_s AND lasb_ks_data between lasb_cd_datas AND lasb_cd_datad Left`TopX  TDataSource
lasb_ksqdsDataSet
lasb_ksqooLeft� TopX  TQuery
lasb_toqooDatabaseName	lasb_data
DataSource	lasb_todsSQL.Stringsselect * from lasb_to.db Left� TopX  TDataSource
lasb_toqdsDataSet
lasb_toqooLeft� TopX   