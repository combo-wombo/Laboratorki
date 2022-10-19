//---------------------------------------------------------------------------

#ifndef lasb_kssrr_pH
#define lasb_kssrr_pH
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
class Tlasb_kssrr : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_kssrr_xxlas_l;
        TLabel *lasb_kssrr_xxprg_l;
        TLabel *lasb_kssrr_xxtitle_l;

        TDBEdit *lasb_kssrr_dokk_e;
        TLabel *lasb_kssrr_dokk_l;
        TBevel *lasb_kssrr_b1;

        TButton *lasb_kssrr_grid_c;
        TButton *lasb_kssrr_back_c;
        TButton *lasb_kssrr_next_c;
        TButton *lasb_kssrr_exit_c;
        TLabel *lasb_kssrr_s_l;
        TLabel *lasb_kssrr_ks_l;
        TDBEdit *lasb_kssrr_to_e;
        TDBEdit *lasb_kssrr_s_e;
        TDBEdit *lasb_kssrr_sn_e;
        TDBEdit *lasb_kssrr_ksn_e;
        TDBEdit *lasb_kssrr_dokn_e;
        TLabel *lasb_kssrr_dokd_l;
        TDBEdit *lasb_kssrr_dokd_e;
        TDBEdit *lasb_kssrr_data_e;
        TLabel *lasb_kssrr_rubkr_l;
        TDBEdit *fiof_kssrr_rubkr_e;

        void __fastcall lasb_kssrr_grid_cClick(TObject *Sender);
        void __fastcall lasb_kssrr_back_cClick(TObject *Sender);
        void __fastcall lasb_kssrr_next_cClick(TObject *Sender);
        void __fastcall lasb_kssrr_exit_cClick(TObject *Sender);
 
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_kssrr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_kssrr *lasb_kssrr;
//---------------------------------------------------------------------------
#endif

