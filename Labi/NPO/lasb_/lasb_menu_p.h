//---------------------------------------------------------------------------

#ifndef lasb_menu_pH
#define lasb_menu_pH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include <DBGrids.hpp>
#include <Grids.hpp>
//#include <Menus.hpp>

#include "lasb_menu_p.h"

#include "lasb_cdstt_p.h"
#include "lasb_cdsff_p.h"
#include "lasb_cdsnn_p.h"

#include "lasb_tosxx_p.h"
#include "lasb_pdsxx_p.h"
#include "lasb_rjsxx_p.h"
#include "lasb_kssrr_p.h"

#include "lasb_ksroo_p.h"
#include "lasb_ksrvv_p.h"
#include "lasb_ksrjj_p.h"

#include "lasb_xxssave_p.h"
#include "lasb_xxsrest_p.h"

//---------------------------------------------------------------------------
class Tlasb_menu : public TForm
{
__published:	// IDE-managed Components
        TLabel *lasb_menu_xxlas_l;
        TLabel *lasb_menu_xxprg_l;
        TLabel *lasb_menu_xxtitle_l;
        TPageControl *lasb_menu_p;
        TTabSheet *lasb_menu_dok_p;
        TTabSheet *lasb_menu_rj_p;
        TTabSheet *lasb_menu_bo_p;
        TTabSheet *lasb_menu_krt_p;
        TTabSheet *lasb_menu_arch_p;
        TTabSheet *lasb_menu_end_p;

        TLabel *lasb_menu_dok_title_l;
        TLabel *lasb_menu_dok_rzd_l;
        TButton *lasb_menu_dok_cdstt_c;
        TLabel *lasb_menu_dok_rzd1_l;
        TButton *lasb_menu_dok_pdsxx_c;


        TLabel *lasb_menu_rj_title_l;
        TLabel *lasb_menu_rj_rzd_l;
        TButton *lasb_menu_rj_rjsxx_c;
        TButton *lasb_menu_rj_rjtks_c;
        TButton *lasb_menu_rj_kssrr_c;


        TLabel *lasb_menu_bo_title_l;
        TLabel *lasb_menu_bo_rzd_l;
        TButton *lasb_menu_bo_cdsff_c;
        TLabel *lasb_menu_bo_rzd1_l;
	  TButton *lasb_menu_bo_ksroo_c;
	  TButton *lasb_menu_bo_ksrvv_c;
	  TButton *lasb_menu_bo_ksrjj_c;


        TLabel *lasb_menu_krt_title_l;
        TLabel *lasb_menu_krt_rzd_l;
        TButton *lasb_menu_krt_tosxx_c;
        TLabel *lasb_menu_krt_rzd1_l;
        TButton *lasb_menu_krt_cdsnn_c;

        TLabel *lasb_menu_arch_title_l;
        TLabel *lasb_menu_arch_rzd_l;
        TButton *lasb_menu_arch_xxsrest_c;
        TButton *lasb_menu_arch_xxssave_c;

        TLabel *lasb_menu_end_title_l;
        TLabel *lasb_menu_end_rzd_l;
        TButton *lasb_menu_end_close_c;

        void __fastcall lasb_menu_dok_cdstt_cClick(TObject *Sender);
        void __fastcall lasb_menu_dok_pdsxx_cClick(TObject *Sender);

        void __fastcall lasb_menu_rj_rjsxx_cClick(TObject *Sender);
        void __fastcall lasb_menu_rj_rjtks_cClick(TObject *Sender);
        void __fastcall lasb_menu_rj_kssrr_cClick(TObject *Sender);

        void __fastcall lasb_menu_bo_cdsff_cClick(TObject *Sender);
        void __fastcall lasb_menu_bo_ksroo_cClick(TObject *Sender);
        void __fastcall lasb_menu_bo_ksrvv_cClick(TObject *Sender);
        void __fastcall lasb_menu_bo_ksrjj_cClick(TObject *Sender);

        void __fastcall lasb_menu_krt_tosxx_cClick(TObject *Sender);
        void __fastcall lasb_menu_krt_cdsnn_cClick(TObject *Sender);

        void __fastcall lasb_menu_arch_xxsrest_cClick(TObject *Sender);
        void __fastcall lasb_menu_arch_xxssave_cClick(TObject *Sender);

        void __fastcall lasb_menu_end_close_cClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_menu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_menu *lasb_menu;
//---------------------------------------------------------------------------
#endif
