#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


/*	���������� 6 (fio_06s). ���������� ��������
     ���������� ���������� 2 � ��  ���� ��� ���������, �� ���������� �������� 
��� ������� ���������.

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
	
	printf("=��� �.�.= \t\t =las_06s= \n");
	printf("=���������� 6 (las_06s). ���������� �������� \n");
	printf("----------------------------------------------------------------\n");	
	
	printf("������� �������� ���������: ");
	scanf("%s", las_values.las_material_name);
	
	printf("������� ����: ");
	scanf("%d", &las_values.las_price);
	
	printf("������� ����������: ");
	scanf("%d", &las_values.las_count);
	
	las_values.las_cost = las_values.las_count * las_values.las_price;
	
	printf("----------------------------------------------------------------\n");	
	printf("�������� ���������:%s ����:%d ����������:%d ���������:%d\n",
		las_values.las_material_name, las_values.las_price, 
		las_values.las_count, las_values.las_cost);
	 
	printf("----------------------------------------------------------------\n");	
	
	printf("������� ����� ������\n");
	getch();
			
	return(0);
}
