#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*	 Упражнение 4 (fio_04m). Работа с массивами в цикле
     Для вышеуказанных переменных объявить массивы на 100 элементов и отработать 
за один проход ввод с консоли в массив, вычисление стоимости и вывод на консоль 
из массива пока не будет введена в названии материала первая *
* 
*/

int main(int argc, char** argv)
{	
		
char 	las_material_name[100][20];
int 	las_price[100];
int 	las_count[100];
int 	las_cost[100];
int 	las_current_index;
	
	system("chcp 1251");
	system("cls");
	
	printf("=Луд А.С.= \t\t =las_04m= \n");	
	printf("=Упражнение 4 (las_04m). Работа с массивами в цикле= \n");
	printf("----------------------------------------------------------------\n");	
			
	las_current_index = 0;
	while(true)
		{
		printf("~~~~~~~~~~~~~~\nВвод информации:\n~~~~~~~~~~~~~~\n");
		printf("Введите название материала: ");
		scanf("%s", las_material_name[las_current_index]);
		
		if(las_material_name[las_current_index][0] == '*')		
			break;
				
		printf("Введите цену: ");
		scanf("%d", &las_price[las_current_index]);
		
		printf("Введите количества: ");
		scanf("%d", &las_count[las_current_index]);
		
		las_cost[las_current_index] = 
			las_count[las_current_index] * las_price[las_current_index];
		
		printf("~~~~~~~~~~~~~~\nВывод информации:\n~~~~~~~~~~~~~~\n");
		printf("Название материала:%s Цена:%d Количество:%d Стоимость:%d\n",
			las_material_name[las_current_index],
			las_price[las_current_index], 
			las_count[las_current_index], 
			las_cost[las_current_index]);
		
		las_current_index += 1;
		
		printf("----------------------------------------------------------------\n");
		}	
		
	return(0);
}
