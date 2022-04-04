#include "kurs_functions.h"
int main() {
    setlocale(LC_ALL, "Russian"); SetConsoleOutputCP(1251); SetConsoleCP(1251);
    cout << "Вариант номер шесть. Массив данных – «Мировые рекорды в беге на 100 метров»." << endl;
    int N, truefalse, act, exec = 1;
    cout << "\nВведите N (количество записей): ";
    N = getValue_ArraySize();
    records* main_array = new records[N];
    inputall(main_array, N); outputall(main_array, N);
    while (exec > 0) {
        cout << "\nПродолжить выполнение программы? (1 - да, 0 - нет): ";
        truefalse = getValue_int();
        if (truefalse == 1) {
            print_menu();
            act = getValue_int();
            if (act == 0 || act == 1 || act == 2 || act == 3 || act == 4 || act == 5 || act == 6 || act == 7 || act == 8 || act == 9) {
                if (act == 0) { exec = 0; }
                if (act == 1) { openfile(main_array, N); }
                if (act == 2) { addelement(main_array, N); }
                if (act == 3) { outputall(main_array, N); }
                if (act == 4) { createfile(main_array, N); }
                if (act == 5) { editline(main_array, N); }
                if (act == 6) { deleteelement(main_array, N); }
                if (act == 7) { sortall(main_array, N); }
                if (act == 8) { addbefore(main_array, N); }
                if (act == 9) { addafter(main_array, N); }
            }
            else { err_msg1(); outputall(main_array, N); }
        }
        else { if (truefalse == 0) { exec = 0; } else { cout << "Введено неверное значение (число должно быть от 0 до 1), попробуйте ещё раз." << endl; } }
    }
    delete[] main_array; return 0;
}
