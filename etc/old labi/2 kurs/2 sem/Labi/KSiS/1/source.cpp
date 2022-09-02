#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<chrono>

void RepSymASM(char* inputstr) {	//замена символов средствами ассемблерной вставки
	__asm {
		mov edx, inputstr	//помещаем начало строки в EDX
		
		replacingF:			//первая (First) стадия
			mov [edx], '+'	//заменяем символ строки на * по адресу EDX
			inc edx			//переходим на следующий символ
			cmp [edx], 0	//сравниваем символ с символом-терминатором (ищем конец строки)
			je breakReplacing //если символ-терминатор, заканчиваем замену
			jmp replacingS	  //если не символ-терминатор, переход во вторую стадию
		
		replacingS:				//вторая (Second) стадия
			inc edx				//не трогая текущий, переходим на следующий символ
			cmp [edx], 0		//сравниваем символ с символом-терминатором (ищем конец строки)
			je breakReplacing	//если символ-терминатор, заканчиваем замену
			jmp replacingF		//если не символ-терминатор, переход в первую стадию
		
		breakReplacing: //конец замены
	}
}

void RepSymCPP(char* inputstr) { //замена символов средствами C++
	for (int x = 0; x < strlen(inputstr); x++) {
		inputstr[x] = '+';
		x++;
	}
}

void main() {
	char My_StringASM[] = "Hello world"; //строка для ассемблера
	char My_StringCPP[] = "Hello world"; //строка для С++
	
	//запуск отсчёта (ассемблер)
	auto startASM = std::chrono::high_resolution_clock::now();
	RepSymASM(My_StringASM); //Replace Symbols (Assembly)
	//остановка отсчёта и вычисление разницы
	auto stopASM = std::chrono::high_resolution_clock::now();
	auto durationASM = std::chrono::duration_cast<std::chrono::nanoseconds>(stopASM - startASM);

	//запуск отсчёта (с++)
	auto startCPP = std::chrono::high_resolution_clock::now();
	RepSymCPP(My_StringCPP); //Replace Symbols (C++)
	//остановка отсчёта и вычисление разницы
	auto stopCPP = std::chrono::high_resolution_clock::now();
	auto durationCPP = std::chrono::duration_cast<std::chrono::nanoseconds>(stopCPP - startCPP);

	//вывод результатов (ассемблер)
	std::cout << "(ASM) New String: ";
	for (int x = 0; x < sizeof(My_StringASM) / sizeof(char); x++) {
		std::cout << My_StringASM[x];
	}	std::cout << "\n";
	std::cout << "(ASM) Elapsed time: " << durationASM.count() << " nanoseconds" << std::endl;
	
	//вывод результатов (с++)
	std::cout << "\n(CPP) New String: ";
	for (int x = 0; x < sizeof(My_StringCPP) / sizeof(char); x++) {
		std::cout << My_StringCPP[x];
	}	std::cout << "\n";
	std::cout << "(CPP) Elapsed time: " << durationCPP.count() << " nanoseconds" << std::endl;

	system("pause"); //пауза
}