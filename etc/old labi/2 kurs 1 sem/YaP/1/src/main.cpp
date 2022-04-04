#include "exam.h"


int main() {
    setlocale(LC_ALL, "russian");
    cout << "�������� �������� ������ ������� ���������:" << endl;
        auto* exam_noParam = new Exam;   //��� ����������
        auto* exam_param = new Exam("Andrey", 2, 3);   //� �����������
        auto* exam_copy = new Exam(*exam_param);   //����������e
    
    cout << "\n\n������ � �������� ����� ������ ��������� �����: " << endl;
    cout << "\n����� �����: ";
        exam_noParam->SetName("������ ������");
        exam_noParam->Print();

    cout << "\n����� ����: ";
        exam_param->SetDate(9);
        exam_param->Print();

    cout << "\n\n������������� ��������� �� ������(���������) ������: " << endl;
        Exam* exam_ptr; //�������� ��������� �� ������
        exam_ptr = &*exam_copy; //���������� ������ ������� ������a
    cout << "\n������, �� ��������� ��� ����� ���������: ";   
        exam_copy->Print(); 
    cout << "\n��������� ������� ����� ���������...";    
        exam_ptr->SetName("������");
    cout << "\n����� ������� ����� ���������: ";    
        exam_ptr->Print();
    cout << "\n����� ������ �������: ";    
        exam_copy->Print();

    //������������� ��������� �� ����� ������
    cout << "\n\n������������� ��������� �� ����� ������: " << endl;
    cout << "\n�������� ��������� �� �����...";    
        void (Exam::* PrintP)() const;
    cout << "\n���������� ������ ���������...";    
        PrintP = &Exam::Print;
    cout << "\n����� ������� ����� ���������: ";    
        (exam_copy->*PrintP)();


    cout << "\n\n�������� ��������: \n";
        delete exam_noParam;
        delete exam_param;
        delete exam_copy;
}