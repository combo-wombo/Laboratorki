#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


/*	Упражнение 6 (fio_06s). Объявление структур
     Аналогично упражнению 2 и на  базе его исходника, но переменные объявить 
как элемент структуры.

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

struct las_data las_values;		
	
	system("chcp 1251");
	system("cls");
	
	printf("=Луд А.С.= \t\t =las_06s= \n");
	printf("=Упражнение 6 (las_06s). Объявление структур \n");
	printf("----------------------------------------------------------------\n");	
	
	printf("Введите название материала: ");
	scanf("%s", las_values.las_material_name);
	
	printf("Введите цену: ");
	scanf("%d", &las_values.las_price);
	
	printf("Введите количества: ");
	scanf("%d", &las_values.las_count);
	
	las_values.las_cost = las_values.las_count * las_values.las_price;
	
	printf("----------------------------------------------------------------\n");	
	printf("Название материала:%s Цена:%d Количество:%d Стоимость:%d\n",
		las_values.las_material_name, las_values.las_price, 
		las_values.las_count, las_values.las_cost);
	 
	printf("----------------------------------------------------------------\n");	
	
	printf("Введите любой символ\n");
	getch();
			
	return(0);
}
