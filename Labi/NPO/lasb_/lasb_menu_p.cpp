//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "lasb_menu_p.h"
#include "lasb_data_p.h"

#include "lasb_cdstt_p.h"
#include "lasb_cdsff_p.h"
#include "lasb_cdsnn_p.h"

#include "lasb_tosxx_p.h"
#include "lasb_togxx_p.h"

#include "lasb_pdsxx_p.h"
#include "lasb_rjsxx_p.h"
#include "lasb_rjtks_p.h"
#include "lasb_kssrr_p.h"

#include "lasb_ksroo_p.h"
#include "lasb_ksrvv_p.h"
#include "lasb_ksrjj_p.h"

#include "lasb_xxssave_p.h"
#include "lasb_xxsrest_p.h"

#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


Tlasb_menu *lasb_menu;
//---------------------------------------------------------------------------
__fastcall Tlasb_menu::Tlasb_menu(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
//  dok
//  группа работ   ввод и разноска первичных документов
//---------------------------------------------------------------------------
// вызов экранной формы
void __fastcall Tlasb_menu::lasb_menu_dok_cdstt_cClick(TObject *Sender)
{
       lasb_cdstt->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_dok_pdsxx_cClick(TObject *Sender)
{
        lasb_data->lasb_pdtbl->Last();
        lasb_pdsxx->Show();
}
//---------------------------------------------------------------------------
//  rj
//  группа работ       работа с рег журналом(РЖ) и книгой счетов(КС)
//---------------------------------------------------------------------------
// вызов просмотровой экранной формы (только чтение)
void __fastcall Tlasb_menu::lasb_menu_rj_rjsxx_cClick(TObject *Sender)
{
        lasb_data->lasb_rjtbl->Last();
        lasb_rjsxx->Show();
}
//---------------------------------------------------------------------------
// вызов программы
void __fastcall Tlasb_menu::lasb_menu_rj_rjtks_cClick(TObject *Sender)
{
        lasb_rjtks->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_rj_kssrr_cClick(TObject *Sender)
{
        lasb_data->lasb_kstbl->Last();
        lasb_kssrr->Show();
}
//---------------------------------------------------------------------------
//  bo
//  группа работ    формирование балансовой отчетности (БО)
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_bo_cdsff_cClick(TObject *Sender)
{
        lasb_cdsff->Show();
}
//---------------------------------------------------------------------------
// вызов формирования печатной формы
void __fastcall Tlasb_menu::lasb_menu_bo_ksroo_cClick(TObject *Sender)
{
    lasb_ksroo->lasb_ksroo_qoo->Close();
    lasb_ksroo->lasb_ksroo_qoo->SQL->Clear();
    lasb_ksroo->lasb_ksroo_qoo->SQL->
        Add("SELECT * FROM lasb_ks.db, lasb_cd.db WHERE lasb_ks_s=lasb_cd_s AND lasb_ks_data between lasb_cd_datas AND lasb_cd_datad");

    lasb_ksroo->lasb_ksroo_qoo->Open();

    int DbSum=0;
    int KrSum=0;
    lasb_ksroo->lasb_ksroo_qoo->First();
    while (!lasb_ksroo->lasb_ksroo_qoo->Eof)
    {
        DbSum=DbSum+
          lasb_ksroo->lasb_ksroo_qoo->
          FieldByName("lasb_ks_rubdb")->AsInteger;

        KrSum=KrSum+
          lasb_ksroo->lasb_ksroo_qoo->
          FieldByName("lasb_ks_rubkr")->AsInteger;

        lasb_ksroo->lasb_ksroo_qoo->Next();
    }

    lasb_ksroo->lasb_ksroo_dbsum->Caption=IntToStr(DbSum);
    lasb_ksroo->lasb_ksroo_krsum->Caption=IntToStr(KrSum);

    lasb_ksroo->lasb_ksroo_qr->Preview();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_bo_ksrvv_cClick(TObject *Sender)
{
// заглушка
  lasb_ksrvv->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_bo_ksrjj_cClick(TObject *Sender)
{
// заглушка
  lasb_ksrjj->Show();
}
//---------------------------------------------------------------------------
//  krt
//  группа работ   сопровождение картотек справочного характера
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_krt_tosxx_cClick(TObject *Sender)
{
        lasb_data->lasb_totbl->Last();
        lasb_tosxx->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_krt_cdsnn_cClick(TObject *Sender)
{
        lasb_cdsnn->Show();
}
//---------------------------------------------------------------------------
//  arch
//  группа работ   ведение архивов
//                 =сохранение и восстановление системы
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_arch_xxssave_cClick(TObject *Sender)
{
        lasb_xxssave->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_arch_xxsrest_cClick(TObject *Sender)
{
        lasb_xxsrest->Show();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//  end
//  группа работ   выход из системы
//---------------------------------------------------------------------------
void __fastcall Tlasb_menu::lasb_menu_end_close_cClick(TObject *Sender)
{
        exit(0);
}
//---------------------------------------------------------------------------


