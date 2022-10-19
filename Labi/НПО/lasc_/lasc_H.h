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

// ���������� ������� ������������� �������� ���
// ����� ������ ������ �� ������
#define lasc_oswd 0x8000      	// �������� ������
#define lasc_oswr 0x4000    	// �������� ������

// ��������������� ������
// �ר� �������� ������
#define lasc_jswd 0x8000    	// �������� ������
#define lasc_jswr 0x4000    	// ����� ������

// Book of schets
// �ר� ������ ������ �� ��������
#define lasc_kswd 0x8000      	// �������� ������
#define lasc_kswr 0x4000    	// ����� ������ 

// Documents
// ��������� �� �������� ������
#define lasc_dswd 0x8000    // �������� ������
#define lasc_dswr 0x4000    // ����� ������

/* kniga schetov  */
/* �ר� ������ ������ �� ������� */
#define lasc_kswd 0x8000      	/* �������� ������ */
#define lasc_kswr 0x4000    	/* ����� ������  */

struct lasc_ks_s 
{
	int		lasc_ks_data[3];	/* ���� �������� */
	char	lasc_ks_dokk[7]; 	/* ��� ��������� */
	int		lasc_ks_dokn;		/* ����� ��������� */
	int		lasc_ks_dokd[3]; 	/* ���� ��������� */
	char	lasc_ks_to[10]; 	/* ���������� �������� */
	int 	lasc_ks_s;	 		/* ���� */
	char 	lasc_ks_sn[10]; 	/* ����, �������� */
	int 	lasc_ks_ks; 		/* ����. ���� */
	char 	lasc_ks_ksn[10]; 	/* ����. ����, �������� */
	char 	lasc_ks_sae[10]; 	/* sae */
	int 	lasc_ks_rubdb;	 	/* ����� ��*/
	int 	lasc_ks_rubkr;	 	/* ����� ��*/
};

/*************************************************/
/* dokymenty  */
/*��������� �� �������� ������*/
#define lasc_dswd 0x8000    /* �������� ������ */
#define lasc_dswr 0x4000    /* ����� ������  */

struct lasc_pd_s 
{
	char	lasc_pd_dokk[7]; 	/* ��� ��������� */
	int		lasc_pd_dokn;		/* ����� ��������� */
	int		lasc_pd_dokd[3]; 	/* ���� ��������� */
	char	lasc_pd_to[10]; 	/* �������� */
	int 	lasc_pd_db; 		/* �����, ���� */
	char 	lasc_pd_dbn[10]; 	/* �����, �������� */
	int 	lasc_pd_kr; 		/* ������, ���� */
	char 	lasc_pd_krn[10]; 	/* ������, �������� */
    char 	lasc_pd_sae[10]; 	/* sae */
    int 	lasc_pd_rub;	 	/* ����� */
};

/*************************************************/

/* ��������������� ������  */
/* �ר� �������� ������  */
#define lasc_jswd 0x8000    /* �������� ������ */
#define lasc_jswr 0x4000    /* ����� ������  */

struct lasc_rj_s 
{
	int		lasc_rj_data[3];	/* ���� �������� */
	char	lasc_rj_dokk[7]; 	/* ��� ��������� */
	int		lasc_rj_dokn;		/* ����� ��������� */
	int		lasc_rj_dokd[3]; 	/* ���� ��������� */
	char	lasc_rj_to[10]; 	/* ���������� �������� */
	int 	lasc_rj_db; 		/* �����, ���� */
	char 	lasc_rj_dbn[10]; 	/* �����, �������� */
	int 	lasc_rj_kr; 		/* ������, ���� */
	char 	lasc_rj_krn[10]; 	/* ������, �������� */
	char 	lasc_rj_sae[10]; 	/* sae */
	int 	lasc_rj_rub;	 	/* ����� */
};
/*************************************************/

/* ���������� ������� ������������� �������� ���  */
#define lasc_oswd 0x8000      	/* �������� ������ */
#define lasc_oswr 0x4000    	/* �������� ������  */

struct lasc_txo_s 
{
	char lasc_txo_dokk[7]; 		/* ��� ���������*/
	char lasc_txo_k[10]; 		/* �������� */
	int lasc_txo_db; 			/* �����, ���� */
	char lasc_txo_dbn[10]; 		/* �����, �������� */
	int lasc_txo_kr; 			/* ������, ���� */
	char lasc_txo_krn[10]; 		/* ������, �������� */
	char lasc_txo_sae[10]; 		/* sae */
};
