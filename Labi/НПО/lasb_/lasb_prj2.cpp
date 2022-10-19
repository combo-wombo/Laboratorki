//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//---------------------------------------------------------------------------
USEFORM("lasb_menu_p.cpp", lasb_menu);
USEFORM("lasb_data_p.cpp", lasb_data);
USEFORM("lasb_cdsff_p.cpp", lasb_cdsff);
USEFORM("lasb_cdsnn_p.cpp", lasb_cdsnn);
USEFORM("lasb_cdstt_p.cpp", lasb_cdstt);
USEFORM("lasb_pdsxx_p.cpp", lasb_pdsxx);
USEFORM("lasb_rjsxx_p.cpp", lasb_rjsxx);
USEFORM("lasb_rjtks_p.cpp", lasb_rjtks);
USEFORM("lasb_kssrr_p.cpp", lasb_kssrr);
USEFORM("lasb_ksroo_p.cpp", lasb_ksroo);
USEFORM("lasb_ksrvv_p.cpp", lasb_ksrvv);
USEFORM("lasb_ksrjj_p.cpp", lasb_ksrjj);
USEFORM("lasb_tosxx_p.cpp", lasb_tosxx);
USEFORM("lasb_togxx_p.cpp", lasb_togxx);
USEFORM("lasb_xxsgrid_p.cpp", lasb_xxsgrid);
USEFORM("lasb_xxssave_p.cpp", lasb_xxssave);
USEFORM("lasb_xxsrest_p.cpp", lasb_xxsrest);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tlasb_menu), &lasb_menu);
                 Application->CreateForm(__classid(Tlasb_data), &lasb_data);
                 Application->CreateForm(__classid(Tlasb_cdsff), &lasb_cdsff);
                 Application->CreateForm(__classid(Tlasb_cdsnn), &lasb_cdsnn);
                 Application->CreateForm(__classid(Tlasb_cdstt), &lasb_cdstt);
                 Application->CreateForm(__classid(Tlasb_tosxx), &lasb_tosxx);
                 Application->CreateForm(__classid(Tlasb_togxx), &lasb_togxx);
                 Application->CreateForm(__classid(Tlasb_pdsxx), &lasb_pdsxx);
                 Application->CreateForm(__classid(Tlasb_rjsxx), &lasb_rjsxx);
                 Application->CreateForm(__classid(Tlasb_rjtks), &lasb_rjtks);
                 Application->CreateForm(__classid(Tlasb_kssrr), &lasb_kssrr);
                 Application->CreateForm(__classid(Tlasb_ksroo), &lasb_ksroo);
                 Application->CreateForm(__classid(Tlasb_ksrvv), &lasb_ksrvv);
                 Application->CreateForm(__classid(Tlasb_ksrjj), &lasb_ksrjj);
                 Application->CreateForm(__classid(Tlasb_xxsgrid), &lasb_xxsgrid);
                 Application->CreateForm(__classid(Tlasb_xxsrest), &lasb_xxsrest);
                 Application->CreateForm(__classid(Tlasb_xxssave), &lasb_xxssave);
                 Application->Run();
        }

        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
