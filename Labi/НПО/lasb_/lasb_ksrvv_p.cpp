//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_ksrvv_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_ksrvv *lasb_ksrvv;

//---------------------------------------------------------------------------
__fastcall Tlasb_ksrvv::Tlasb_ksrvv(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tlasb_ksrvv::lasb_ksrvv_exit_cClick(TObject *Sender)
{
  lasb_ksrvv->Close();
}
//---------------------------------------------------------------------------






