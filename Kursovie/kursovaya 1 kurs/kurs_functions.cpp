#include "kurs_functions.h"

string getpoltype(records* M, int& I) {
    string shtring;
    if (M[I].runner_info.pol == male) { return shtring = "�������"; }
    if (M[I].runner_info.pol == female) { return shtring = "�������"; }
    if (M[I].runner_info.pol != male && M[I].runner_info.pol != female) {
        return shtring = "ERROR01";
    }
}
float getValue_float() {
    float a; string msg = "�������� ������ ���� ������";
    while (true) {
        cin >> a; if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "������������ ���� �������� (" << msg << "), ���������� ��� ���.\n";
        }
        else { cin.ignore(32767, '\n'); return a; }
    }
}
int getValue_int() {
    int a; string msg = "�������� ������ ���� ������";
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "������������ ���� �������� (" << msg << "), ���������� ��� ���.\n";
        }
        else { cin.ignore(32767, '\n'); return a; }
    }
}
int getValue_pol() {
    int a; string msg = "�������� ������ ���� ������";
    while (true) {
        while (true) {
            cin >> a; if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "������������ ���� �������� (" << msg << "), ���������� ��� ���.\n";
            }
            else { cin.ignore(32767, '\n'); break; }
        }
        if (a == 1 || a == 2) { return a; }
        else { cout << "������������ ���� �������� (����� ����� ���� ����� 1, ���� 2), ���������� ��� ���.\n"; }
    }
}
int getValue_ArraySize() {
    int a; string msg = "�������� ������ ���� ������";
    while (true) {
        while (true) {
            cin >> a; if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "������������ ���� �������� (" << msg << "), ���������� ��� ���.\n";
            }
            else { cin.ignore(32767, '\n'); break; }
        }
        if (a != 0) { return a; }
        else { cout << "������������ ���� �������� (����� ����� ���� ������ ����), ���������� ��� ���.\n"; }
    }
}
void print_menu() {
    cout << "\n�������� ��������: " << endl;
    cout << " 0. ����� �� ���������" << endl;
    cout << " 1. ���� ���������� �� ���������� ����� � ������ ���������� �� ������" << endl;
    cout << " 2. ���������� ����� ��������� � ����� �������" << endl;
    cout << " 3. �������� ���� ��������� �������" << endl;
    cout << " 4. ����� ���������� �� ������� � ��������� ����" << endl;
    cout << " 5. ������������� ����� ���������� ��������" << endl;
    cout << " 6. �������� ���������� ��������" << endl;
    cout << " 7. ���������� ������� �� ��������� ����" << endl;
    cout << " 8. ������� ������ �������� ����� ��������� ���������" << endl;
    cout << " 9. ������� ������ �������� ����� ���������� ��������" << endl;
    cout << "\n�������� (0-9): ";
}
void err_msg1() {
    system("cls"); cout << "\n������� �������� �������� (����� ������ ���� �� 0 �� 9), ���������� ��� ���.\n" << endl;
    system("pause"); system("cls");
}
void outputall(records* M, int& N) {
    system("cls");
    cout << "\n=x================================ ����� ���� ��������. ===========================================x=" << endl;
    for (int i = 0; i < N; i++) {
        cout << "���. �" << left << setw(3) << i + 1 << " | " << "���-���: " << left << setw(6) << M[i].result << " | " << "�����: " << left << setw(21) << M[i].runner << " | " << "���: " << left << setw(4) << M[i].year << " | " << "�������: " << left << setw(3) << M[i].age << " | " << "���: " << getpoltype(M, i) << endl;
    }
    cout << "=x=================================================================================================x=" << endl;
}
void inputall(records* M, int& N) {
    system("cls");
    cout << "\n=x=============================== ���� �������. ================================x=" << endl;
    for (int i = 0; i < N; i++) {
        cout << "\n������ �" << i + 1 << ": " << endl;
        cout << "������� ��������� ������ (xx.xx): ";
        M[i].result = getValue_float();
        cout << "������� ������ �������: ";
        cin.getline(M[i].runner, 21);
        cout << "������� ��� ��������� ������� (yyyy): ";
        M[i].year = getValue_int();
        cout << "������� ������� �����������: ";
        M[i].age = getValue_float();
        cout << "������� ��� ����������� (1 - �������, 2 - �������): ";
        M[i].runner_info.pol = getValue_pol();
    }
    cout << "=x==============================================================================x=" << endl;
}
void createfile(records* M, int& N) { //output.txt
    outputall(M, N); string path;
    cout << "\n������� ���� � �������� ����� ��� ������ (����. D:\\output.txt): "; cin >> path;
    ofstream out; out.open(path);
    for (int i = 0; i < N; i++) {
        out << "���. �" << left << setw(3) << i + 1 << " | " << "���-���: " << left << setw(6) << M[i].result << " | " << "�����: " << left << setw(21) << M[i].runner << " | " << "���: " << left << setw(4) << M[i].year << " | " << "�������: " << left << setw(3) << M[i].age << " | " << "���: " << getpoltype(M, i) << endl;
    } out.close();
    cout << "�������� ����� ���������." << endl; system("pause"); outputall(M, N);
}
void openfile(records* M, int& N) { //input.txt
    outputall(M, N); string path, replace_line; int i2 = 0;
    cout << "\n������� ���� � �������� ����� ��� �������� (����. D:\\input.txt): ";
    cin >> path; ifstream in; in.open(path);
    if (!in.is_open()) {
        cout << "\n\n==(!)== ���� �� ������, ���� �� ����� ���� ������! ==(!)==\n\n������� � ������� ����...\n";
        system("pause"); in.close(); return;
    }
    in >> i2; records* mas2 = new records[i2];
    for (int i = 0; i < i2; i++) {
        in >> mas2[i].result;
        in >> mas2[i].runner;
        in >> mas2[i].year;
        in >> mas2[i].age;
        in >> mas2[i].runner_info.pol;
    }
    in.close();
    for (int i = 0; i < i2; i++) {
        replace_line = mas2[i].runner;
        replace(replace_line.begin(), replace_line.end(), '_', ' ');
        strcpy_s(mas2[i].runner, replace_line.c_str());
    }
    N = i2;
    for (int i = 0; i < N; i++) {
        M[i] = mas2[i];
    }
    cout << "�������� ����� ���������." << endl;
    system("pause"); outputall(M, N);
    delete[] mas2;
}
void addelement(records* M, int& N) {
    outputall(M, N); N = N + 1;
    records* M2 = new records[N];
    for (int i = 0; i < N - 1; i++) {
        M2[i] = M[i];
    }
    cout << "\n������ �" << N << ": " << endl;
    cout << "������� ��������� ������ (xx.xx): ";
    M2[N - 1].result = getValue_float();
    cout << "������� ������ �������: ";
    cin.getline(M2[N - 1].runner, 21);
    cout << "������� ��� ��������� ������� (yyyy): ";
    M2[N - 1].year = getValue_int();
    cout << "������� ������� �����������: ";
    M2[N - 1].age = getValue_float();
    cout << "������� ��� ����������� (1 - �������, 2 - �������): ";
    M2[N - 1].runner_info.pol = getValue_pol();
    for (int i = 0; i < N; i++) { M[i] = M2[i]; }
    cout << "\n���������� ���������." << endl;
    delete[] M2; outputall(M, N);
}
void deleteelement(records* M, int& N) {
    outputall(M, N); int del = 0;
    cout << "\n������� ����� ������, ������� ������ �������: ";
    del = getValue_int(); del = del - 1;
    if (del > (N - 1) || del < 0) {
        cout << "\n\n==(!)== ������� �������� �������� (����� �� ������� �������). ==(!)==\n\n������� � ������� ����...\n";
        system("pause"); return;
    }
    records* M2 = new records[N - 1];
    for (int i = 0; i < N; i++) {
        if (i < del) { M2[i] = M[i]; }
        if (i > del) { M2[i - 1] = M[i]; }
    }
    N--; for (int i = 0; i < N; i++) { M[i] = M2[i]; } cout << "������ �������." << endl;
    system("pause"); delete[] M2; outputall(M, N);
}
void editline(records* M, int& N) {
    outputall(M, N);
    records* M2 = new records[N];
    for (int i = 0; i < N; i++) {
        M2[i] = M[i];
    }
    int del; cout << "\n������� ����� ������, ������� ������ ���������������: ";
    del = getValue_int(); del = del - 1;
    if (del > (N - 1) || del < 0) {
        cout << "\n\n==(!)== ������� �������� �������� (����� �� ������� �������). ==(!)==\n\n������� � ������� ����...\n";
        system("pause"); delete[] M2; return;
    }
    cout << "\n������ �" << del + 1 << ": " << endl;
    cout << "������� ��������� ������ (xx.xx): ";
    M2[del].result = getValue_float();
    cout << "������� ������ �������: ";
    cin.getline(M2[del].runner, 21);
    cout << "������� ��� ��������� ������� (yyyy): ";
    M2[del].year = getValue_int();
    cout << "������� ������� �����������: ";
    M2[del].age = getValue_float();
    cout << "������� ��� ����������� (1 - �������, 2 - �������): ";
    M2[del].runner_info.pol = getValue_pol();
    for (int i = 0; i < N; i++) { M[i] = M2[i]; }
    cout << "\n�������������� ���������." << endl;
    delete[] M2; outputall(M, N);
}
void sortall(records* M, int& N) {
    records swap; float highest; int high, i;
    for (i = 0; i < N - 1; i++) {
        high = i;
        for (int j = i + 1; j < N; j++) {
            if (M[j].result < M[high].result)
                high = j;
        }
        records swap = M[i]; M[i] = M[high]; M[high] = swap;
    }
    cout << "���������� ���������. " << endl; outputall(M, N);
}
void addbefore(records* M, int& N) {
    outputall(M, N); int add;
    cout << "\n������� ����� ������, ����� ������� ������ �������� ����� �������: ";
    add = getValue_int(); add = add - 1;
    if (add > (N - 1) || add < 0) {
        cout << "\n\n==(!)== ������� �������� �������� (����� �� ������� �������). ==(!)==\n\n������� � ������� ����...\n";
        system("pause");
        return;
    }
    records* M2 = new records[N + 1];
    for (int i = 0; i < N; i++) {
        if (i < add) { M2[i] = M[i]; }
        if (i >= add) { M2[i + 1] = M[i]; }
    }
    cout << "\n������ �" << add + 1 << ": " << endl;
    cout << "������� ��������� ������ (xx.xx): ";
    M2[add].result = getValue_float();
    cout << "������� ������ �������: ";
    cin.getline(M2[add].runner, 21);
    cout << "������� ��� ��������� ������� (yyyy): ";
    M2[add].year = getValue_int();
    cout << "������� ������� �����������: ";
    M2[add].age = getValue_float();
    cout << "������� ��� ����������� (1 - �������, 2 - �������): ";
    M2[add].runner_info.pol = getValue_pol();
    N++; for (int i = 0; i < N; i++) { M[i] = M2[i]; } cout << "������ ���������." << endl; delete[] M2; outputall(M, N);
}
void addafter(records* M, int& N) {
    outputall(M, N); int add = 0;
    cout << "\n������� ����� ������, ����� ������� ������ �������� ����� �������: ";
    add = getValue_int(); add--;
    if (add > (N - 1) || add < 0) {
        cout << "\n\n==(!)== ������� �������� �������� (����� �� ������� �������). ==(!)==\n\n������� � ������� ����...\n";
        system("pause"); return;
    }
    records* M2 = new records[N + 1];
    for (int i = 0; i < N; i++) {
        if (i <= add) { M2[i] = M[i]; }
        if (i > add) { M2[i + 1] = M[i]; }
    }
    cout << "\n������ �" << add + 2 << ": " << endl;
    cout << "������� ��������� ������ (xx.xx): ";
    M2[add + 1].result = getValue_float();
    cout << "������� ������ �������: ";
    cin.getline(M2[add + 1].runner, 21);
    cout << "������� ��� ��������� ������� (yyyy): ";
    M2[add + 1].year = getValue_int();
    cout << "������� ������� �����������: ";
    M2[add + 1].age = getValue_float();
    cout << "������� ��� ����������� (1 - �������, 2 - �������): ";
    M2[add + 1].runner_info.pol = getValue_pol();
    N++; for (int i = 0; i < N; i++) { M[i] = M2[i]; } cout << "������ ���������." << endl; delete[] M2; outputall(M, N);
}
