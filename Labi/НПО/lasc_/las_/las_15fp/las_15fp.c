#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "las_15fp.h"

/*	 ���������� 15(fio_15fp). ���������������� � �����.
     ������� ���� � ������� ������� ���������� (1 - ������ �����, 2 - ������, 
3 - �����, 4 - � ����� �����, 9 - ����� �� ���������) � ����������� 
���������������� � ����� fio_12xx � ������� �� ������� ����� ������. 

*/

int main(int argc, char** argv)
{		

FILE			*las_file_d;	

struct las_data *las_values;

int 			las_command;

	system("chcp 1251");
	system("cls");
		
	printf("=��� �.�.= \t\t =las_15fp= \n");	
	printf("=���������� 15(las_15fp). ���������������� � �����.= \n");	
	printf("----------------------------------------------------------------\n");	
			  
	las_file_d = fopen("las_12xx", "rb");
    if (las_file_d == NULL)
		{
        perror("Error occured while opening file");
        return(1);
		}    
    
    printf("����������:\n");
	printf("1 - ������ �����\n");
	printf("2 - ������\n");
	printf("3 - �����\n");
	printf("4 - � ����� �����\n");
	printf("9 - ����� �� ���������\n");
			
	las_values = (struct las_data*)malloc(sizeof(struct las_data));
	
	while (true)
		{
		scanf("%d", &las_command);
		
		if(las_command == 1)
			{
			rewind(las_file_d);	
			fread(las_values, sizeof(struct las_data), 1, las_file_d);
			printf("�������� ���������: %s ����: %d ����������: %d ���������: %d\n",
				las_values->las_material_name, 
				las_values->las_price, 
				las_values->las_count, 
				las_values->las_cost);
			}
			
		if(las_command == 2)
			{
			if(fread(las_values, sizeof(struct las_data), 1, las_file_d) == 1)
				{
				printf("�������� ���������: %s ����: %d ����������: %d ���������: %d\n",
					las_values->las_material_name, 
					las_values->las_price, 
					las_values->las_count, 
					las_values->las_cost);
				continue;
				}			
			printf("�� ���������� � ����� �����. \n");
			}
			
		if(las_command == 3)
			{
			if (ftell(las_file_d) == 0)		
				{
				printf("�� ���������� � ������ �����!!\n");			
				continue;
				}							
				
			fseek(las_file_d, ftell(las_file_d) - sizeof(struct las_data), SEEK_SET);
			
			fread(las_values, sizeof(struct las_data), 1, las_file_d);
			printf("�������� ���������: %s ����: %d ����������: %d ���������: %d\n",
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
			printf("�������� ��������!!!\n������ ������� ��� �����:\n");
			printf("1 - ������ �����\n");
			printf("2 - ������\n");
			printf("3 - �����\n");
			printf("4 - � ����� �����\n");
			printf("9 - ����� �� ���������\n");
			}
		}	
	
	free(las_values);
		
	return(0);
}
