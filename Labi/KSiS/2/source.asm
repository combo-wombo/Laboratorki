;statement: Текст содержит равное количество прописных латинских и прописных русских букв
;     true: кждую стрчную латнскую бкву сответсвующе прописной буквой,а прписную–строчной
;    false: Циклически  сдвинуть  текст  на K (константа)  позиций  влево  без  использования 
;           дополнительной памяти, реализовав следующий алгоритм: перевернуть подмассив из первых K символов; 
;           перевернуть оставшийся подмассив; перевернуть весь текст  
;===========================================================================================================
section .data
  entermsg db 'Enter your message: '
  enlen equ $ - entermsg
  resultmsg db 0xa, 'Final result: '
  reslen equ $ - resultmsg
  
  truemsg db 0xa, 'The statement is true! (jumping to func1)'
  trlen equ $ - truemsg
  
  falsemsg db 0xa, 'The statement is false. (jumping to func2)'
  fllen equ $ - falsemsg
section .bss
  input resb 100
  input2 resb 3
section .text
  global _start
	
textWelcome:
  mov edx, enlen
  mov ecx, entermsg
  mov ebx, 1
  mov eax, 4
  int 0x80
  ret
  
textTrue:
  mov edx, trlen
  mov ecx, truemsg
  mov ebx, 1
  mov eax, 4
  int 0x80
  ret

textFalse:
  mov edx, fllen
  mov ecx, falsemsg
  mov ebx, 1
  mov eax, 4
  int 0x80
  ret
  
textResult:
  mov edx, reslen
  mov ecx, resultmsg
  mov ebx, 1
  mov eax, 4
  int 0x80
  ret
  
input100:
  mov eax, 3
  mov ebx, 0
  mov ecx, input
  mov edx, 100
  int 80h
  ret
 
outInput:
  mov eax, 4
  mov ebx, 1
  mov ecx, input
  mov edx, 101
  int 80h
  ret
	
exit:
  mov ebx,0   ;process' exit code
  mov eax,1   ;(sys_exit)
  int 80h    ;kernel reads the eax register

_start:
  call textWelcome
  call input100
  call outInput
  call textTrue
  call textFalse
  call textResult
  call exit