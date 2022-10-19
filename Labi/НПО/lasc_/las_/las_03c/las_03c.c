#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*
	 Упражнение 3 (fio_03c). Работа в цикле
     Вышеуказанные переменные вводить с консоли и выволить на консоль пока 
не будет введена в названии материала первая *
*/

int main(int argc, char** argv)
{	
	
char 	las_material_name[20];
int 	las_price;
int 	las_count;
int 	las_cost;		
		
	system("chcp 1251");
	system("cls");
	
	
	printf("=Луд А.С.= \t\t =las_03c= \n");
	printf("=Упражнение 3 (las_03c). Работа в цикле= \n");
	printf("----------------------------------------------------------------\n");	
			
	while(true)
		{
		printf("~~~~~~~~~~~~~~\nВвод информации:\n~~~~~~~~~~~~~~\n");
		
		printf("Введите название материала: ");
		scanf("%s", las_material_name);
				
		if(las_material_name[0] == '*')		
			break;		
		
		printf("Введите цену: ");
		scanf("%d", &las_price);
		
		printf("Введите количества: ");
		scanf("%d", &las_count);
		
		las_cost = las_count * las_price;
		
		printf("~~~~~~~~~~~~~~\nВывод информации:\n~~~~~~~~~~~~~~\n");
		printf("Название материала:%s Цена:%d Количество:%d Стоимость:%d\n",
			las_material_name, las_price, las_count, las_cost);		
		printf("----------------------------------------------------------------\n");
		}	
	
	return(0);
}


