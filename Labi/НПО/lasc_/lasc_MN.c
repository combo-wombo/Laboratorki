#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

#include "lasc_H.h"

int main() 
{
	
int 	lasc_wk;
	
    setlocale(0, "");

    while(true)
		{
			
		printf(" lasc_mn ��� �.�. \t ����������� �� � \n\n");

		printf(" ��������� ��������� \n");
		printf("\t 11 - ���� ������� ���� \n");
		printf("\t 12 - ���� � �������� ��������� ���������� (��) \n");

		printf(" ������ � �������� ��������� \n");
		printf("\t 21 - �������� �� \n");
		printf("\t 22 - ����. �� �� �� \n");
		printf("\t 23 - �������� �� \n");

		printf(" ���������� ���������� \n");
		printf("\t 31 - ����������� �������� ���� \n");
		printf("\t 32 - ��������-��������� ��������� \n");
		printf("\t 33 - ���������� ��������� (��������) \n");
		printf("\t 34 - ������-����� (��������) \n");

		printf(" ���������  \n");
		printf("\t 41 - ������� �������� (���) \n");
		printf("\t 42 - ��������� ���� \n");

		printf(" ������ \n");
		printf("\t 51 - ����� (��������) \n");
		printf("\t 52 - �������������� (��������) \n");

		printf(" ����� \n");
		printf("\t 61 - ����� \n");
		
		scanf("%i", &lasc_wk);
		
		if(lasc_wk == 11) 
			{
			lasc_nst_st();
			continue;	
			}
			
		if(lasc_wk == 12) 
			{
			lasc_pd();
			continue;	
			}
			
		if(lasc_wk == 21) 
			{
			lasc_rj();
			continue;	
			}
			
		if(lasc_wk == 22) 
			{
			lasc_jtk();
			continue;	
			}
			
		if(lasc_wk == 23) 
			{
			lasc_ks();
			continue;	
			}
			
		if(lasc_wk == 31) 
			{
			lasc_nst_si();
			continue;	
			}
			
		if(lasc_wk == 32) 
			{
			lasc_osv();
			continue;	
			}
			
		if(lasc_wk == 33) 
			{
			lasc_bv();
			continue;	
			}
			
		if(lasc_wk == 34) 
			{
			lasc_jo();
			continue;	
			}
			
		if(lasc_wk == 41) 
			{
			lasc_txo();
			continue;	
			}
			
		if(lasc_wk == 42) 
			{
			lasc_nst_sf();
			continue;	
			}	
			
		if(lasc_wk == 51) 
			{
			lasc_ac();
			continue;	
			}
			
		if(lasc_wk == 52) 
			{
			lasc_av();
			continue;	
			}
			
		if(lasc_wk == 61) 
			{
			return 0;
			}
			
		printf("\n �������� ���� \n");	
		
		}
	
    getch();
	return(0);
}
