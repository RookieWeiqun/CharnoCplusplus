#include<iostream>
class Entity
{s
public:
	int m_x, m_y;
public:
	Entity(int x, int y) : m_x(x), m_y(y)
	{std::cout << "Entity Construct!" << std::endl; }
	Entity() {};
	 virtual ~Entity()
	{ std::cout << "Entity Disstruct!" << std::endl;}
};
class Player:public Entity
{
public:
	enum state
	{
		win = 2, fall = 0, tie = 1
	};
public:
	const char* m_name;
	int*p_history=new int[5];
	static int count;
public:
	Player(int x ,int y,const char*name):Entity::Entity(x, y)
	{
		m_name = name;
		std::cout << "Player "<<name<<"Construct!" << std::endl;
	}
	~Player() 
	{ 
		delete p_history; 
		std::cout << "Player" << m_name << "Disstruct!" << std::endl;
	}
	void record(state sta) 
	{
		p_history[count] = sta;
		count++;
	}
	void PrintRecord()
	{
		std::cout << "运动员的成绩为：" << std::endl;
		for(int i=0;i<count;i++)
		std::cout << p_history[i] << std::endl;
	}
};
int Player::count = 0;
int main()
{
	Entity *P_entity=new Entity(2, 5);
	std::cout << "--------------------" << std::endl;
	Player* P_player1 = new Player(3, 5, "dog");
	P_player1->record(Player::fall);
	P_player1->record(Player::fall);
	P_player1->record(Player::fall);
	P_player1->record(Player::win);
	P_player1->record(Player::tie);
	P_player1->PrintRecord();
	std::cout << "--------------------" << std::endl;
	Entity* e = P_player1;
	e->m_x;//当子类指针赋值给父类指针时,调用成员函数是调用父类(e是Entity类型)，但调用数据成员时因为指针时Entity类型，所以规定了其能访问的空间大小也为Entity类大小(sizeof(Entity)=12)，故能访问的数据成员为m_x和m_y，但其值的大小确实子类中的，因为e是子类对象的地址;
	Player* p = (Player*)P_entity;
	p->m_name;//当父类指针赋值给子类指针时,调用成员函数是调用子类(e是Entity类型)，但调用数据成员时因为指针时Player类型，所以规定了其能访问的空间大小也为Player类大小(sizeof(Entity)=20)，故能访问的数据成员m_name，但实际上却不能得到m_name的值，因为p是父类对象的地址;
	int x = *((int*)e+3);//这种访问方式可太牛逼了！指针的魅力。
	delete e;//当子类指针赋值给父类指针时，虚析构函数与普通虚函数相比是子类析构函数和父类机构函数都调用，一般父类析构函数都应该加上virtual关键字。
	delete P_entity;
	std::cin.get();
}