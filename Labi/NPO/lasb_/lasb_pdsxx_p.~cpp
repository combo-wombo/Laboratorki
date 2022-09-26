//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_pdsxx_p.h"
#include "lasb_xxsgrid_p.h"
#include "lasb_togxx_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_pdsxx *lasb_pdsxx;

//---------------------------------------------------------------------------
__fastcall Tlasb_pdsxx::Tlasb_pdsxx(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_pdtbl->Active=true;
  lasb_data->lasb_toqoo->SQL->Add("where lasb_to_dokk=:lasb_to_dokk");
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_grid_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_pdds;
  lasb_xxsgrid->Caption="lasb_pdsxx  viberi dokument ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_back_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Prior();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_next_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_add_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Active=true;
  lasb_data->lasb_pdtbl->Append();
  lasb_data->lasb_pdtbl->Edit();

  lasb_data->lasb_cdtbl->Active=true;
  lasb_data->lasb_pdtbl->Edit();
  lasb_pdsxx->lasb_pdsxx_dokd_e->Text =
        lasb_data->lasb_cdds->DataSet->FieldByName("lasb_cd_datat")->AsDateTime;
  lasb_data->lasb_pdtbl->Post();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Edit();
  lasb_data->lasb_pdtbl->Post();
  lasb_pdsxx->Close();
}
//---------------------------------------------------------------------------



void __fastcall Tlasb_pdsxx::lasb_pdsxx_pdtrj_cClick(TObject *Sender)
{
        lasb_data->lasb_pdtbl->Active=true;
        lasb_data->lasb_pdtbl->Active=true;


        lasb_data->lasb_rjtbl->Active=false;
        lasb_data->lasb_rjtbl->Active=true;
        lasb_data->lasb_rjtbl->Last();

//---------------

        lasb_data->lasb_rjtbl->Append(); 
	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_0")->AsString= "0";

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_data")->AsDateTime=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dokd")->AsDateTime;

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokk")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dokk")->AsString;
	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokn")->Value=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dokn")->Value;
	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokd")->AsDateTime=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dokd")->AsDateTime;

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_to")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_to")->AsString;

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_db")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_db")->AsString;
	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dbn")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dbn")->AsString;

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_kr")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_kr")->AsString;
	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_krn")->AsString=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_krn")->AsString;

	lasb_data->lasb_rjtbl->FieldByName("lasb_rj_rub")->Value=
           lasb_data->lasb_pdtbl->FieldByName("lasb_pd_rub")->Value;

        lasb_data->lasb_rjtbl->Post();
//        lasb_rjtbl->Active=false;

}
//---------------------------------------------------------------------------

void __fastcall Tlasb_pdsxx::lasb_tosxx_to_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Active = true;  
  lasb_data->lasb_toqoo->Close();

  AnsiString lasb_to_dokk = lasb_pdsxx->lasb_pdsxx_dokk_e->Text;
  lasb_data->lasb_toqoo->ParamByName("lasb_to_dokk")->AsString = lasb_to_dokk;

  lasb_data->lasb_toqoo->Open();

  lasb_togxx->lasb_togxx_g->DataSource = lasb_data->lasb_toqds;
  lasb_togxx->Caption="-lasb_pdsxx   viberi operaciu ";

  lasb_togxx->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_pdsxx::lasb_pdsxx_del_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Delete();
  lasb_data->lasb_pdtbl->Edit();
}


