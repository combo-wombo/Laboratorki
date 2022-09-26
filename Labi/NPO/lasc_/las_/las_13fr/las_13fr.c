#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_13fr.h"

/*   Упражнение 13(fio_13fr). Чтение файла.
     На базе исходника упражнения 11 реализовать чтение  ранее полученного 
файла fio_12xx c выводом записей на консоль.

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data*	las_values;
FILE* 				las_file_d;		
		
	system("chcp 1251");
	system("cls");
			
	printf("=Луд А.С.= \t\t =las_13fr= \n");
	printf("=Упражнение 13(las_13fr). Чтение файла.= \n");
	printf("----------------------------------------------------------------\n");	
	
	if ((las_file_d = fopen("las_12xx", "rb")) == NULL)
		{
        perror("Error occured while opening file");
        return 1;
		}
	
	while(!feof(las_file_d))
		{
		las_values = (struct las_data*)malloc(sizeof(struct las_data)); 
			
		if(fread(las_values, sizeof(struct las_data), 1, las_file_d) != 1)			
			break;				
		
		printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
			las_values->las_material_name, 
			las_values->las_price, 
			las_values->las_count, 
			las_values->las_cost);		
		
		printf("----------------------------------------------------------------\n");	
		free(las_values);		
		}
	
    fclose(las_file_d);    
	
	getch();
	
	return(0);
}

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}
