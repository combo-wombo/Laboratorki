#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*
	 ���������� 3 (fio_03c). ������ � �����
     ������������� ���������� ������� � ������� � �������� �� ������� ���� 
�� ����� ������� � �������� ��������� ������ *
*/

int main(int argc, char** argv)
{	
	
char 	las_material_name[20];
int 	las_price;
int 	las_count;
int 	las_cost;		
		
	system("chcp 1251");
	system("cls");
	
	
	printf("=��� �.�.= \t\t =las_03c= \n");
	printf("=���������� 3 (las_03c). ������ � �����= \n");
	printf("----------------------------------------------------------------\n");	
			
	while(true)
		{
		printf("~~~~~~~~~~~~~~\n���� ����������:\n~~~~~~~~~~~~~~\n");
		
		printf("������� �������� ���������: ");
		scanf("%s", las_material_name);
				
		if(las_material_name[0] == '*')		
			break;		
		
		printf("������� ����: ");
		scanf("%d", &las_price);
		
		printf("������� ����������: ");
		scanf("%d", &las_count);
		
		las_cost = las_count * las_price;
		
		printf("~~~~~~~~~~~~~~\n����� ����������:\n~~~~~~~~~~~~~~\n");
		printf("�������� ���������:%s ����:%d ����������:%d ���������:%d\n",
			las_material_name, las_price, las_count, las_cost);		
		printf("----------------------------------------------------------------\n");
		}	
	
	return(0);
}


