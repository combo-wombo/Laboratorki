#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_13fr.h"

/*   ���������� 13(fio_13fr). ������ �����.
     �� ���� ��������� ���������� 11 ����������� ������  ����� ����������� 
����� fio_12xx c ������� ������� �� �������.

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data*	las_values;
FILE* 				las_file_d;		
		
	system("chcp 1251");
	system("cls");
			
	printf("=��� �.�.= \t\t =las_13fr= \n");
	printf("=���������� 13(las_13fr). ������ �����.= \n");
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
		
		printf("�������� ���������: %s ����: %d ����������: %d ���������: %d\n",
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
