//---------------------------------------------------------------------------

#ifndef lasb_xxsgrid_pH
#define lasb_xxsgrid_pH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class Tlasb_xxsgrid : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *lasb_xxsgrid_g;
    TBitBtn *lasb_xxsgrid_exit_c;
    void __fastcall lasb_xxsgrid_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tlasb_xxsgrid(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_xxsgrid  *lasb_xxsgrid;
//---------------------------------------------------------------------------
#endif
