#include <iostream>
#include <iomanip>
#include <string.h>
#include "errors.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "6. H������� ���������, � ������� ������� �������� �������: ������ � ��������� (������������� ����������, ������� ���������������, ����������� ������������� ��������, ����������� �������� � ����������). ������� ����� ��� �������� ��������� ������ (������� ���������� �� ������� �����), � ������� ����������� �������� �[ ]�. ��� �������� ������ � ��� �������� ����������� �������� �==�, �!=�, �=�. ������������������ ������ ����������.\n" << std::endl;

	AccessError AError("������������ ����������");
	TranslateError TError1("������ �������������� 1");
	TranslateError TError2("������ �������������� 2");
	ValueTranslateError VTError("���������� ������������� ��������");
	InterfaceTranslateError ITError("���������� �������� � ����������");
	ErrorArray EA;



	std::cout << "\n������ ���������:" << endl;
	EA.AddToList(&AError);
	EA.AddToList(&TError1);
	EA.AddToList(&TError2);
	EA.AddToList(&VTError);
	EA.AddToList(&ITError);
	EA.PrintArray();
	
	std::cout << "\n���������� �������� [] ��� ������:" << endl;
	EA[2];
	EA[1];
	std::cout << "\n���������� �������� ��������� (==) � ������������� (=): \n�� �������������:" << endl;
	std::cout << (TError1 == TError2) << std::endl;
	TError1 = TError2;
	std::cout << "����� �������������:" << endl;
	std::cout << (TError1 == TError2) << std::endl;
	std::cout << "���������� ����������� (!=):" << endl;
	std::cout << (TError1 != TError2) << endl;
	return 0;
}
