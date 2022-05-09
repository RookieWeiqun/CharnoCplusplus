#include<iostream>
#include<string>
#include<vector>
//解释为什么用函数指针
void MoveA(const std::string& data1)
{
	std::cout << data1 << std::endl;
}
void MoveB(const std::string& data2)
{
	std::cout << data2 << std::endl;
}
void MoveC(const std::string& data3)
{
	std::cout << data3 << std::endl;
}
void MoveD(const std::string &data4)
{
	std::cout << data4 << std::endl;
}
void Match(const std::string* Data, void(*ptr[])(const std::string&),unsigned int size)
{
	for(unsigned int i = 0; i < size; i++)
	{
		ptr[i](Data[i]);
	}
}
//理解lamuta函数
//void LogFuc(int value)
//{
//	std::cout << value << std::endl;
//}
void ForEach(std::vector<int> values,void(*log)(int))
{
	for (int value : values)
		log(value);
}
int main()
{

	//解释为什么用函数指针
	char* str[] = { (char[])"get",(char[])"not" };//char指针数组每个str[i]代表一个指针，str代表指针数组的地址
    char* adress= str[0];
	 *((char *)(str[0]+1)) = 'o';
	std::cout << str[0] << std::endl;
	std::string Data[] = { "firstly","second","third","forth"};//区别于char指针数组，string构建的是对象数组,数组名Data为指针，Data[i]为对象，对象的话用构造函数增添改查;
	unsigned int size = sizeof(Data) / sizeof(Data[0]);
	using PMove = void(const std::string&);
	PMove* ptr[] = {MoveA ,MoveB,MoveC,MoveD };
	Match(Data, ptr, size);


	//理解lamuta函数
	int l = 0;
	const std::vector<int> values = {1,2,3,4,5};
	ForEach(values, [](int n) {	std::cout << n<< std::endl; });
	std::cin.get();
}