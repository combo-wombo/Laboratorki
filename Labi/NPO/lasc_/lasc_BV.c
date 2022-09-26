// УЧЁТ ВЫДАЧИ ЛИТРОВ ПО УЧАСТКА
#define lasc_kswd 0x8000      	// Удалённая запись
#define lasc_kswr 0x4000    	// Обход записи

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <io.h>

#include "lasc_H.h"

void lasc_bv() 
{
    printf("lasc_bv Балансовая ведомость \n");
    printf("\t Балансовая ведомость сформирована \n");
    
    printf("\t Нажмите любую клавишу \n");
    getch();
}
