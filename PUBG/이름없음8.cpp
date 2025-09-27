#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int a = 9;
	int* ptr = &a;
	
	std::cout << a << '\n';
	std::cout << &a << '\n';
	
	*ptr = 7;
	
	std::cout << a << '\n';
	std::cout << *ptr << '\n';
	std::cout << ptr << '\n';

}
