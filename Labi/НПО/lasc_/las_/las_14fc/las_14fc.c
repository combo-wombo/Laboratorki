#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_14fc.h"

/*	 Упражнение 14(fio_14fc). Копирование файла.
     На базе исходных текстов упражнений 13 и 12 реализовать Чтение ранее 
полученного файла fio_12xx c выводом в файл fio_14xx.

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data* 	las_values;
FILE* 				las_source_file_d;	
FILE* 				las_dest_file_d;		
		
	system("chcp 1251");
	system("cls");
			
	printf("=Луд А.С.= \t\t =las_14fc= \n");
	printf("=Упражнение 14(las_14fc). Копирование файла.= \n");
	printf("----------------------------------------------------------------\n");	
	
	if ((las_source_file_d = fopen("las_12xx", "rb")) == NULL)
		{
        perror("Error occured while opening file");
        return 1;
		}
		
	if ((las_dest_file_d = fopen("las_14xx", "awb")) == NULL)
		{
        perror("Error occured while opening file");
        return 1;
		}
	
	while(!feof(las_source_file_d))
		{
		las_values = (struct las_data*)malloc(sizeof(struct las_data));
		if(fread(las_values, sizeof(struct las_data), 1, las_source_file_d) != 1)			
			break;				
			
		fwrite(las_values, sizeof(struct las_data), 1, las_dest_file_d);
		free(las_values);			
		}
	
    fclose(las_source_file_d);  
    fclose(las_dest_file_d);	  
		
	return(0);
}

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}
