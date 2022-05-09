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
	string(const string& temp )//�����Լ��Ŀ������캯��
	{
		m_size = temp.m_size;
		p_buffer = new char[m_size + 1];
		for (unsigned int i = 0; i < m_size; i++)
		p_buffer[i] = temp.p_buffer[i];
		p_buffer[m_size] = 0;
		std::cout << "hello copy!" << std::endl;
	};
	//��ֹ�������캯����string(const string& temp) = delete;
	string() :p_buffer(nullptr),m_size(0){};
	char& operator [](const int& number)
	{
		return p_buffer[number];
	}
	string& operator=(const string &temp)//���������=�����Ϊɶ��ִ�У�����
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
 void strPrint(const string &string)//����������ý�����ÿ������캯��
 {
	 std::cout << string << std::endl;
 }
int main()
{
	string test("dog");//���ù��캯����
	string test1 = test;//���ÿ������캯����
	string test2;
	{
		string* test3 = new string("our");
		delete test3;//new �����Ķ������ʹ��delete��ɾ�����ϵĿռ䣩ʱ�ŵ���������������������new������ָ��Ҳ��Ҫdelete��
	}
	test2 = test;//�ȳ�ʼ��test2Ȼ����ܵ����������������������
	test1[0] = 'b';
	strPrint(test);
	strPrint(test1); 
	strPrint(test2);
	std::cin.get();
}