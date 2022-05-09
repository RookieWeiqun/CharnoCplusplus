#include<iostream>
#include<string>
class string 
{
private:
	 char* p_buffer;
	 unsigned int m_size;
public:
	string(const char* buffer)
	{  
		m_size = strlen(buffer);
		p_buffer = new char[m_size + 1];
		for (unsigned int i = 0; i < m_size; i++)
			p_buffer[i] = buffer[i];
		p_buffer[m_size] = 0;
	};
	string(const string& temp )//定义自己的拷贝构造函数
	{
		m_size = temp.m_size;
		p_buffer = new char[m_size + 1];
		for (unsigned int i = 0; i < m_size; i++)
		p_buffer[i] = temp.p_buffer[i];
		p_buffer[m_size] = 0;
		std::cout << "hello copy!" << std::endl;
	};
	//禁止拷贝构造函数：string(const string& temp) = delete;
	string() :p_buffer(nullptr),m_size(0){};
	char& operator [](const int& number)
	{
		return p_buffer[number];
	}
	string& operator=(const string &temp)//运算符重载=号这个为啥不执行？？？
	{
		m_size = temp.m_size;
		p_buffer = new char[m_size + 1];
		for (unsigned int i = 0; i < m_size; i++)
		p_buffer[i] = temp.p_buffer[i];
		p_buffer[m_size] = 0 ;
		return *this;
	}
	friend std::ostream& operator <<(std::ostream& steam, const string& x);
	~string() 
	{
		std::cout << "disconstruct function is called!" << std::endl;
		delete p_buffer;
	}
};
 std::ostream& operator <<(std::ostream& steam, const string& x)
{	
	steam << x.p_buffer ;
	return steam;
}
 void strPrint(const string &string)//如果不加引用将会调用拷贝构造函数
 {
	 std::cout << string << std::endl;
 }
int main()
{
	string test("dog");//调用构造函数；
	string test1 = test;//调用拷贝构造函数；
	string test2;
	{
		string* test3 = new string("our");
		delete test3;//new 创建的对象必须使用delete（删除堆上的空间）时才调用析构函数，而类中用new创建的指针也需要delete。
	}
	test2 = test;//先初始化test2然后才能调用重载运算符函数！！！
	test1[0] = 'b';
	strPrint(test);
	strPrint(test1); 
	strPrint(test2);
	std::cin.get();
}