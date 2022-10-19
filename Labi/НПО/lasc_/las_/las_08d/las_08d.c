#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#define las_SIZE 100

/*	  Упражнение 8 (fio_08d). Использование #define.
     Аналогично упражнению 7 и на базе его исходника, но  размерность массива 
структур определена с использованием #define.

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

struct las_data las_values[las_SIZE];
int las_current_index;
		
	system("chcp 1251");
	system("cls");
			
	printf("=Луд А.С.= \t\t =las_08d= \n");
	printf("=Упражнение 8 (las_08d). Использование #define.= \n");
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
