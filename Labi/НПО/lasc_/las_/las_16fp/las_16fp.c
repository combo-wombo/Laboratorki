#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_16fp.h"

/*	 ���������� 16(fio_16fp). ���������� �������.
     �� ��������� ���������� 11 ������� ��������� �������� ������ ��� ������� 
main � ������� ������������ � ���������� �������� �������.
* 
*/

int main(int argc, char** argv)
{	

struct las_data las_values[las_SIZE];
int 			las_current_index;		
	
	system("chcp 1251");
	system("cls");
	
	printf("=��� �.�.= \t\t =las_16fp= \n");	
	printf("=���������� 16(las_16fp). ���������� �������.= \n");	
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
