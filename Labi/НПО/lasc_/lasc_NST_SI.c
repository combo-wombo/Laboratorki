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

    printf(" lasc_nst_si \t ¬вод интервала и счета \n");

/***********/
    printf("\t »нтервал с дд мм гг  %i %i %i \n",
           lasc_nst_sid.lasc_nst_datas[0],
           lasc_nst_sid.lasc_nst_datas[1],
           lasc_nst_sid.lasc_nst_datas[2]);

    printf("\t ¬ведите день \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[0]);
    
    if (lasc_nst_sii.lasc_nst_datas[0] != 0)
        lasc_nst_sid.lasc_nst_datas[0] = lasc_nst_sii.lasc_nst_datas[0];

    printf("\t ¬ведите мес€ц \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[1]);
    
    if (lasc_nst_sii.lasc_nst_datas[1] != 0)
        lasc_nst_sid.lasc_nst_datas[1] = lasc_nst_sii.lasc_nst_datas[1];

    printf("\t ¬ведите год \t 0 - без изменений \n");
    scanf("%i", &lasc_nst_sii.lasc_nst_datas[2]);
    
    if (lasc_nst_sii.lasc_nst_datas[2] != 0)
        lasc_nst_sid.lasc_nst_datas[2] = lasc_nst_sii.lasc_nst_datas[2];

/***********/
    printf("\t »нтервал до дд мм гг  %i %i %i \n",
           lasc_nst_sid.lasc_nst_datado[0],
           lasc_nst_sid.lasc_nst_datado[1],
           lasc_nst_sid.lasc_nst_datado[2]);

    printf("\t ¬ведите день \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[0]);
    
    if (lasc_nst_sii.lasc_nst_datado[0] != 0)
        lasc_nst_sid.lasc_nst_datado[0] = lasc_nst_sii.lasc_nst_datado[0];

    printf("\t ¬ведите мес€ц \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[1]);
    
    if (lasc_nst_sii.lasc_nst_datado[1] != 0)
        lasc_nst_sid.lasc_nst_datado[1] = lasc_nst_sii.lasc_nst_datado[1];

    printf("\t ¬ведите год \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_datado[2]);
    
    if (lasc_nst_sii.lasc_nst_datado[2] != 0)
        lasc_nst_sid.lasc_nst_datado[2] = lasc_nst_sii.lasc_nst_datado[2];

    printf("\t —чет:  %i \n", lasc_nst_sid.lasc_nst_s);
    printf("\t Ќазвание счета:  %10s \n", lasc_nst_sid.lasc_nst_sn);

    printf("\t ¬ведите счет \t 0 - без изменений \n");
    
    scanf("%i", &lasc_nst_sii.lasc_nst_s);
    
    if (lasc_nst_sii.lasc_nst_s != 0)
        lasc_nst_sid.lasc_nst_s = lasc_nst_sii.lasc_nst_s;

    printf("\t ¬ведите название счета \t * - без изменений \n");
    
    scanf("%s", lasc_nst_sii.lasc_nst_sn);

    if (lasc_nst_sii.lasc_nst_sn[0] != '*')
        strcpy (lasc_nst_sid.lasc_nst_sn, lasc_nst_sii.lasc_nst_sn);

    fclose(lasc_nst_sif);

    lasc_nst_sif = fopen("./lasc_C.db", "wb+");

    fwrite(&lasc_nst_sid, sizeof(lasc_nst_sid), 1, lasc_nst_sif);

    fclose(lasc_nst_sif);

    printf(" Ќажмите любую клавишу \n");
    getch();
}
