#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_txo() 
{
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
struct lasc_txo_s 	lasc_txo_sd;
FILE* 				lasc_txo_sf;
int 				lasc_wk;

    lasc_txo_sf = fopen("./lasc_O.db", "rb");
    
    fseek(lasc_txo_sf, 0, SEEK_END);

    lasc_l = ftell(lasc_txo_sf);
    lasc_mrec = (int)(lasc_l / sizeof(lasc_txo_sd) - 1);

    lasc_txo_sf = fopen("./lasc_O.db", "rb+");
    
    lasc_nrec = 0;
    lasc_l = 0;
    
    fseek(lasc_txo_sf, lasc_l, SEEK_SET);

	lasc_l = lasc_nrec * sizeof(lasc_txo_sd);
    fseek(lasc_txo_sf, lasc_l, SEEK_SET);
    fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sf);
    
	
	
	while(true) {
		printf("\t Document code      %s \n",	lasc_txo_sd.lasc_txo_dokk	);
		printf("\t Operation          %s \n",	lasc_txo_sd.lasc_txo_k  	);
		printf("\t Debet, schet       %i \n",	lasc_txo_sd.lasc_txo_db 	);
		printf("\t Debet, name        %s \n",	lasc_txo_sd.lasc_txo_dbn	);
		printf("\t Kredit, schet      %i \n",	lasc_txo_sd.lasc_txo_kr 	);
		printf("\t Kredit, name       %s \n",	lasc_txo_sd.lasc_txo_krn 	);
		printf("\t Sae                %s \n",	lasc_txo_sd.lasc_txo_sae	);
    
		printf(" lasc_txo \t ��� �.�. \n");
		printf(" lasc_txo \t ���������� ������� ����� � ����� ������� \n");
		printf("\t ���������� ������� %i \n", lasc_mrec + 1);
		printf("\t ������ %i  ������ %i \n\n", lasc_nrec + 1, sizeof(lasc_txo_sd));
		
		printf("\n");
		printf("\t 1 - ������ \n");
		printf("\t 4 - ������������� \n");
		printf("\t 5 - �������� \n");
		printf("\t 6 - ����� \n");
		printf("\t 7 - ������ \n");
		printf("\t 0 - ����� \n");
		
		scanf("%i", &lasc_wk);
		
		if (lasc_wk == lasc_wkh) 
			{
			printf("\t Document code \n");
			printf("\t Operation  \n");
			printf("\t Full operation \n");
			printf("\t Debet, schet \n");
			printf("\t Debet, name \n");
			printf("\t Kredit, schet \n");
			printf("\t Kredit, name \n");
			printf("\t Sae \n");
			printf(" ����� ����� ������� \n");
			getch();
			continue;
			}
			
		if (lasc_wk == lasc_wke)
			{
			printf(" lasc_txo \t ������ �� ������������   \n");
			printf("\t Document code      %s \n",	lasc_txo_sd.lasc_txo_dokk	);
			printf("\t Operation          %s \n",	lasc_txo_sd.lasc_txo_k  	);
			printf("\t Debet, schet       %i \n",	lasc_txo_sd.lasc_txo_db 	);
			printf("\t Debet, name        %s \n",	lasc_txo_sd.lasc_txo_dbn	);
			printf("\t Kredit, schet      %i \n",	lasc_txo_sd.lasc_txo_kr 	);
			printf("\t Kredit, name       %s \n",	lasc_txo_sd.lasc_txo_krn 	);
			printf("\t Sae                %s \n",	lasc_txo_sd.lasc_txo_sae	);

			printf("\t ������� ��� ��������� \n");
			scanf("%s", lasc_txo_sd.lasc_txo_dokk);
			printf("\t ������� �������� \n");
			scanf("%s", lasc_txo_sd.lasc_txo_k);
			printf("\t ������� �����, ���� \n");
			scanf("%i", &lasc_txo_sd.lasc_txo_db);
			printf("\t ������� �����, �������� \n");
			scanf("%s", lasc_txo_sd.lasc_txo_dbn);
			printf("\t ������� ������, ���� \n");
			scanf("%i", &lasc_txo_sd.lasc_txo_kr);
			printf("\t ������� ������, �������� \n");
			scanf("%s", lasc_txo_sd.lasc_txo_krn);
			printf("\t ������� sae \n");
			scanf("%s", lasc_txo_sd.lasc_txo_sae);

			lasc_l = lasc_nrec * sizeof(lasc_txo_sd);
			fseek(lasc_txo_sf, lasc_l, SEEK_SET);
			fwrite(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sf);
			continue;
			}
			
		if (lasc_wk == lasc_wka) 
			{
			lasc_mrec++;
			lasc_l = lasc_mrec * sizeof(lasc_txo_sd);
			fseek(lasc_txo_sf, lasc_l, SEEK_SET);
			fwrite(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sf);
			lasc_nrec = lasc_mrec;
			continue;
			}
			
		if (lasc_wk == lasc_wkb) 
			{
			if (lasc_nrec > 0)
				lasc_nrec--;
				
			fseek(lasc_txo_sf, (lasc_nrec) * sizeof(lasc_txo_sd) , SEEK_SET);
			fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sf);
			continue;
			}
			
		if (lasc_wk == lasc_wkf) 
			{
			if (lasc_nrec < lasc_mrec)
				lasc_nrec++;
				
			fseek(lasc_txo_sf, (lasc_nrec) * sizeof(lasc_txo_sd) , SEEK_SET);
			fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sf);
			continue;
			}
			
		if (lasc_wk == lasc_wkq) 
			{
			fclose(lasc_txo_sf);
			return;
			}
			
		printf("\n �������� ���� \n");
		
	}
    getch();
}
