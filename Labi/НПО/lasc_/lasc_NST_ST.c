#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "lasc_H.h"

void  lasc_nst_st() 
{
struct lasc_nst 	lasc_nst_sti, lasc_nst_std;
FILE* 				lasc_nst_stf;

	printf(" lasc_nst Луд А.С. \n");
	printf(" Объявление даты \n");

	lasc_nst_stf = fopen("./lasc_C.db", "rb+");

	fseek(lasc_nst_stf, 0L, SEEK_SET);

	fread(&lasc_nst_std, sizeof(lasc_nst_std), 1, lasc_nst_stf);

	printf(" lasc_nst Ввод текущей даты \n");

	printf(" Дата: дд мм гг %i %i %i \n",
		   lasc_nst_std.lasc_nst_datat[0],
		   lasc_nst_std.lasc_nst_datat[1],
		   lasc_nst_std.lasc_nst_datat[2]);

	printf("\t Введите день \t 0 - без изменений \n");
	scanf("%i", &lasc_nst_sti.lasc_nst_datat[0]);
	
	if (lasc_nst_sti.lasc_nst_datat[0] != 0)
		lasc_nst_std.lasc_nst_datat[0] = lasc_nst_sti.lasc_nst_datat[0];

	printf("\t Введите месяц \t 0 - без изменений \n");
	
	scanf("%i", &lasc_nst_sti.lasc_nst_datat[1]);
	if (lasc_nst_sti.lasc_nst_datat[1] != 0)
		lasc_nst_std.lasc_nst_datat[1] = lasc_nst_sti.lasc_nst_datat[1];

	printf("\t Введите год \t 0 - без изменений \n");
	
	scanf("%i", &lasc_nst_sti.lasc_nst_datat[2]);
	if (lasc_nst_sti.lasc_nst_datat[2] != 0)
		lasc_nst_std.lasc_nst_datat[2] = lasc_nst_sti.lasc_nst_datat[2];

	fseek(lasc_nst_stf, 0l, SEEK_SET);

	fwrite(&lasc_nst_std, sizeof(lasc_nst_std), 1, lasc_nst_stf);

	fclose(lasc_nst_stf);

	printf(" Нажмите любую клавишу \n");
	getch();
}
