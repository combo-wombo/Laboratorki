#include "Personel.h"
Personel::Personel() {
	std::cout << "Using a default constructor." << std::endl;
	this->set((char*)"Default", 0, 0);
}
Personel::Personel(char* newName, int newId, int newLevel) {
	std::cout << "Using a constructor with parameters." << std::endl;
	this->set(newName, newId, newLevel);
}
Personel::Personel(const Personel& refObj) {
	std::cout << "Using a copying constructor." << std::endl;
	this->set((char*)refObj.name, refObj.fabId, refObj.level);
}
Personel::~Personel() {
	std::cout << "Executing a destructor of a Personel object." << std::endl;
}
char* Personel::getName() {
	return this->name;
}
int Personel::getId() {
	return this->fabId;
}
int Personel::getLevel() {
	return this->level;
}
void Personel::setName(char* newName) {
	for (int i = 0; i < 25; i++) {
		this->name[i] = newName[i];
	}
}
void Personel::setId(int newId) {
	this->fabId = newId;
}
void Personel::setLevel(int newLevel) {
	this->level = newLevel;
}
void Personel::set(char* newName, int newId, int newLevel) {
	this->setName(newName);
	this->setId(newId);
	this->setLevel(newLevel);
}