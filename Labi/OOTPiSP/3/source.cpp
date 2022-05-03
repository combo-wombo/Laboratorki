#include "Personel.h"
int main() {
	Personel pers1;
	Personel pers2((char*)"Nigga", 25, 3);
	Personel pers3(pers2);

	char*(Personel::*myptr)(); //pointer definition
	myptr = &Personel::getName; //setting up a pointer
	std::cout << "Default: " << pers1.getName() << std::endl;
	std::cout << "With param: " << pers2.getName() << std::endl;
	std::cout << "Copy: " << pers3.getName() << std::endl;
	std::cout << "Pointer: " << (pers2.*myptr)() << std::endl;
	return 0;
}