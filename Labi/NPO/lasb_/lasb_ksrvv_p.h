//---------------------------------------------------------------------------

#ifndef lasb_ksrvv_pH
#define lasb_ksrvv_pH
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
class Tlasb_ksrvv : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_ksrvv_xxprg_l;
        TButton *lasb_ksrvv_exit_c;
        TLabel *lasb_ksrvv_xxlas_l;
        TLabel *lasb_ksrvv_xxtitle_l;
        void __fastcall lasb_ksrvv_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_ksrvv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_ksrvv *lasb_ksrvv;
//---------------------------------------------------------------------------
#endif
