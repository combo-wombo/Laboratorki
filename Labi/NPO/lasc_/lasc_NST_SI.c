#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "lasc_H.h"

void lasc_nst_si() 
{
struct lasc_nst 	lasc_nst_sii, lasc_nst_sid;
FILE  				*lasc_nst_sif;

    lasc_nst_sif = fopen ("./lasc_C.db", "rb+");

    fseek(lasc_nst_sif, 0L, SEEK_SET);

    fread(&lasc_nst_sid, sizeof(lasc_nst_sid), 1, lasc_nst_sif);

    printf(" lasc_nst_si \t ���� ��������� � ����� \n");

/***********/
    printf("\t �������� � �� �� ��  %i %i %i \n",
           lasc_nst_sid.lasc_nst_datas[0],
           lasc_nst_sid.lasc_nst_datas[1],
           lasc_nst_sid.lasc_nst_datas[2]);

    printf("\t ������� ���� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[0]);
    
    if (lasc_nst_sii.lasc_nst_datas[0] != 0)
        lasc_nst_sid.lasc_nst_datas[0] = lasc_nst_sii.lasc_nst_datas[0];

    printf("\t ������� ����� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[1]);
    
    if (lasc_nst_sii.lasc_nst_datas[1] != 0)
        lasc_nst_sid.lasc_nst_datas[1] = lasc_nst_sii.lasc_nst_datas[1];

    printf("\t ������� ��� \t 0 - ��� ��������� \n");
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[2]);
    
    if (lasc_nst_sii.lasc_nst_datas[2] != 0)
        lasc_nst_sid.lasc_nst_datas[2] = lasc_nst_sii.lasc_nst_datas[2];

/***********/
    printf("\t �������� �� �� �� ��  %i %i %i \n",
           lasc_nst_sid.lasc_nst_datado[0],
           lasc_nst_sid.lasc_nst_datado[1],
           lasc_nst_sid.lasc_nst_datado[2]);

    printf("\t ������� ���� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[0]);
    
    if (lasc_nst_sii.lasc_nst_datado[0] != 0)
        lasc_nst_sid.lasc_nst_datado[0] = lasc_nst_sii.lasc_nst_datado[0];

    printf("\t ������� ����� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[1]);
    
    if (lasc_nst_sii.lasc_nst_datado[1] != 0)
        lasc_nst_sid.lasc_nst_datado[1] = lasc_nst_sii.lasc_nst_datado[1];

    printf("\t ������� ��� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[2]);
    
    if (lasc_nst_sii.lasc_nst_datado[2] != 0)
        lasc_nst_sid.lasc_nst_datado[2] = lasc_nst_sii.lasc_nst_datado[2];

    printf("\t ����:  %i \n", lasc_nst_sid.lasc_nst_s);
    printf("\t �������� �����:  %10s \n", lasc_nst_sid.lasc_nst_sn);

    printf("\t ������� ���� \t 0 - ��� ��������� \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_s);
    
    if (lasc_nst_sii.lasc_nst_s != 0)
        lasc_nst_sid.lasc_nst_s = lasc_nst_sii.lasc_nst_s;

    printf("\t ������� �������� ����� \t * - ��� ��������� \n");
    
    scanf("%s", lasc_nst_sii.lasc_nst_sn);

    if (lasc_nst_sii.lasc_nst_sn[0] != '*')
        strcpy (lasc_nst_sid.lasc_nst_sn, lasc_nst_sii.lasc_nst_sn);

    fclose(lasc_nst_sif);

    lasc_nst_sif = fopen("./lasc_C.db", "wb+");

    fwrite(&lasc_nst_sid, sizeof(lasc_nst_sid), 1, lasc_nst_sif);

    fclose(lasc_nst_sif);

    printf(" ������� ����� ������� \n");
    getch();
}
