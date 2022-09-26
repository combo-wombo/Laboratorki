#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_15fp.h"

/*	 Упражнение 15(fio_15fp). Позиционирование в файле.
     Сделать ввод с консоли символа управления (1 - начало файла, 2 - вперед, 
3 - назад, 4 - в конец файла, 9 - выход из программы) и реализовать 
позиционирование в файле fio_12xx с выводом на консоль полей записи. 

*/

int main(int argc, char** argv)
{		

FILE			*las_file_d;	

struct las_data *las_values;

int 			las_command;

	system("chcp 1251");
	system("cls");
		
	printf("=Луд А.С.= \t\t =las_15fp= \n");	
	printf("=Упражнение 15(las_15fp). Позиционирование в файле.= \n");	
	printf("----------------------------------------------------------------\n");	
			  
	las_file_d = fopen("las_12xx", "rb");
    if (las_file_d == NULL)
		{
        perror("Error occured while opening file");
        return(1);
		}    
    
    printf("Инструкция:\n");
	printf("1 - начало файла\n");
	printf("2 - вперед\n");
	printf("3 - назад\n");
	printf("4 - в конец файла\n");
	printf("9 - выход из программы\n");
			
	las_values = (struct las_data*)malloc(sizeof(struct las_data));
	
	while (true)
		{
		scanf("%d", &las_command);
		
		if(las_command == 1)
			{
			rewind(las_file_d);	
			fread(las_values, sizeof(struct las_data), 1, las_file_d);
			printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
				las_values->las_material_name, 
				las_values->las_price, 
				las_values->las_count, 
				las_values->las_cost);
			}
			
		if(las_command == 2)
			{
			if(fread(las_values, sizeof(struct las_data), 1, las_file_d) == 1)
				{
				printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
					las_values->las_material_name, 
					las_values->las_price, 
					las_values->las_count, 
					las_values->las_cost);
				continue;
				}			
			printf("Вы находитесь в конце файла. \n");
			}
			
		if(las_command == 3)
			{
			if (ftell(las_file_d) == 0)		
				{
				printf("Вы находитесь в начале файла!!\n");			
				continue;
				}							
				
			fseek(las_file_d, ftell(las_file_d) - sizeof(struct las_data), SEEK_SET);
			
			fread(las_values, sizeof(struct las_data), 1, las_file_d);
			printf("Название материала: %s Цена: %d Количество: %d Стоимость: %d\n",
				las_values->las_material_name, 
				las_values->las_price, 
				las_values->las_count, 
				las_values->las_cost);	
				
			fseek(las_file_d, ftell(las_file_d) - sizeof(struct las_data), SEEK_SET);			
			}
			
		if(las_command == 4)			
			fseek(las_file_d, 0, SEEK_END);	
						
		if(las_command == 9)			
			return(0);		
					
		if(las_command != 1 && las_command != 2 && las_command != 3 && las_command != 4 && las_command != 9)
			{
			printf("Неверная комманда!!!\nСписок комманд для ввода:\n");
			printf("1 - начало файла\n");
			printf("2 - вперед\n");
			printf("3 - назад\n");
			printf("4 - в конец файла\n");
			printf("9 - выход из программы\n");
			}
		}	
	
	free(las_values);
		
	return(0);
}
