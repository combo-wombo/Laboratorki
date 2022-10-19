//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_tosxx_p.h"
#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_tosxx *lasb_tosxx;

//---------------------------------------------------------------------------
__fastcall Tlasb_tosxx::Tlasb_tosxx(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_totbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_grid_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_tods;
  lasb_xxsgrid->Caption="lasb_tosxx  viberi operaciu ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_back_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Prior();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_next_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_add_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Active=true;
  lasb_data->lasb_totbl->Append();
  lasb_data->lasb_totbl->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_del_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Delete();
  lasb_data->lasb_totbl->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_tosxx::lasb_tosxx_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_totbl->Edit();
  lasb_data->lasb_totbl->Post();
  lasb_tosxx->Close();
}
//---------------------------------------------------------------------------

