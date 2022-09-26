//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlasb_xxsgrid *lasb_xxsgrid;
//---------------------------------------------------------------------------
__fastcall Tlasb_xxsgrid::Tlasb_xxsgrid(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_xxsgrid::lasb_xxsgrid_exit_cClick(TObject *Sender)
{
    lasb_xxsgrid->Close();
}
//---------------------------------------------------------------------------
