//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_kssrr_p.h"
#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_kssrr *lasb_kssrr;

//---------------------------------------------------------------------------
__fastcall Tlasb_kssrr::Tlasb_kssrr(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_kstbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_kssrr::lasb_kssrr_grid_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_ksds;
  lasb_xxsgrid->Caption="lasb_kssrr  viberi dokument ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_kssrr::lasb_kssrr_back_cClick(TObject *Sender)
{
  lasb_data->lasb_kstbl->Prior();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_kssrr::lasb_kssrr_next_cClick(TObject *Sender)
{
  lasb_data->lasb_kstbl->Next();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_kssrr::lasb_kssrr_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_kstbl->Edit();
  lasb_data->lasb_kstbl->Post();
  lasb_kssrr->Close();
}
//---------------------------------------------------------------------------


