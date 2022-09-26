//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_ksrjj_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_ksrjj *lasb_ksrjj;

//---------------------------------------------------------------------------
__fastcall Tlasb_ksrjj::Tlasb_ksrjj(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tlasb_ksrjj::lasb_ksrjj_exit_cClick(TObject *Sender)
{
  lasb_ksrjj->Close();
}
//---------------------------------------------------------------------------






