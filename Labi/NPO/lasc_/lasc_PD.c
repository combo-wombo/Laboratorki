#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_pd() 
{
int 				lasc_wk;
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
struct lasc_pd_s 	lasc_pd_sd;
struct lasc_rj_s 	lasc_rj_sd;
struct lasc_txo_s 	lasc_txo_sd;
FILE* 				lasc_pd_sdf;
FILE* 				lasc_rj_sjf;
FILE* 				lasc_txo_sof;

    lasc_pd_sdf = fopen ("./lasc_D.db", "rb+");

    fseek(lasc_pd_sdf, 0, SEEK_END);
    lasc_l = ftell(lasc_pd_sdf);
    lasc_mrec = (int)((lasc_l / sizeof(lasc_pd_sd)) - 1);

    lasc_nrec = 0;
    fseek(lasc_pd_sdf, 0L, SEEK_SET);

    lasc_rj_sjf = fopen ("./lasc_J.db", "ab");

	while(true)
		{
			
		printf(" lasc_pd  Работа с первичными документами \n");
		printf("\t Количество записей %i   \n", lasc_mrec + 1);
		printf("\t Текущая запись %i  размер %i   \n\n", lasc_nrec + 1, sizeof(lasc_pd_sd));

		lasc_l = lasc_nrec * sizeof(lasc_pd_sd);
		fseek(lasc_pd_sdf, lasc_l, SEEK_SET);
		fread(&lasc_pd_sd, sizeof(lasc_pd_sd), 1, lasc_pd_sdf);

		printf("\t Документ  %s %i  от (дд мм гг) %i.%i.%i \n",
			   lasc_pd_sd.lasc_pd_dokk,
			   lasc_pd_sd.lasc_pd_dokn,
			   lasc_pd_sd.lasc_pd_dokd[0],
			   lasc_pd_sd.lasc_pd_dokd[1],
			   lasc_pd_sd.lasc_pd_dokd[2]);

		printf("\t Операция                 %s \n", lasc_pd_sd.lasc_pd_to );
		printf("\t Дебет (счет, название)   %i %s \n", lasc_pd_sd.lasc_pd_db, lasc_pd_sd.lasc_pd_dbn);
		printf("\t Кредит (счет, название)  %i %s \n", lasc_pd_sd.lasc_pd_kr, lasc_pd_sd.lasc_pd_krn);
		printf("\t Sae                      %s \n", lasc_pd_sd.lasc_pd_sae );
		printf("\t Сумма                    %i \n", lasc_pd_sd.lasc_pd_rub );

		printf("\n");
		printf("\t 1 - Помощь \n");
		printf("\t 4 - Редактировать \n");
		printf("\t 5 - Добавить \n");
		printf("\t 6 - Назад \n");
		printf("\t 7 - Вперед \n");
		printf("\t 9 - Разноска документа в РЖ \n");
		printf("\t 0 - Выход \n");
		
		scanf("%i", &lasc_wk);
		
		if (lasc_wk == lasc_wkh) 
			{
				
				printf("\t Документ (назв, номер, дата) \n");
				printf("\t Операция                     \n");
				printf("\t Дебет (счет, название)       \n");
				printf("\t Кредит (счет, название)      \n");
				printf("\t Sae                          \n");
				printf("\t Сумма                        \n");
				printf(" Нажмите любую клавишу \n");
				getch();
				continue;
				
			}
			
		if (lasc_wk == lasc_wke) 
			{
				
			printf(" lasc_pd  Первичные документы \n");

			printf("\t Документ  %s %i  от %i.%i.%i \n",
					   lasc_pd_sd.lasc_pd_dokk,
					   lasc_pd_sd.lasc_pd_dokn,
					   lasc_pd_sd.lasc_pd_dokd[0],
					   lasc_pd_sd.lasc_pd_dokd[1],
					   lasc_pd_sd.lasc_pd_dokd[2]);

			printf("\t Операция                %s \n", lasc_pd_sd.lasc_pd_to );
			printf("\t Дебет(счет, название)   %i %s \n", lasc_pd_sd.lasc_pd_db, lasc_pd_sd.lasc_pd_dbn);
			printf("\t Кредит(счет, название)  %i %s \n", lasc_pd_sd.lasc_pd_kr, lasc_pd_sd.lasc_pd_krn);
			printf("\t Sae                     %s \n", lasc_pd_sd.lasc_pd_sae );
			printf("\t Сумма                   %i \n", lasc_pd_sd.lasc_pd_rub );

			printf("\t Введите код документа \n");
			scanf("%s", lasc_pd_sd.lasc_pd_dokk);

			printf("\t Введите номер документа \n");
			scanf("%i", &lasc_pd_sd.lasc_pd_dokn);

			printf("\t Введите дд \n");
			scanf("%i", &lasc_pd_sd.lasc_pd_dokd[0]);

			printf("\t Введите мм \n");
			scanf("%i", &lasc_pd_sd.lasc_pd_dokd[1]);

			printf("\t Введите гг \n");
			scanf("%i", &lasc_pd_sd.lasc_pd_dokd[2]);

			lasc_txo_sof = fopen("./lasc_O.db", "rb");
			fseek(lasc_txo_sof, 0, SEEK_END);

			long lasc_txo_l = ftell(lasc_txo_sof);
			int lasc_txo_mrec = (int)(lasc_txo_l / sizeof(lasc_txo_sd) - 1);

			lasc_txo_sof = fopen("./lasc_O.db", "rb+");
			int lasc_txo_nrec = 0;
			lasc_txo_l = 0;
			fseek(lasc_txo_sof, lasc_txo_l, SEEK_SET);

			printf("**********************\n");
			printf(" Типовые операции (ТХО): \n");

			while (lasc_txo_nrec <= lasc_txo_mrec)
				{
					
				lasc_txo_l = lasc_txo_nrec * sizeof(lasc_txo_sd);
				fseek(lasc_txo_sof, lasc_txo_l, SEEK_SET);
				fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sof);

				printf("\t № %i \n", lasc_txo_nrec + 1);
				printf("\t Код документа      %s \n", lasc_txo_sd.lasc_txo_dokk);
				printf("\t Операция           %s \n", lasc_txo_sd.lasc_txo_k);
				printf("\t Дебет, счёт        %i \n", lasc_txo_sd.lasc_txo_db);
				printf("\t Дебет, назв        %s \n", lasc_txo_sd.lasc_txo_dbn);
				printf("\t Кредит, счёт       %i \n", lasc_txo_sd.lasc_txo_kr);
				printf("\t Кредит, назв       %s \n", lasc_txo_sd.lasc_txo_krn);
				printf("\t Sae                %s \n", lasc_txo_sd.lasc_txo_sae);

				printf("\n");

				lasc_txo_nrec++;
				
				} 

			printf("**********************\n");

			int lasc_txo_num;
				
			while (lasc_txo_num < 0 || lasc_txo_num > lasc_txo_mrec)
				{
					
				printf("\n Введите номер ТХО \n");
				scanf("%i", &lasc_txo_num);
				lasc_txo_num--;
					
				} 

			lasc_txo_l = lasc_txo_num * sizeof(lasc_txo_sd);
			fseek(lasc_txo_sof, lasc_txo_l, SEEK_SET);
			fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sof);

			memcpy(lasc_pd_sd.lasc_pd_to,lasc_txo_sd.lasc_txo_k, 10);
			lasc_pd_sd.lasc_pd_db = lasc_txo_sd.lasc_txo_db;
			memcpy(lasc_pd_sd.lasc_pd_dbn,lasc_txo_sd.lasc_txo_dbn, 10);
			lasc_pd_sd.lasc_pd_kr = lasc_txo_sd.lasc_txo_kr;
			memcpy(lasc_pd_sd.lasc_pd_krn,lasc_txo_sd.lasc_txo_krn, 10);
			memcpy(lasc_pd_sd.lasc_pd_sae,lasc_txo_sd.lasc_txo_sae, 10);

			printf("\n Введите  сумму \n");
			scanf("%i", &lasc_pd_sd.lasc_pd_rub);

			lasc_l = lasc_nrec * sizeof(lasc_pd_sd);
			fseek(lasc_pd_sdf, lasc_l, SEEK_SET);
			fwrite(&lasc_pd_sd, sizeof(lasc_pd_sd), 1, lasc_pd_sdf);
			continue;	
				
			}
			
		if (lasc_wk == lasc_wka)
			{
				
			lasc_mrec++;
			lasc_l = lasc_mrec * sizeof(lasc_pd_sd);
			fseek(lasc_pd_sdf, lasc_l, SEEK_SET);
			fwrite(&lasc_pd_sd, sizeof(lasc_pd_sd), 1, lasc_pd_sdf);
			lasc_nrec = lasc_mrec;
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
			if (lasc_nrec < lasc_mrec)
				lasc_nrec++;
			continue;
			}
			
		if (lasc_wk == lasc_wkq)
			{
			fclose(lasc_rj_sjf);
			fclose(lasc_pd_sdf);
			return;
			}
			
		if (lasc_wk == lasc_wkr)
			{
				
			lasc_rj_sd.lasc_rj_data[0] = lasc_pd_sd.lasc_pd_dokd[0];
			lasc_rj_sd.lasc_rj_data[1] = lasc_pd_sd.lasc_pd_dokd[1];
			lasc_rj_sd.lasc_rj_data[2] = lasc_pd_sd.lasc_pd_dokd[2];
			memcpy(lasc_rj_sd.lasc_rj_dokk, lasc_pd_sd.lasc_pd_dokk, 7);
			lasc_rj_sd.lasc_rj_dokn = lasc_pd_sd.lasc_pd_dokn;
			lasc_rj_sd.lasc_rj_dokd[0] = lasc_pd_sd.lasc_pd_dokd[0];
			lasc_rj_sd.lasc_rj_dokd[1] = lasc_pd_sd.lasc_pd_dokd[1];
			lasc_rj_sd.lasc_rj_dokd[2] = lasc_pd_sd.lasc_pd_dokd[2];
			memcpy(lasc_rj_sd.lasc_rj_to, lasc_pd_sd.lasc_pd_to, 10);
			lasc_rj_sd.lasc_rj_db = lasc_pd_sd.lasc_pd_db;
			memcpy(lasc_rj_sd.lasc_rj_dbn, lasc_pd_sd.lasc_pd_dbn, 10);
			lasc_rj_sd.lasc_rj_kr = lasc_pd_sd.lasc_pd_kr;
			memcpy(lasc_rj_sd.lasc_rj_krn, lasc_pd_sd.lasc_pd_krn, 10);
			memcpy(lasc_rj_sd.lasc_rj_sae, lasc_pd_sd.lasc_pd_sae, 10);
			lasc_rj_sd.lasc_rj_rub = lasc_pd_sd.lasc_pd_rub;

			fwrite(&lasc_rj_sd, sizeof(lasc_rj_sd), 1, lasc_rj_sjf);
			printf("Произошло разнесение \n");
			printf(" Нажмите любую клавишу \n");
			getch();	
			
			}		
		
		printf("\n Неверный ввод \n");		
		}
		
	printf(" Нажмите любую клавишу \n");
    getch();
}
