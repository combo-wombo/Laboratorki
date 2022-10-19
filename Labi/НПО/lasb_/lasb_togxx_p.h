//---------------------------------------------------------------------------

#ifndef lasb_togxx_pH
#define lasb_togxx_pH
#define lasb_pdsxx_pH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class Tlasb_togxx : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *lasb_togxx_g;
    TBitBtn *lasb_togxx_exit_c;
    void __fastcall lasb_togxx_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tlasb_togxx(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_togxx  *lasb_togxx;
//---------------------------------------------------------------------------
#endif
