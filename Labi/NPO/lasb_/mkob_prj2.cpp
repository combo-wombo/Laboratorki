//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//---------------------------------------------------------------------------
USEFORM("mkob_menu_p.cpp", mkob_menu);
USEFORM("mkob_data_p.cpp", mkob_data);
USEFORM("mkob_cdsff_p.cpp", mkob_cdsff);
USEFORM("mkob_cdsnn_p.cpp", mkob_cdsnn);
USEFORM("mkob_cdstt_p.cpp", mkob_cdstt);
USEFORM("mkob_pdsxx_p.cpp", mkob_pdsxx);
USEFORM("mkob_rjsxx_p.cpp", mkob_rjsxx);
USEFORM("mkob_rjtks_p.cpp", mkob_rjtks);
USEFORM("mkob_kssrr_p.cpp", mkob_kssrr);
USEFORM("mkob_ksroo_p.cpp", mkob_ksroo);
USEFORM("mkob_ksrvv_p.cpp", mkob_ksrvv);
USEFORM("mkob_ksrjj_p.cpp", mkob_ksrjj);
USEFORM("mkob_tosxx_p.cpp", mkob_tosxx);
USEFORM("mkob_togxx_p.cpp", mkob_togxx);
USEFORM("mkob_xxsgrid_p.cpp", mkob_xxsgrid);
USEFORM("mkob_xxssave_p.cpp", mkob_xxssave);
USEFORM("mkob_xxsrest_p.cpp", mkob_xxsrest);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tmkob_menu), &mkob_menu);
                 Application->CreateForm(__classid(Tmkob_data), &mkob_data);
                 Application->CreateForm(__classid(Tmkob_cdsff), &mkob_cdsff);
                 Application->CreateForm(__classid(Tmkob_cdsnn), &mkob_cdsnn);
                 Application->CreateForm(__classid(Tmkob_cdstt), &mkob_cdstt);
                 Application->CreateForm(__classid(Tmkob_tosxx), &mkob_tosxx);
                 Application->CreateForm(__classid(Tmkob_togxx), &mkob_togxx);
                 Application->CreateForm(__classid(Tmkob_pdsxx), &mkob_pdsxx);
                 Application->CreateForm(__classid(Tmkob_rjsxx), &mkob_rjsxx);
                 Application->CreateForm(__classid(Tmkob_rjtks), &mkob_rjtks);
                 Application->CreateForm(__classid(Tmkob_kssrr), &mkob_kssrr);
                 Application->CreateForm(__classid(Tmkob_ksroo), &mkob_ksroo);
                 Application->CreateForm(__classid(Tmkob_ksrvv), &mkob_ksrvv);
                 Application->CreateForm(__classid(Tmkob_ksrjj), &mkob_ksrjj);
                 Application->CreateForm(__classid(Tmkob_xxsgrid), &mkob_xxsgrid);
                 Application->CreateForm(__classid(Tmkob_xxsrest), &mkob_xxsrest);
                 Application->CreateForm(__classid(Tmkob_xxssave), &mkob_xxssave);
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
