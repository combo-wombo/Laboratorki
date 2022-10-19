//---------------------------------------------------------------------------

#ifndef lasb_xxsrest_pH
#define lasb_xxsrest_pH
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
class Tlasb_xxsrest : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_xxsrest_xxprg_l;
        TButton *lasb_xxsrest_exit_c;
        TLabel *lasb_xxsrest_xxlas_l;
        TLabel *lasb_xxsrest_xxtitle_l;
        void __fastcall lasb_xxsrest_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_xxsrest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_xxsrest *lasb_xxsrest;
//---------------------------------------------------------------------------
#endif
