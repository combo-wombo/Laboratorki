#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;

struct records { float result; char runner[22]; int year; float age; union { int pol; }runner_info; };
enum poltype { male = 1, female = 2 };
float getValue_float();
int getValue_int();
int getValue_ArraySize();
int getValue_pol();
void print_menu();
void err_msg1();
string getpoltype(records* M, int& I);
void outputall(records* M, int& N);
void inputall(records* M, int& N);
void createfile(records* M, int& N);
void openfile(records* M, int& N);
void addelement(records* M, int& N);
void deleteelement(records* M, int& N);
void editline(records* M, int& N);
void sortall(records* M, int& N);
void addbefore(records* M, int& N);
void addafter(records* M, int& N);
