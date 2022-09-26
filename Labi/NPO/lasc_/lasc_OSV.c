#define lasc_kswd 0x8000
#define lasc_kswr 0x4000

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <stdbool.h>

#include "lasc_H.h"

void lasc_osv() 
{
long 				lasc_l;
int 				lasc_nrec, lasc_mrec;
int 				lasc_ks_rubdb_sum;
int 				lasc_ks_rubkr_sum;
struct lasc_nst 	lasc_nst_sd;
struct lasc_ks_s 	lasc_ks_sd;
FILE* 				lasc_nst_sf;
FILE* 				lasc_ks_sf;
FILE* 				lasc_osv_sf;
char 				c;

    lasc_nst_sf = fopen ("./lasc_C.db", "rb+");
    fseek(lasc_nst_sf, 0L, SEEK_SET);

    fread(&lasc_nst_sd, sizeof(lasc_nst_sd), 1, lasc_nst_sf);
    fclose(lasc_nst_sf);

    lasc_osv_sf = fopen("./lasc_OSV.txt", "w");
    fprintf(lasc_osv_sf, "%85s\n", "");
    fprintf(lasc_osv_sf, "%4s%-20.20s%8s%s%13s%s%2s\n", "", "=Lud A.S.=", "", "oborotno-saldovaa vedomost", "", "=lasc_krsoo=", "");
    fprintf(lasc_osv_sf, "%8s%s%4s%4i%13s%s%4s%2i.%2i.%4i%10s%2i.%2i.%4i     \n",
            "",
            "schet",
            "",
            lasc_nst_sd.lasc_nst_s,
            "",
            "interval s",
            "",
            lasc_nst_sd.lasc_nst_datas[0],
            lasc_nst_sd.lasc_nst_datas[1],
            lasc_nst_sd.lasc_nst_datas[2],
            "      do    ",
            lasc_nst_sd.lasc_nst_datado[0],
            lasc_nst_sd.lasc_nst_datado[1],
            lasc_nst_sd.lasc_nst_datado[2]);
            
    fprintf(lasc_osv_sf, "%85s\n", "");
    fprintf(lasc_osv_sf, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(lasc_osv_sf, "\t data      | sae  | dokument   | schet | korr schet | vx | oborot db kr | isx      \n");
    fprintf(lasc_osv_sf, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(lasc_osv_sf, "%85s\n", "");
    lasc_ks_sf = fopen("./lasc_K.db", "rb");

    fseek(lasc_ks_sf, 0, SEEK_END);
    lasc_l = ftell(lasc_ks_sf);
    lasc_mrec = (int) (lasc_l / sizeof(lasc_ks_sd ) );

    lasc_ks_sf = fopen ("./lasc_K.db", "rb");

    lasc_nrec = 0;
    lasc_l = lasc_nrec * sizeof(lasc_ks_sd);
    fseek(lasc_ks_sf, lasc_l, SEEK_SET);

    lasc_nrec = 0;
    lasc_ks_rubdb_sum = 0;
    lasc_ks_rubkr_sum = 0;

    while(true)
		{
			
		lasc_nrec++;
		
		if (lasc_nrec > lasc_mrec)
			break;

		fread(&lasc_ks_sd, sizeof(lasc_ks_sd), 1, lasc_ks_sf);
		
		if((lasc_nst_sd.lasc_nst_datas[0] <= lasc_ks_sd.lasc_ks_data[0] && lasc_ks_sd.lasc_ks_data[0] <= lasc_nst_sd.lasc_nst_datado[0]) &&
		   (lasc_nst_sd.lasc_nst_datas[1] <= lasc_ks_sd.lasc_ks_data[1] && lasc_ks_sd.lasc_ks_data[1] <= lasc_nst_sd.lasc_nst_datado[1]) &&
		   (lasc_nst_sd.lasc_nst_datas[2] <= lasc_ks_sd.lasc_ks_data[2] && lasc_ks_sd.lasc_ks_data[2] <= lasc_nst_sd.lasc_nst_datado[2]))
			{
			
		if( lasc_nst_sd.lasc_nst_s == lasc_ks_sd.lasc_ks_s ){
		
		
				fprintf(lasc_osv_sf, "  %2i.%2i.%4i   %4s   %-4s%10s%4i%9s%4i%9s%5i%7s%5i%6s\n",
						lasc_ks_sd.lasc_ks_data[0],
						lasc_ks_sd.lasc_ks_data[1],
						lasc_ks_sd.lasc_ks_data[2],
						lasc_ks_sd.lasc_ks_sae,
						lasc_ks_sd.lasc_ks_dokk,
						"",
						lasc_ks_sd.lasc_ks_s,
						"",
						lasc_ks_sd.lasc_ks_ks,
						"",
						lasc_ks_sd.lasc_ks_rubdb,
						"",
						lasc_ks_sd.lasc_ks_rubkr,
						"");
						
				lasc_ks_rubdb_sum += lasc_ks_sd.lasc_ks_rubdb;
				lasc_ks_rubkr_sum += lasc_ks_sd.lasc_ks_rubkr;
				
				fprintf(lasc_osv_sf, "%22s%-4i%59s\n", "", lasc_ks_sd.lasc_ks_dokn, "");
				fprintf(lasc_osv_sf, "%22s%2i.%2i.%4i%53s\n",
						"",
						lasc_ks_sd.lasc_ks_dokd[0],
						lasc_ks_sd.lasc_ks_dokd[1],
						lasc_ks_sd.lasc_ks_dokd[2],
						"");
				fprintf(lasc_osv_sf, "%85s\n", "");
			}
		}
	}
    fclose(lasc_ks_sf);
    fprintf(lasc_osv_sf, "%85s\n", "");

    fprintf(lasc_osv_sf, "%39s%s%3s%5i%7s%5i%6s\n",
            "",
            "lasc_itogo po schetu",
            "",
            lasc_ks_rubdb_sum,
            "",
            lasc_ks_rubkr_sum,
            "");
            
    fprintf(lasc_osv_sf, "%85s\n", "");
    fclose(lasc_osv_sf);

    lasc_osv_sf = fopen("./lasc_OSV.txt", "r");
    printf("\n");
    
    c = fgetc(lasc_osv_sf);
    
    while (c != EOF)
		{
			
        printf ("%c", c);
        c = fgetc(lasc_osv_sf);
        
		}
    
    fclose(lasc_osv_sf);

    printf(" ������� ����� ������� \n");
    getch();
}
