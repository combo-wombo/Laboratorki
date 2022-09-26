//---------------------------------------------------------------------------

#ifndef lasb_cdsff_pH
#define lasb_cdsff_pH
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
class Tlasb_cdsff : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_cdsff_xxprg_l;
        TButton *lasb_cdsff_exit_c;
        TLabel *lasb_cdsff_xxlas_l;
        TLabel *lasb_cdsff_xxtitle_l;
        TBevel *lasb_cdsff_1_b;
        TLabel *lasb_cdsff_datas_l;
        TLabel *lasb_cdsff_datad_l;
        TDBEdit *lasb_cdsff_datas_e;
        TDBEdit *lasb_cdsff_datad_e;
        TDBEdit *lasb_cdsff_s_e;
        TLabel *lasb_cdsff_s_l;
        void __fastcall lasb_cdsff_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_cdsff(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_cdsff *lasb_cdsff;
//---------------------------------------------------------------------------
#endif
