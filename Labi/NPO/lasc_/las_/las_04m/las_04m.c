#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*	 ���������� 4 (fio_04m). ������ � ��������� � �����
     ��� ������������� ���������� �������� ������� �� 100 ��������� � ���������� 
�� ���� ������ ���� � ������� � ������, ���������� ��������� � ����� �� ������� 
�� ������� ���� �� ����� ������� � �������� ��������� ������ *
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
	
	printf("=��� �.�.= \t\t =las_04m= \n");	
	printf("=���������� 4 (las_04m). ������ � ��������� � �����= \n");
	printf("----------------------------------------------------------------\n");	
			
	las_current_index = 0;
	while(true)
		{
		printf("~~~~~~~~~~~~~~\n���� ����������:\n~~~~~~~~~~~~~~\n");
		printf("������� �������� ���������: ");
		scanf("%s", las_material_name[las_current_index]);
		
		if(las_material_name[las_current_index][0] == '*')		
			break;
				
		printf("������� ����: ");
		scanf("%d", &las_price[las_current_index]);
		
		printf("������� ����������: ");
		scanf("%d", &las_count[las_current_index]);
		
		las_cost[las_current_index] = 
			las_count[las_current_index] * las_price[las_current_index];
		
		printf("~~~~~~~~~~~~~~\n����� ����������:\n~~~~~~~~~~~~~~\n");
		printf("�������� ���������:%s ����:%d ����������:%d ���������:%d\n",
			las_material_name[las_current_index],
			las_price[las_current_index], 
			las_count[las_current_index], 
			las_cost[las_current_index]);
		
		las_current_index += 1;
		
		printf("----------------------------------------------------------------\n");
		}	
		
	return(0);
}
