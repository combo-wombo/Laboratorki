#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_10fn.h"

/*	 Упражнение 10 (fio_10fn). Использование функции пользователя.
     На базе исходника упражнения 9 реализовать  вычисление стоимости через 
вызов функции пользователя fio_10fv, которая находится том же исходном файле, 
с использованием передачи параметров по адресу.

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data 	las_values[las_SIZE];
int 				las_current_index;
		
	system("chcp 1251");
	system("cls");
			
	printf("=Луд А.С.= \t\t =las_10fn= \n");
	printf("=Упражнение 10 (las_10fn). Использование функции пользователя.= \n");
	printf("----------------------------------------------------------------\n");	
	
	las_current_index = 0;
	while (true)
		{
			
		printf("~~~~~~~~~~~~~~\nВвод информации:\n~~~~~~~~~~~~~~\n");		
		
		printf("Введите название материала: ");
		scanf("%s", las_values[las_current_index].las_material_name);
		
		if(las_values[las_current_index].las_material_name[0] == '*')	
			break;	
		
		printf("Введите цену: ");
		scanf("%d", &las_values[las_current_index].las_price);
		
		printf("Введите количества: ");
		scanf("%d", &las_values[las_current_index].las_count);
		
		las_10fv(&las_values[las_current_index]);
		printf("----------------------------------------------------------------\n");
					
		printf("~~~~~~~~~~~~~~\nВывод информации:\n~~~~~~~~~~~~~~\n");		
		printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
			las_values[las_current_index].las_material_name, 
			las_values[las_current_index].las_price, 
			las_values[las_current_index].las_count, 
			las_values[las_current_index].las_cost);		
			
		printf("----------------------------------------------------------------\n");	
		 
		las_current_index += 1;
		}	
		
	return(0);
}

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}

