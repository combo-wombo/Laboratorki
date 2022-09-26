//---------------------------------------------------------------------------

#ifndef lasb_cdstt_pH
#define lasb_cdstt_pH
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
class Tlasb_cdstt : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_cdstt_xxprg_l;
        TLabel *lasb_cdstt_datat_l;
        TDBEdit *lasb_cdstt_datat_e;
        TButton *lasb_cdstt_exit_c;
        TLabel *lasb_cdstt_xxlas_l;
        TLabel *lasb_cdstt_xxtitle_l;
        TBevel *lasb_cdstt_1_b;
        void __fastcall lasb_cdstt_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_cdstt(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_cdstt *lasb_cdstt;
//---------------------------------------------------------------------------
#endif

