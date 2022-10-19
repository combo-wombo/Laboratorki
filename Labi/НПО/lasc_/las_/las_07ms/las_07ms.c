#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*	 Упражнение 7 (fio_07ms). Работа с массивом структур в цикле.
     На базе исходника упражнения 6 Объявить массив структур  и отработать 
аналогично упражнению 4 за один проход ввод с консоли в массив, вычисление 
стоимости и вывод на консоль из массива пока не будет введена в названии 
материала первая *

*/

struct las_data
{	
	char las_material_name[20];
	int las_price;
	int las_count;
	int las_cost;
};

int main(int argc, char** argv)
{	

struct las_data las_values[100];
int 			las_current_index;
		
	system("chcp 1251");
	system("cls");
			
	printf("=Луд А.С.= \t\t =las_07ms= \n");
	printf("=Упражнение 7 (las_07ms). Работа с массивом структур в цикле.= \n");
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
		
		las_values[las_current_index].las_cost = 
			las_values[las_current_index].las_count * las_values[las_current_index].las_price;
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
