//---------------------------------------------------------------------------

#ifndef lasb_data_pH
#define lasb_data_pH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class Tlasb_data : public TForm
{
__published:	// IDE-managed Components
        TDatabase *lasb_data;
        TTable *lasb_totbl;
        TTable *lasb_pdtbl;
        TTable *lasb_rjtbl;
        TTable *lasb_kstbl;
        TTable *lasb_cdtbl;
        TDataSource *lasb_cdds;
        TDataSource *lasb_tods;
        TDataSource *lasb_pdds;
        TDataSource *lasb_rjds;
        TDataSource *lasb_ksds;
        TQuery *lasb_ksqoo;
        TDataSource *lasb_ksqds;
        TQuery *lasb_toqoo;
        TDataSource *lasb_toqds;


private:	// User declarations
public:		// User declarations
        __fastcall Tlasb_data(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tlasb_data *lasb_data;
//---------------------------------------------------------------------------
#endif
