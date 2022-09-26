#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*   Упражнение 5 (fio_05m3). Работа с массивами в нескольких циклах
     Аналогично упражнению 4, но за 3 прохода по массиву (ввести, рассчитать 
стоимость, вывод на консоль).

*/

int main(int argc, char** argv)
{	
	
char las_material_name[100][20];
int las_price[100];
int las_count[100];
int las_cost[100];
int las_current_index;
int las_temp_index;
bool las_exit;	
	
	system("chcp 1251");
	system("cls");
	
	printf("=Луд А.С.= \t\t =las_05m3= \n");	
	printf("=Упражнение 5 (las_05m3). Работа с массивами в нескольких циклах \n");
	printf("----------------------------------------------------------------\n");	
	
	
	las_current_index = 0;
	las_exit = false;	
	while(true)
		{	
						
		printf("~~~~~~~~~~~~~~\nВвод информации:\n~~~~~~~~~~~~~~\n");
		
		las_temp_index = las_current_index;
		while(las_temp_index < las_current_index + 3)
			{
				
			printf("Введите название материала: ");
			scanf("%s", las_material_name[las_temp_index]);
			
			if(las_material_name[las_temp_index][0] == '*')	
				{
					las_exit = true;
					break;
				}
			
			printf("Введите цену: ");
			scanf("%d", &las_price[las_temp_index]);
			
			printf("Введите количества: ");
			scanf("%d", &las_count[las_temp_index]);
			
			las_cost[las_temp_index] = 
				las_count[las_temp_index] * las_price[las_temp_index];
			printf("----------------------------------------------------------------\n");
						
			las_temp_index += 1;
			}
					
		if(las_exit)		
			break;		
		
		printf("~~~~~~~~~~~~~~\nВывод информации:\n~~~~~~~~~~~~~~\n");
		
		las_temp_index = las_current_index;
		while(las_temp_index < las_current_index + 3)
			{
				
			printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
				las_material_name[las_temp_index], 
				las_price[las_temp_index], 
				las_count[las_temp_index], 
				las_cost[las_temp_index]);		
			printf("----------------------------------------------------------------\n");
			
			las_temp_index += 1;
			}		
			
		las_current_index = las_temp_index;
		}
			
	return(0);
}
