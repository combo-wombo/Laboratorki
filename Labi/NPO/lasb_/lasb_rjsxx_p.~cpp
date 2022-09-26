//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_rjsxx_p.h"
#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_rjsxx *lasb_rjsxx;

//---------------------------------------------------------------------------
__fastcall Tlasb_rjsxx::Tlasb_rjsxx(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_rjtbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_grid_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_rjds;
  lasb_xxsgrid->Caption="lasb_rjsxx  viberi dokument ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_back_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Prior();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_next_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_add_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Active=true;
  lasb_data->lasb_rjtbl->Append();
  lasb_data->lasb_rjtbl->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_del_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Delete();
  lasb_data->lasb_rjtbl->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjsxx::lasb_rjsxx_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Edit();
  lasb_data->lasb_rjtbl->Post();
  lasb_rjsxx->Close();
}
//---------------------------------------------------------------------------



