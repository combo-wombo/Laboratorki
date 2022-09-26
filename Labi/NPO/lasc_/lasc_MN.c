#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

#include "lasc_H.h"

int main() 
{
	
int 	lasc_wk;
	
    setlocale(0, "");

    while(true)
		{
			
		printf(" lasc_mn Луд А.С. \t Бухгалтерия на С \n\n");

		printf(" Первичные документы \n");
		printf("\t 11 - Ввод текущей даты \n");
		printf("\t 12 - Ввод и разноска первичных документов (ПД) \n");

		printf(" Работа с учётными журналами \n");
		printf("\t 21 - Просмотр РЖ \n");
		printf("\t 22 - Форм. КС из РЖ \n");
		printf("\t 23 - Просмотр КС \n");

		printf(" Балансовая отчетность \n");
		printf("\t 31 - Определение отчетных форм \n");
		printf("\t 32 - Оборотно-сальдовая ведомость \n");
		printf("\t 33 - Балансовая ведомость (заглушка) \n");
		printf("\t 34 - Журнал-ордер (заглушка) \n");

		printf(" Картотеки  \n");
		printf("\t 41 - Типовые операции (ТХО) \n");
		printf("\t 42 - Настройка АРМа \n");

		printf(" Архивы \n");
		printf("\t 51 - Копия (заглушка) \n");
		printf("\t 52 - Восстановление (заглушка) \n");

		printf(" Выход \n");
		printf("\t 61 - Выход \n");
		
		scanf("%i", &lasc_wk);
		
		if(lasc_wk == 11) 
			{
			lasc_nst_st();
			continue;	
			}
			
		if(lasc_wk == 12) 
			{
			lasc_pd();
			continue;	
			}
			
		if(lasc_wk == 21) 
			{
			lasc_rj();
			continue;	
			}
			
		if(lasc_wk == 22) 
			{
			lasc_jtk();
			continue;	
			}
			
		if(lasc_wk == 23) 
			{
			lasc_ks();
			continue;	
			}
			
		if(lasc_wk == 31) 
			{
			lasc_nst_si();
			continue;	
			}
			
		if(lasc_wk == 32) 
			{
			lasc_osv();
			continue;	
			}
			
		if(lasc_wk == 33) 
			{
			lasc_bv();
			continue;	
			}
			
		if(lasc_wk == 34) 
			{
			lasc_jo();
			continue;	
			}
			
		if(lasc_wk == 41) 
			{
			lasc_txo();
			continue;	
			}
			
		if(lasc_wk == 42) 
			{
			lasc_nst_sf();
			continue;	
			}	
			
		if(lasc_wk == 51) 
			{
			lasc_ac();
			continue;	
			}
			
		if(lasc_wk == 52) 
			{
			lasc_av();
			continue;	
			}
			
		if(lasc_wk == 61) 
			{
			return 0;
			}
			
		printf("\n Неверный ввод \n");	
		
		}
	
    getch();
	return(0);
}
