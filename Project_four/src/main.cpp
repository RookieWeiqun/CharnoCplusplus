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
		std::cout << "Entity对象已被创建！" << std::endl;
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
	  std::string& changeName(const std::string &name)//既可以输入name改变，也可以返回name后在main中改变m_name的值；
	 {
		  m_name = name;
		  return  m_name;
	  }
	 void getPos() const//再此声明的const说明this指针为const Entity*this，它指向的空间为常量，getName函数为const型  
	{
 		std::cout << this->getName()<< "现在的位置为x=" << m_x << " y=" << m_y << std::endl;
	};

};
int Entity::number = 0;
int main()
{
	Entity e(1,1,"Duncan");
	std::string name0 =e.getName();	//因为没有引用所以对name0操作不会改变e对象中的m_name的名字；
	name0.at(1) = 'e';
	std::cout << "名字为：" << name0 << std::endl;
	e.getPos();

	std::string &name1 = e.changeName("Park");//因为引用,所以对name1操作会改变e对象中的m_name的名字；
	name1.at(1) = 'e';
	std::cout << "名字为：" << name1 << std::endl;
	e.getPos();
	std::cin.get();
}