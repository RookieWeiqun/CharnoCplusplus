#include<iostream>
#include<string>
class Entity
{
private:
	int m_x, m_y;
	static int number;
	std::string m_name;
public:
	
	Entity(int x, int y,std::string name):m_x(x),m_y(y),m_name(name)
	{
		std::cout << "Entity�����ѱ�������" << std::endl;
	};
	void move(int x, int y)
	{
		m_x += x;
		m_y += y;
	}
	 const std::string getName() const 
	{
		 return  m_name;
	}
	  std::string& changeName(const std::string &name)//�ȿ�������name�ı䣬Ҳ���Է���name����main�иı�m_name��ֵ��
	 {
		  m_name = name;
		  return  m_name;
	  }
	 void getPos() const//�ٴ�������const˵��thisָ��Ϊconst Entity*this����ָ��Ŀռ�Ϊ������getName����Ϊconst��  
	{
 		std::cout << this->getName()<< "���ڵ�λ��Ϊx=" << m_x << " y=" << m_y << std::endl;
	};

};
int Entity::number = 0;
int main()
{
	Entity e(1,1,"Duncan");
	std::string name0 =e.getName();	//��Ϊû���������Զ�name0��������ı�e�����е�m_name�����֣�
	name0.at(1) = 'e';
	std::cout << "����Ϊ��" << name0 << std::endl;
	e.getPos();

	std::string &name1 = e.changeName("Park");//��Ϊ����,���Զ�name1������ı�e�����е�m_name�����֣�
	name1.at(1) = 'e';
	std::cout << "����Ϊ��" << name1 << std::endl;
	e.getPos();
	std::cin.get();
}