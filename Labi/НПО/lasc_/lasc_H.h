void lasc_pd();
void lasc_rj();
void lasc_jtk();
void lasc_ks();
void lasc_txo();
void lasc_k1();
void lasc_jo();
void lasc_bv();
void lasc_osv();
void lasc_ktk();
void lasc_ac();
void lasc_av();
void lasc_nst_sf();
void lasc_nst_si();
void lasc_nst_st();
void lasc_mn();

/***********************************************/

#define lasc_wkh   1	// Help
#define lasc_wks   2	// Save
#define lasc_wkp   3	// Print
#define lasc_wke   4	// Edit
#define lasc_wka   5	// Add
#define lasc_wkb   6	// Back
#define lasc_wkf   7	// Forward
#define lasc_wkd   8	// Delete
#define lasc_wkr   9 	// Rsmash
#define lasc_wkq   0	// Quit

/***********************************************/

struct lasc_nst 
{
	int lasc_nst_datat[3]; 		// Current data dd mm gg
	int lasc_nst_datas[3]; 		// Interval s dd mm gg
	int lasc_nst_datado[3]; 	// Interval do dd mm gg
	int lasc_nst_s; 			// Schet
	char lasc_nst_sn[10]; 		// Name of schet
	char lasc_nst_firma[10]; 	// Firm
};

/*************************************************/

// СПРАВОЧНИК ТИПОВЫХ ХОЗЯЙСТВЕННЫХ ОПЕРАЦИЙ ТХО
// Нормы выдачи спирта на станок
#define lasc_oswd 0x8000      	// Удалённая запись
#define lasc_oswr 0x4000    	// Обходная запись

// РЕГИСТРАЦИОННЫЙ ЖУРНАЛ
// УЧЁТ ПЕРЕДАЧИ СПИРТА
#define lasc_jswd 0x8000    	// Удалённая запись
#define lasc_jswr 0x4000    	// Обход записи

// Book of schets
// УЧЁТ ВЫДАЧИ ЛИТРОВ ПО УЧАСТКАМ
#define lasc_kswd 0x8000      	// Удалённая запись
#define lasc_kswr 0x4000    	// Обход записи 

// Documents
// НАКЛАДНЫЕ НА ПЕРЕДАЧУ СПИРТА
#define lasc_dswd 0x8000    // Удалённая запись
#define lasc_dswr 0x4000    // Обход записи

/* kniga schetov  */
/* УЧЁТ ВЫДАЧИ ЛИТРОВ ПО УЧАСТКА */
#define lasc_kswd 0x8000      	/* удалённая запись */
#define lasc_kswr 0x4000    	/* обход записи  */

struct lasc_ks_s 
{
	int		lasc_ks_data[3];	/* дата операции */
	char	lasc_ks_dokk[7]; 	/* код документа */
	int		lasc_ks_dokn;		/* номер документа */
	int		lasc_ks_dokd[3]; 	/* дата документа */
	char	lasc_ks_to[10]; 	/* содержание операции */
	int 	lasc_ks_s;	 		/* счет */
	char 	lasc_ks_sn[10]; 	/* счет, название */
	int 	lasc_ks_ks; 		/* корр. счет */
	char 	lasc_ks_ksn[10]; 	/* корр. счет, название */
	char 	lasc_ks_sae[10]; 	/* sae */
	int 	lasc_ks_rubdb;	 	/* сумма дб*/
	int 	lasc_ks_rubkr;	 	/* сумма кр*/
};

/*************************************************/
/* dokymenty  */
/*НАКЛАДНЫЕ НА ПЕРЕДАЧУ СПИРТА*/
#define lasc_dswd 0x8000    /* удалённая запись */
#define lasc_dswr 0x4000    /* обход записи  */

struct lasc_pd_s 
{
	char	lasc_pd_dokk[7]; 	/* код документа */
	int		lasc_pd_dokn;		/* номер документа */
	int		lasc_pd_dokd[3]; 	/* дата документа */
	char	lasc_pd_to[10]; 	/* операция */
	int 	lasc_pd_db; 		/* дебет, счет */
	char 	lasc_pd_dbn[10]; 	/* дебет, название */
	int 	lasc_pd_kr; 		/* кредит, счет */
	char 	lasc_pd_krn[10]; 	/* кредит, название */
    char 	lasc_pd_sae[10]; 	/* sae */
    int 	lasc_pd_rub;	 	/* сумма */
};

/*************************************************/

/* РЕГИСТРАЦИОННЫЙ ЖУРНАЛ  */
/* УЧЁТ ПЕРЕДАЧИ СПИРТА  */
#define lasc_jswd 0x8000    /* удалённая запись */
#define lasc_jswr 0x4000    /* обход записи  */

struct lasc_rj_s 
{
	int		lasc_rj_data[3];	/* дата операции */
	char	lasc_rj_dokk[7]; 	/* код документа */
	int		lasc_rj_dokn;		/* номер документа */
	int		lasc_rj_dokd[3]; 	/* дата документа */
	char	lasc_rj_to[10]; 	/* содержание операции */
	int 	lasc_rj_db; 		/* дебет, счет */
	char 	lasc_rj_dbn[10]; 	/* дебет, название */
	int 	lasc_rj_kr; 		/* кредит, счет */
	char 	lasc_rj_krn[10]; 	/* кредит, название */
	char 	lasc_rj_sae[10]; 	/* sae */
	int 	lasc_rj_rub;	 	/* сумма */
};
/*************************************************/

/* СПРАВОЧНИК ТИПОВЫХ ХОЗЯЙСТВЕННЫХ ОПЕРАЦИЙ ТХО  */
#define lasc_oswd 0x8000      	/* удалённая запись */
#define lasc_oswr 0x4000    	/* обходная запись  */

struct lasc_txo_s 
{
	char lasc_txo_dokk[7]; 		/* код документа*/
	char lasc_txo_k[10]; 		/* операция */
	int lasc_txo_db; 			/* дебет, счет */
	char lasc_txo_dbn[10]; 		/* дебет, название */
	int lasc_txo_kr; 			/* кредит, счет */
	char lasc_txo_krn[10]; 		/* кредит, название */
	char lasc_txo_sae[10]; 		/* sae */
};
