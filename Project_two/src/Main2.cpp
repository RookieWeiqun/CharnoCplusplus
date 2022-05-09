#include<iostream>
#include<string>
class Entity
{
public:
	int m_x, m_y;
public:
	void move(int x, int y)
	{
		m_x += x;
		m_y += y;
		getPos();
	}
	Entity(int x, int y);
	Entity() {};
	static int number;//声明球员数量，用static变量，在这里只是声明了static，和extern类似，因是在编译的时候进行静态变量的内存分配，故需要在函数外进行静态变量的定义。
	virtual void getPos()
	{
		std::cout << "Entity现在的位置为x=" << m_x << " y=" << m_y << std::endl;
	};
	void getNmuber()
	{
		std::cout << "创建了"<<number<<"个球员"  << std::endl;
	};
};
int Entity::number=0;
Entity::Entity(int x, int y)
{
	m_x = x;
	m_y = y;
	getPos();
};
class Player : public Entity 
{
private:
	std::string * Playername;
public:
	Player(int x, int y, std::string* name):Entity()//没有：时默认调用无参Entity构造函数，如果在Entity中没有声明无参的构造函数，则需要手动继承有参Entity，要不然报错。
	{
		m_x = x;
		m_y = y;
		Playername = name;
		number++;
		getNmuber();
	};
	void getPos() override
	{
		std::cout <<"球员"<< *Playername << "现在的位置为x=" << m_x << " y=" << m_y <<std::endl;
	}
	void getPlayname()
	{
		std::cout << "新球员的名字为：" << *Playername << std::endl;
	}
};

int main()
{
	Entity* e = new Entity(1,1);
	std::string str = "dog";
	std::string * name = &str;
	Player player1(1,1,name);
	str = "TimDuncan";
	Player player2(2,1,name);
	player1.getPlayname();
	player2.move(3, 3);
	str = "Parker";
	Player* player3 = new Player(0, 1, name);
	player3->move(3,1);//因为只有Entity类中有move函数，而move中调用了getPos()函数，所以如果不用虚函数会优先调用Entity类中的getPos()函数，也会出问题。
	player3->getPos();
	e->getPos();
	e = player3;//将player3的值赋给e，如果没有虚函数，函数将从Entity类中调用getPos()函数，因为e为Entity类，但加入虚函数后，函数的调用会显得更“聪明”，会优先调用Player的getPos()函数。
	e->getPos();
	delete e;
	//delete player3;e和player3指向同一位置，所以只删除一个就可以。
	std::cin.get();
}