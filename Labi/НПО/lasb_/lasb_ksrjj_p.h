//---------------------------------------------------------------------------

#ifndef lasb_ksrjj_pH
#define lasb_ksrjj_pH
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
class Tlasb_ksrjj : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_ksrjj_xxprg_l;
        TButton *lasb_ksrjj_exit_c;
        TLabel *lasb_ksrjj_xxlas_l;
        TLabel *lasb_ksrjj_xxtitle_l;
        void __fastcall lasb_ksrjj_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_ksrjj(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_ksrjj *lasb_ksrjj;
//---------------------------------------------------------------------------
#endif
