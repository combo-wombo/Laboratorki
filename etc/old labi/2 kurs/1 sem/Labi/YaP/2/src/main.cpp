#include <iomanip>
#include "books.h"

int PrintItem::count = 0; PrintItem** PrintItem::items = nullptr;

int main() {
    setlocale(LC_ALL, "Russian"); //������� ����
    Magazine SportsMag("NBA Stars 2011", 9.99, "NBA Publishing ltd.");
    SportsMag.Add(); //���������� ������� �������� � ������, ��������� ����� ���������� ��� ��������
    Book CnP("������������ � ���������", 10.59, "�. �����������"); //�������� �����
    Book FnC("���� � ����", 5.69, "�. ��������"); //�������� �����
    TextBook Math3("����������", 3.33, "������������ ����������� ��", 3); //�������� �������

    PrintItem::listItems(); //����� ���������
}
