#include"head.h"
#include<iostream>
int a = 5;//可以在这，也可以在main函数中
void addFun() 
{
	a++;
	std::cout << "a在head里面的值为" << a << std::endl;
}