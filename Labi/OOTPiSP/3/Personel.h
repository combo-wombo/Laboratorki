/*3. КАДРЫ
имя – char*
номер цеха – int
разряд – int*/
const int LNAME = 25;
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <stdio.h>
class Personel {
private:
	char name[LNAME];
	int fabId;
	int level;
public:
	Personel();
	Personel(char*, int, int);
	Personel(const Personel & refObj);
	~Personel();

	char* getName();
	int getId();
	int getLevel();

	void setName(char*);
	void setId(int);
	void setLevel(int);
	void set(char*, int, int);
};