//---------------------------------------------------------------------------

#ifndef lasb_cdsnn_pH
#define lasb_cdsnn_pH
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
class Tlasb_cdsnn : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_cdsnn_xxprg_l;
        TLabel *lasb_cdsnn_firma_l;
        TDBEdit *lasb_cdsnn_firma_e;
        TButton *lasb_cdsnn_exit_c;
        TLabel *lasb_cdsnn_xxfio_l;
        TLabel *lasb_cdsnn_xxtitle_l;
        TBevel *lasb_cdsnn_1_b;
        void __fastcall lasb_cdsnn_exit_cClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_cdsnn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_cdsnn *lasb_cdsnn;
//---------------------------------------------------------------------------
#endif
