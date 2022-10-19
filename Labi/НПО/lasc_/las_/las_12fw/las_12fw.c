#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_12fw.h"

/*	 ���������� 12 (fio_12fw). ����� � ����.
     ���������� ���������� 11 � �� ���� ��� ���������, ��  ����� �� �������  
���������� �� ����� � ���������������� ���� fio_12xx.

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data		las_values[las_SIZE];
FILE* 				las_file_d;
int 				las_current_index;
		
	system("chcp 1251");
	system("cls");
			
	printf("=��� �.�.= \t\t =las_12fw= \n");
	printf("=���������� 12 (las_12fw). ����� � ����..= \n");
	printf("----------------------------------------------------------------\n");	
	
	las_current_index = 0;
	while (true)
		{
		printf("~~~~~~~~~~~~~~\n���� ����������:\n~~~~~~~~~~~~~~\n");		
		
		printf("������� �������� ���������: ");
		scanf("%s", las_values[las_current_index].las_material_name);
		
		if(las_values[las_current_index].las_material_name[0] == '*')	
			break;	
		
		printf("������� ����: ");
		scanf("%d", &las_values[las_current_index].las_price);
		
		printf("������� ����������: ");
		scanf("%d", &las_values[las_current_index].las_count);
		
		las_10fv(&las_values[las_current_index]);
		printf("----------------------------------------------------------------\n");
					
		if(las_values[las_current_index].las_cost > 50)
			{
									
			if ((las_file_d = fopen("las_12xx", "awb")) == NULL)
				{
				perror("Error occured while opening file");
				return(1);
				}
			
			fwrite(&las_values[las_current_index], sizeof(struct las_data), 1, las_file_d);
			
			fclose(las_file_d);
			}
		 
		las_current_index += 1;
		}	
		
	return(0);
}

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}
