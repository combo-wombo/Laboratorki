all: lasc

lasc: lasc_AC.o lasc_AV.o lasc_BV.o lasc_JO.o lasc_JTK.o lasc_KS.o lasc_MN.o lasc_NST_SF.o lasc_NST_SI.o lasc_NST_ST.o lasc_OSV.o lasc_PD.o lasc_RJ.o lasc_TXO.o
	gcc -o lasc lasc_AC.o lasc_AV.o lasc_BV.o lasc_JO.o lasc_JTK.o lasc_KS.o lasc_MN.o lasc_NST_SF.o lasc_NST_SI.o lasc_NST_ST.o lasc_OSV.o lasc_PD.o lasc_RJ.o lasc_TXO.o

lasc_AC.o: lasc_AC.c
	gcc -c lasc_AC.c

lasc_AV.o: lasc_AV.c
	gcc -c lasc_AV.c
	
lasc_BV.o: lasc_BV.c
	gcc -c lasc_BV.c
		
lasc_JO.o: lasc_JO.c
	gcc -c lasc_JO.c
			
lasc_JTK.o: lasc_JTK.c
	gcc -c lasc_JTK.c
			
lasc_KS.o: lasc_KS.c
	gcc -c lasc_KS.c

lasc_MN.o: lasc_MN.c
	gcc -c lasc_MN.c

lasc_NST_SF.o: lasc_NST_SF.c
	gcc -c lasc_NST_SF.c
	
lasc_NST_SI.o: lasc_NST_SI.c
	gcc -c lasc_NST_SI.c
	
lasc_NST_ST.o: lasc_NST_ST.c
	gcc -c lasc_NST_ST.c
		
lasc_OSV.o: lasc_OSV.c
	gcc -c lasc_OSV.c
		
lasc_PD.o: lasc_PD.c
	gcc -c lasc_PD.c
		
lasc_RJ.o: lasc_RJ.c
	gcc -c lasc_RJ.c
	
lasc_TXO.o: lasc_TXO.c
	gcc -c lasc_TXO.c
	
clean:
	rm -rf *.o lasc
