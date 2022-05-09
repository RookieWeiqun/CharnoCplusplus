#include<iostream>
#include"head.h"
int main()
{
	int b = 0;
	addFun();//将head里面a的值+1
	Function();
	b = a;
	std::cout << "a在main里面的值为" << a << std::endl;
	std::cout << "b的值为"<< b << std::endl;
	std::cin.get();
}