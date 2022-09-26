//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_xxsrest_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_xxsrest *lasb_xxsrest;

//---------------------------------------------------------------------------
__fastcall Tlasb_xxsrest::Tlasb_xxsrest(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tlasb_xxsrest::lasb_xxsrest_exit_cClick(TObject *Sender)
{
  lasb_xxsrest->Close();
}
//---------------------------------------------------------------------------






