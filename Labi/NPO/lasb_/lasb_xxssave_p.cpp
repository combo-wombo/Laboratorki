//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_xxssave_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_xxssave *lasb_xxssave;

//---------------------------------------------------------------------------
__fastcall Tlasb_xxssave::Tlasb_xxssave(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tlasb_xxssave::lasb_xxssave_exit_cClick(TObject *Sender)
{
  lasb_xxssave->Close();
}
//---------------------------------------------------------------------------






