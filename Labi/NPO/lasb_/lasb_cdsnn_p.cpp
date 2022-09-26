//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_cdsnn_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlasb_cdsnn *lasb_cdsnn;
//---------------------------------------------------------------------------
__fastcall Tlasb_cdsnn::Tlasb_cdsnn(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_cdtbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_cdsnn::lasb_cdsnn_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_cdtbl->Edit();
  lasb_data->lasb_cdtbl->Post();
  lasb_cdsnn->Close();
}
//---------------------------------------------------------------------------

