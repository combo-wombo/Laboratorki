#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_11f.h"

/*	 ���������� 11 (fio_11f). ������ �� �������.
     ���������� ���������� 10 � �� ���� ��� ���������, ��  ����� �� ������� 
������ ���������� � ����� ������ 50

*/

void las_10fv(struct las_data* las_value);

int main(int argc, char** argv)
{	

struct las_data las_values[las_SIZE];
int 			las_current_index;
		
	system("chcp 1251");
	system("cls");
			
	printf("=��� �.�.= \t\t =las_11f= \n");
	printf("=���������� 11 (las_11f). ������ �� �������..= \n");
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
				
			printf("~~~~~~~~~~~~~~\n����� ����������:\n~~~~~~~~~~~~~~\n");		
			printf("�������� ���������: %s ����: %d ����������: %d ���������: %d\n",
				las_values[las_current_index].las_material_name, 
				las_values[las_current_index].las_price, 
				las_values[las_current_index].las_count, 
				las_values[las_current_index].las_cost);		
			
			printf("----------------------------------------------------------------\n");	
			}
		 
		las_current_index += 1;
		}	
		
	return(0);
}

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}

