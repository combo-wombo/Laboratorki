// РЕГИСТРАЦИОННЫЙ ЖУРНАЛ
#define lasc_kswd 0x8000    // удалённая запись
#define lasc_kswr 0x4000    // обход записи

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_ks() 
{
int 				lasc_wk;
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
struct lasc_ks_s 	lasc_ks_sd;
FILE* 				lasc_ks_sf;

    lasc_ks_sf = fopen("./lasc_K.db", "rb");
    fseek(lasc_ks_sf, 0, SEEK_END);
    lasc_l = ftell(lasc_ks_sf);
    lasc_mrec = (int)(lasc_l / sizeof(lasc_ks_sd));

    lasc_ks_sf = fopen("./lasc_K.db", "rb");

    lasc_nrec = 0;
    lasc_l = 0;
    fseek(lasc_ks_sf, lasc_l, SEEK_SET);

	while (true)
		{
			
		printf("lasc_ks \t Просмотр KC \n");
		printf("\t Количество записей %i n", lasc_mrec);
		printf("\t Запись %i размер %i \n\n", lasc_nrec + 1, sizeof(lasc_ks_sd));

		lasc_l = lasc_nrec * sizeof(lasc_ks_sd);
		fseek(lasc_ks_sf, lasc_l, SEEK_SET);
		fread(&lasc_ks_sd, sizeof(lasc_ks_sd), 1, lasc_ks_sf);

		printf("\t Дата операции  %i %i %i \n",
			   lasc_ks_sd.lasc_ks_data[0],
			   lasc_ks_sd.lasc_ks_data[1],
			   lasc_ks_sd.lasc_ks_data[2] );
		printf("\t Документ  %s %i  от (дд мм гг)  %i %i %i \n",
			   lasc_ks_sd.lasc_ks_dokk,
			   lasc_ks_sd.lasc_ks_dokn,
			   lasc_ks_sd.lasc_ks_dokd[0],
			   lasc_ks_sd.lasc_ks_dokd[1],
			   lasc_ks_sd.lasc_ks_dokd[2]);
			   
		printf("\t Операция          %s \n", lasc_ks_sd.lasc_ks_to );
		printf("\t Счет              %i %s \n", lasc_ks_sd.lasc_ks_s, lasc_ks_sd.lasc_ks_sn);
		printf("\t Корр. счет        %i %s \n", lasc_ks_sd.lasc_ks_ks, lasc_ks_sd.lasc_ks_ksn);
		printf("\t Sae               %s \n", lasc_ks_sd.lasc_ks_sae );
		printf("\t Сумма дб          %i \n", lasc_ks_sd.lasc_ks_rubdb );
		printf("\t Сумма кр          %i \n", lasc_ks_sd.lasc_ks_rubkr );

		printf("\n");
		printf("\t 1 - Помощь \n");
		printf("\t 6 - Назад \n");
		printf("\t 7 - Вперед \n");
		printf("\t 0 - Выход \n");
		
		scanf("%i", &lasc_wk);
		
		if (lasc_wk == lasc_wkh) 
			{
			printf("\t Дата операции               \n");
			printf("\t Документ(назв, номер, дата) \n");
			printf("\t Операция                    \n");
			printf("\t Счет                        \n");
			printf("\t Корр. счет                  \n");
			printf("\t Sae                         \n");
			printf("\t Сумма дб                    \n");
			printf("\t Сумма кр                    \n");
			printf(" Нажмите любую клавишу \n");
			getch();
			continue;
			}
			
		if (lasc_wk == lasc_wkb)
			{
			if (lasc_nrec > 0)
				lasc_nrec--;
			continue;
			}
						
		if (lasc_wk == lasc_wkf) 
			{
			if (lasc_nrec < lasc_mrec - 1)
				lasc_nrec++;
			continue;
			}
			
		if (lasc_wk == lasc_wkq) 
			{
			fclose(lasc_ks_sf);
				return;
			}
			
		printf("\n Неверный ввод \n");
		
	}
	
    getch();
}
