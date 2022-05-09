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
		std::cout << "�˶�Ա�ĳɼ�Ϊ��" << std::endl;
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
	e->m_x;//������ָ�븳ֵ������ָ��ʱ,���ó�Ա�����ǵ��ø���(e��Entity����)�����������ݳ�Աʱ��Ϊָ��ʱEntity���ͣ����Թ涨�����ܷ��ʵĿռ��СҲΪEntity���С(sizeof(Entity)=12)�����ܷ��ʵ����ݳ�ԱΪm_x��m_y������ֵ�Ĵ�Сȷʵ�����еģ���Ϊe���������ĵ�ַ;
	Player* p = (Player*)P_entity;
	p->m_name;//������ָ�븳ֵ������ָ��ʱ,���ó�Ա�����ǵ�������(e��Entity����)�����������ݳ�Աʱ��Ϊָ��ʱPlayer���ͣ����Թ涨�����ܷ��ʵĿռ��СҲΪPlayer���С(sizeof(Entity)=20)�����ܷ��ʵ����ݳ�Աm_name����ʵ����ȴ���ܵõ�m_name��ֵ����Ϊp�Ǹ������ĵ�ַ;
	int x = *((int*)e+3);//���ַ��ʷ�ʽ��̫ţ���ˣ�ָ���������
	delete e;//������ָ�븳ֵ������ָ��ʱ����������������ͨ�麯��������������������͸���������������ã�һ�㸸������������Ӧ�ü���virtual�ؼ��֡�
	delete P_entity;
	std::cin.get();
}