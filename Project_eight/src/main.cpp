#include<iostream>
#include<string>
#include<vector>
//����Ϊʲô�ú���ָ��
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
//���lamuta����
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

	//����Ϊʲô�ú���ָ��
	char* str[] = { (char[])"get",(char[])"not" };//charָ������ÿ��str[i]����һ��ָ�룬str����ָ������ĵ�ַ
    char* adress= str[0];
	 *((char *)(str[0]+1)) = 'o';
	std::cout << str[0] << std::endl;
	std::string Data[] = { "firstly","second","third","forth"};//������charָ�����飬string�������Ƕ�������,������DataΪָ�룬Data[i]Ϊ���󣬶���Ļ��ù��캯������Ĳ�;
	unsigned int size = sizeof(Data) / sizeof(Data[0]);
	using PMove = void(const std::string&);
	PMove* ptr[] = {MoveA ,MoveB,MoveC,MoveD };
	Match(Data, ptr, size);


	//���lamuta����
	int l = 0;
	const std::vector<int> values = {1,2,3,4,5};
	ForEach(values, [](int n) {	std::cout << n<< std::endl; });
	std::cin.get();
}