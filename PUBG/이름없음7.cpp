#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	//int x = 5;
	//std::cout<<x<<"\n";
	//std::cout<<&x<<"\n";//&�� ��1�� ������  
	//std::cout<<*&x<<"\n";//*�� �ּ��� �� ã�°�  
	
	int v = 70;
	double dv = 100;
	
	int* int_ptr = &v; 
	double* dou_ptr = &dv; 
	
	std::cout << &v << "\n";
	std::cout << &dv << "\n\n";
	
	std::cout << *&v << "\n";
	std::cout << *&dv << "\n";
}

