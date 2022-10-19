//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_cdsff_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_cdsff *lasb_cdsff;
//---------------------------------------------------------------------------
__fastcall Tlasb_cdsff::Tlasb_cdsff(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_cdtbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_cdsff::lasb_cdsff_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_cdtbl->Edit();
  lasb_data->lasb_cdtbl->Post();
  lasb_cdsff->Close();
}
//---------------------------------------------------------------------------




