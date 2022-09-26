//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_togxx_p.h"
#include "lasb_pdsxx_p.h"
#include "lasb_tosxx_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlasb_togxx *lasb_togxx;
//---------------------------------------------------------------------------
__fastcall Tlasb_togxx::Tlasb_togxx(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_togxx::lasb_togxx_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_pdtbl->Active=true;
  lasb_data->lasb_totbl->Active=true;

  lasb_data->lasb_pdtbl->Edit();


  lasb_data->lasb_pdtbl->FieldByName("lasb_pd_to")->AsString=
     lasb_data->lasb_toqds->DataSet->FieldByName("lasb_to_k")->AsString;

  lasb_data->lasb_pdtbl->FieldByName("lasb_pd_db")->AsString=
     lasb_data->lasb_toqds->DataSet->FieldByName("lasb_to_db")->AsString;
  lasb_data->lasb_pdtbl->FieldByName("lasb_pd_dbn")->AsString=
     lasb_data->lasb_toqds->DataSet->FieldByName("lasb_to_dbn")->AsString;

  lasb_data->lasb_pdtbl->FieldByName("lasb_pd_kr")->AsString=
     lasb_data->lasb_toqds->DataSet->FieldByName("lasb_to_kr")->AsString;
  lasb_data->lasb_pdtbl->FieldByName("lasb_pd_krn")->AsString=
     lasb_data->lasb_toqds->DataSet->FieldByName("lasb_to_krn")->AsString;


  lasb_data->lasb_pdtbl->Post();
  lasb_togxx->Close();
}
//---------------------------------------------------------------------------
