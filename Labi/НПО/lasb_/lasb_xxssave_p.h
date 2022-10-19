//---------------------------------------------------------------------------

#ifndef lasb_xxssave_pH
#define lasb_xxssave_pH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tlasb_xxssave : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_xxssave_xxprg_l;
        TButton *lasb_xxssave_exit_c;
        TLabel *lasb_xxssave_xxlas_l;
        TLabel *lasb_xxssave_xxtitle_l;
        void __fastcall lasb_xxssave_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_xxssave(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_xxssave *lasb_xxssave;
//---------------------------------------------------------------------------
#endif
