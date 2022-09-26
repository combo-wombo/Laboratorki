#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <direct.h>
#include <io.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_jtk() 
{
	
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
struct lasc_rj_s 	lasc_rj_sd;
struct lasc_ks_s 	lasc_ks_sd;
FILE* 				lasc_rj_sf;
FILE* 				lasc_ks_sf;

    lasc_rj_sf = fopen ("./lasc_J.db", "rb");

    fseek(lasc_rj_sf, 0, SEEK_END);
    lasc_l = ftell(lasc_rj_sf);
    lasc_mrec = (int)(lasc_l / sizeof(lasc_rj_sd));

    lasc_rj_sf = fopen("./lasc_J.db", "rb");

    lasc_nrec = 0;
    lasc_l = lasc_nrec * sizeof(lasc_rj_sd);
    fseek(lasc_rj_sf, lasc_l, SEEK_SET);

    lasc_ks_sf = fopen("./lasc_K.db", "wb");
    fclose(lasc_ks_sf);

    lasc_ks_sf = fopen ("./lasc_K.db", "ab");

    printf("lasc_jtk \t РЖ -> KC \n");
    printf("\t Количество записей %i n", lasc_mrec);
    printf("\t Запись %i  размер %i \n\n", lasc_nrec + 1, sizeof(lasc_rj_sd));

    lasc_nrec = 0;

	while(true)
		{
			
		lasc_nrec++;
		
		if (lasc_nrec > lasc_mrec)
			break;

		fread(&lasc_rj_sd, sizeof(lasc_rj_sd), 1, lasc_rj_sf);

		lasc_ks_sd.lasc_ks_data[0] = lasc_rj_sd.lasc_rj_data[0];
		lasc_ks_sd.lasc_ks_data[1] = lasc_rj_sd.lasc_rj_data[1];
		lasc_ks_sd.lasc_ks_data[2] = lasc_rj_sd.lasc_rj_data[2];
		memcpy(lasc_ks_sd.lasc_ks_dokk, lasc_rj_sd.lasc_rj_dokk, 7);
		lasc_ks_sd.lasc_ks_dokn = lasc_rj_sd.lasc_rj_dokn;
		lasc_ks_sd.lasc_ks_dokd[0] = lasc_rj_sd.lasc_rj_dokd[0];
		lasc_ks_sd.lasc_ks_dokd[1] = lasc_rj_sd.lasc_rj_dokd[1];
		lasc_ks_sd.lasc_ks_dokd[2] = lasc_rj_sd.lasc_rj_dokd[2];
		memcpy(lasc_ks_sd.lasc_ks_to, lasc_rj_sd.lasc_rj_to, 10);
		lasc_ks_sd.lasc_ks_s = lasc_rj_sd.lasc_rj_db;
		memcpy(lasc_ks_sd.lasc_ks_sn, lasc_rj_sd.lasc_rj_dbn, 10);

		lasc_ks_sd.lasc_ks_ks = lasc_rj_sd.lasc_rj_kr;
		memcpy(lasc_ks_sd.lasc_ks_ksn, lasc_rj_sd.lasc_rj_krn, 10);

		memcpy(lasc_ks_sd.lasc_ks_sae, lasc_rj_sd.lasc_rj_sae, 10);

		lasc_ks_sd.lasc_ks_rubdb = lasc_rj_sd.lasc_rj_rub;
		lasc_ks_sd.lasc_ks_rubkr = 0;

		fwrite(&lasc_ks_sd, sizeof(lasc_ks_sd), 1, lasc_ks_sf);

		lasc_ks_sd.lasc_ks_data[0] = lasc_rj_sd.lasc_rj_data[0];
		lasc_ks_sd.lasc_ks_data[1] = lasc_rj_sd.lasc_rj_data[1];
		lasc_ks_sd.lasc_ks_data[2] = lasc_rj_sd.lasc_rj_data[2];
		memcpy(lasc_ks_sd.lasc_ks_dokk, lasc_rj_sd.lasc_rj_dokk, 7);
		lasc_ks_sd.lasc_ks_dokn = lasc_rj_sd.lasc_rj_dokn;
		lasc_ks_sd.lasc_ks_dokd[0] = lasc_rj_sd.lasc_rj_dokd[0];
		lasc_ks_sd.lasc_ks_dokd[1] = lasc_rj_sd.lasc_rj_dokd[1];
		lasc_ks_sd.lasc_ks_dokd[2] = lasc_rj_sd.lasc_rj_dokd[2];
		memcpy(lasc_ks_sd.lasc_ks_to, lasc_rj_sd.lasc_rj_to, 10);
		lasc_ks_sd.lasc_ks_s = lasc_rj_sd.lasc_rj_kr;
		memcpy(lasc_ks_sd.lasc_ks_sn, lasc_rj_sd.lasc_rj_krn, 10);

		lasc_ks_sd.lasc_ks_ks = lasc_rj_sd.lasc_rj_db;
		memcpy(lasc_ks_sd.lasc_ks_ksn, lasc_rj_sd.lasc_rj_dbn, 10);

		memcpy(lasc_ks_sd.lasc_ks_sae, lasc_rj_sd.lasc_rj_sae, 10);

		lasc_ks_sd.lasc_ks_rubdb = 0;
		lasc_ks_sd.lasc_ks_rubkr = lasc_rj_sd.lasc_rj_rub;

		fwrite(&lasc_ks_sd, sizeof(lasc_ks_sd), 1, lasc_ks_sf);
		
		}

    fclose(lasc_rj_sf);
    fclose(lasc_ks_sf);

    printf(" Успех, обработано  %i  записей \n", lasc_nrec - 1);
    
    printf(" Нажмите любую клавишу \n");
    getch();
}
