// РЕГИСТРАЦИОННЫЙ ЖУРНАЛ
#define lasc_jswd 0x8000    // Удалённая запись
#define lasc_jswr 0x4000    // Обход записи

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_rj() 
{
int 				lasc_wk;
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
struct lasc_rj_s 	lasc_rj_sd;
struct lasc_txo_s 	lasc_txo_sd;
FILE* 				lasc_rj_sjf;
FILE* 				lasc_txo_sof;

    lasc_rj_sjf = fopen("./lasc_J.db", "rb");

    fseek(lasc_rj_sjf, 0, SEEK_END);
    lasc_l = ftell(lasc_rj_sjf);
    lasc_mrec = (int)(lasc_l / sizeof(lasc_rj_sd) - 1);

    lasc_rj_sjf = fopen ("./lasc_J.db", "rb");

    lasc_nrec = 0;
    lasc_l = 0;
    fseek(lasc_rj_sjf, lasc_l, SEEK_SET);

    while(true)
		{
			
		printf(" lasc_rj \t Просмотр РЖ \n");
		printf("\t Количество записей %i \n", lasc_mrec + 1);
		printf("\t Запись %i  размер %i \n\n", lasc_nrec + 1, sizeof(lasc_rj_sd));
    
		lasc_l = lasc_nrec * sizeof(lasc_rj_sd);
		fseek(lasc_rj_sjf, lasc_l, SEEK_SET);
		fread(&lasc_rj_sd, sizeof(lasc_rj_sd), 1, lasc_rj_sjf);

		printf("\t Дата операции   %i %i %i \n",
			   lasc_rj_sd.lasc_rj_data[0],
			   lasc_rj_sd.lasc_rj_data[1],
			   lasc_rj_sd.lasc_rj_data[2]);
			   
		printf("\t Документ  %s %i  от (дд мм гг)  %i %i %i \n",
			   lasc_rj_sd.lasc_rj_dokk,
			   lasc_rj_sd.lasc_rj_dokn,
			   lasc_rj_sd.lasc_rj_dokd[0],
			   lasc_rj_sd.lasc_rj_dokd[1],
			   lasc_rj_sd.lasc_rj_dokd[2]);
			   
		printf("\t Операция                %s \n", lasc_rj_sd.lasc_rj_to);
		printf("\t Дебет (счет, название)   %i %s \n", lasc_rj_sd.lasc_rj_db, lasc_rj_sd.lasc_rj_dbn);
		printf("\t Кредит (счет, название)  %i %s \n", lasc_rj_sd.lasc_rj_kr, lasc_rj_sd.lasc_rj_krn);
		printf("\t Sae                     %s \n", lasc_rj_sd.lasc_rj_sae);
		printf("\t Сумма                   %i \n", lasc_rj_sd.lasc_rj_rub);
		
		printf("\n");
		printf("\t 1 - Помощь \n");
		printf("\t 4 - Редактировать \n");
		printf("\t 5 - Добавить \n");
		printf("\t 6 - Назад \n");
		printf("\t 7 - Вперед \n");
		printf("\t 0 - Выход \n");
			
		scanf("%i", &lasc_wk);
		
		if (lasc_wk == lasc_wkh) 
			{
			printf("\t Дата операции                \n");
			printf("\t Документ (назв, номер, дата) \n");
			printf("\t Операция                     \n");
			printf("\t Дебет (счет, название)       \n");
			printf("\t Кредит (счет, название)      \n");
			printf("\t Sae                          \n");
			printf("\t Сумма                        \n");
			printf("\t Нажмите любую клавишу \n");
			getch();	
			continue;
			}
		
		if (lasc_wk == lasc_wke)
			{
			printf(" lasc_rj \t Регистрационные журналы \n");

			printf("\t Дата операции   %i %i %i \n",
					  lasc_rj_sd.lasc_rj_data[0],
					  lasc_rj_sd.lasc_rj_data[1],
					  lasc_rj_sd.lasc_rj_data[2]);
					   
			printf("\t Документ  %s %i  от (дд мм гг)  %i %i %i \n",
					   lasc_rj_sd.lasc_rj_dokk,
					   lasc_rj_sd.lasc_rj_dokn,
					   lasc_rj_sd.lasc_rj_dokd[0],
					   lasc_rj_sd.lasc_rj_dokd[1],
					   lasc_rj_sd.lasc_rj_dokd[2]);
				
			printf("\t Операция                 %s \n", lasc_rj_sd.lasc_rj_to);
			printf("\t Дебет (счет, название)   %i %s \n", lasc_rj_sd.lasc_rj_db, lasc_rj_sd.lasc_rj_dbn);
			printf("\t Кредит (счет, название)  %i %s \n", lasc_rj_sd.lasc_rj_kr, lasc_rj_sd.lasc_rj_krn);
			printf("\t Sae                      %s \n", lasc_rj_sd.lasc_rj_sae);
			printf("\t Сумма                    %i \n", lasc_rj_sd.lasc_rj_rub);

			printf("\t Введите дату операции, дд \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_data[0]);

			printf("\t Введите дату операции, мм \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_data[1]);

			printf("\t Введите дату операции, гг \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_data[2]);
				
			printf("\t Введите код документа \n");
			scanf("%s", lasc_rj_sd.lasc_rj_dokk);

			printf("\t Введите номер документа \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_dokn);

			printf("\t Введите дату документа, дд \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_dokd[0]);

			printf("\t Введите дату документа, мм \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_dokd[1]);

			printf("\t Введите дату документа, гг \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_dokd[2]);

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
						
				printf("\n Введи номер ТХО \n");
				scanf("%i", &lasc_txo_num);
				lasc_txo_num--;
					
				}

			lasc_txo_l = lasc_txo_num * sizeof(lasc_txo_sd);
			fseek(lasc_txo_sof, lasc_txo_l, SEEK_SET);
			fread(&lasc_txo_sd, sizeof(lasc_txo_sd), 1, lasc_txo_sof);

			memcpy(lasc_rj_sd.lasc_rj_to,lasc_txo_sd.lasc_txo_k, 10);
			lasc_rj_sd.lasc_rj_db = lasc_txo_sd.lasc_txo_db;
			memcpy(lasc_rj_sd.lasc_rj_dbn,lasc_txo_sd.lasc_txo_dbn, 10);
			lasc_rj_sd.lasc_rj_kr = lasc_txo_sd.lasc_txo_kr;
			memcpy(lasc_rj_sd.lasc_rj_krn,lasc_txo_sd.lasc_txo_krn, 10);
			memcpy(lasc_rj_sd.lasc_rj_sae,lasc_txo_sd.lasc_txo_sae, 10);

			printf("\n Введите сумму \n");
			scanf("%i", &lasc_rj_sd.lasc_rj_rub);

			lasc_l = lasc_nrec * sizeof(lasc_rj_sd);
			fseek(lasc_rj_sjf, lasc_l, SEEK_SET);
			fwrite(&lasc_rj_sd, sizeof(lasc_rj_sd), 1, lasc_rj_sjf);
			continue;
			
			}
			
		if (lasc_wk == lasc_wka) 
			{
			lasc_mrec++;
			lasc_l = lasc_mrec * sizeof(lasc_rj_sd);
			fseek(lasc_rj_sjf, lasc_l, SEEK_SET);
			fwrite(&lasc_rj_sd, sizeof(lasc_rj_sd), 1, lasc_rj_sjf);
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
			return;
			}
		
		printf("\n Неверный ввод \n");
		
		}
		
	printf("\t Нажмите любую клавишу \n");
	getch();
}
