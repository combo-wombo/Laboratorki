//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lasb_data_p.h"
#include "lasb_rjtks_p.h"
#include "lasb_xxsgrid_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tlasb_rjtks *lasb_rjtks;

//---------------------------------------------------------------------------
__fastcall Tlasb_rjtks::Tlasb_rjtks(TComponent* Owner)
        : TForm(Owner)
{
  lasb_data->lasb_rjtbl->Active=true;
  lasb_data->lasb_kstbl->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjtks::lasb_rjtks_gridrj_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_rjds;
  lasb_xxsgrid->Caption="lasb_rjtks  posmotri reg jurnal i viidi ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjtks::lasb_rjtks_gridks_cClick(TObject *Sender)
{
  lasb_xxsgrid->lasb_xxsgrid_g->DataSource= lasb_data->lasb_ksds;
  lasb_xxsgrid->Caption="lasb_rjtks  posmotri knigu schetov i viidi ";
  lasb_xxsgrid->Show();
}
//---------------------------------------------------------------------------
void __fastcall Tlasb_rjtks::lasb_rjtks_exit_cClick(TObject *Sender)
{
  lasb_data->lasb_rjtbl->Edit();
  lasb_data->lasb_rjtbl->Post();
  lasb_data->lasb_kstbl->Edit();
  lasb_data->lasb_kstbl->Post();
  lasb_rjtks->Close();
}
//---------------------------------------------------------------------------


void __fastcall Tlasb_rjtks::lasb_rjtks_wk_cClick(TObject *Sender)
{
        lasb_data->lasb_kstbl->First();
        lasb_data->lasb_kstbl->Active=true;

    while (!(lasb_data->lasb_kstbl->Eof))
        {
        lasb_data->lasb_kstbl->Delete();
        }

        lasb_data->lasb_rjtbl->First();
        lasb_data->lasb_rjtbl->Active=true;

        lasb_data->lasb_kstbl->First();
        lasb_data->lasb_kstbl->Active=true;


    while (!(lasb_data->lasb_rjtbl->Eof))
        {

//---------------

        lasb_data->lasb_kstbl->Append();
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_0")->AsString= "0";

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_data")->AsDateTime=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_data")->AsDateTime;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokk")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokk")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokn")->Value=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokn")->Value;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokd")->AsDateTime=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokd")->AsDateTime;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_to")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_to")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_s")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_db")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_sn")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dbn")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_ks")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_kr")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_ksn")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_krn")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_rubdb")->Value=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_rub")->Value;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_rubkr")->Value= 0;

        lasb_data->lasb_kstbl->Post();
//-------------

        lasb_data->lasb_kstbl->Append();
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_0")->AsString= "0";

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_data")->AsDateTime=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_data")->AsDateTime;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokk")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokk")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokn")->Value=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokn")->Value;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_dokd")->AsDateTime=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dokd")->AsDateTime;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_to")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_to")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_s")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_kr")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_sn")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_krn")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_ks")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_db")->AsString;
	lasb_data->lasb_kstbl->FieldByName("lasb_ks_ksn")->AsString=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_dbn")->AsString;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_rubdb")->Value= 0;

	lasb_data->lasb_kstbl->FieldByName("lasb_ks_rubkr")->Value=
           lasb_data->lasb_rjtbl->FieldByName("lasb_rj_rub")->Value;


        lasb_data->lasb_kstbl->Post();
//-------------

        lasb_data->lasb_rjtbl->Next();
        }

}
//---------------------------------------------------------------------------


