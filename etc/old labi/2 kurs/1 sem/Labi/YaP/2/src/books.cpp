#include <iostream>
#include "books.h"
using namespace std;


PrintItem::PrintItem(const char* name, float price, bool isAdd) :
    name(name), price(price) {    
    if (isAdd) Add();
    cout << "������ PrintItem \"" << name << "\"\n";
}
PrintItem::~PrintItem() { cout << "����� PrintItem \"" << name << "\"\n"; }
void PrintItem::Add() {
    PrintItem** temp = items;
    items = new PrintItem * [count + 1];
    for (int i = 0; i < count; i++) items[i] = temp[i];
    items[count] = this; count++;
}
void PrintItem::listItems() {
    cout << "\n=========================================\n";
    for (int i = 0; i < count; i++) items[i]->Print();
    cout << "=========================================\n" << endl;
}

Magazine::Magazine(const char* name, float price, const char* publisher) : PrintItem(name, price, false), publisher(publisher) { cout << "������ ������ \"" << name << "\"\n"; }
Magazine::~Magazine() { cout << "����� ������ \"" << name << "\"\n"; }
void Magazine::Print() { cout << "������ � ���������: \"" << name << "\", �����: " << price << ", ���������: " << publisher << "\n"; }

Book::Book(const char* name, float price, const char* author) : PrintItem(name, price, true), author(author) {  cout << "������� ����� \"" << name << "\"\n"; }
Book::~Book() { cout << "������� ����� \"" << name << "\"\n"; }
void Book::Print() { cout << "����� � ���������: \"" << name << "\", �����: " << price << ", �������: " << author << "\n"; }

TextBook::TextBook(const char* name, float price, const char* author, int grade) : Book(name, price, author), grade(grade) {    cout << "������ ������� \"" << name << "\"\n"; }
TextBook::~TextBook() { cout << "����� ������� \"" << name << "\"\n"; }
void TextBook::Print() { cout << "������� � ���������: \"" << name << "\", �����: " << price << ", �������: " << author << ", �����: " << grade << "\n"; }
