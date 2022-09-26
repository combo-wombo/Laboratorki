//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_cdstt_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_cdstt *lasb_cdstt;

//---------------------------------------------------------------------------
__fastcall Tlasb_cdstt::Tlasb_cdstt(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_cdtbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_cdstt::lasb_cdstt_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_cdtbl->Edit();
  lasb_data->lasb_cdtbl->Post();
  lasb_cdstt->Close();
}
//---------------------------------------------------------------------------





