#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "lasc_H.h"

void lasc_nst_sf() 
{
struct lasc_nst 	lasc_nst_sfi, lasc_nst_sfd;
FILE* 				lasc_nst_sff;

    lasc_nst_sff = fopen ("./lasc_C.db", "rb+");
    
    fseek(lasc_nst_sff, 0L, SEEK_SET);

    fread(&lasc_nst_sfd, sizeof(lasc_nst_sfd), 1, lasc_nst_sff);

    printf(" lasc_nst_sf Настройка APMа\n");
    printf("\t Название фирмы %10s \n", lasc_nst_sfd.lasc_nst_firma);
    printf("\t Введите название фирмы \t * - без изменений \n");
    
    scanf("%s", lasc_nst_sfi.lasc_nst_firma);

    if (lasc_nst_sfi.lasc_nst_firma[0] != '*')
        strcpy(lasc_nst_sfd.lasc_nst_firma, lasc_nst_sfi.lasc_nst_firma);

    fseek(lasc_nst_sff, 0L, SEEK_SET);

    fwrite(&lasc_nst_sfd, sizeof(lasc_nst_sfd), 1, lasc_nst_sff);

    fclose(lasc_nst_sff);

    printf(" Нажмите любую клваишу \n");
    
    getch();
}
