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
	static int number;//������Ա��������static������������ֻ��������static����extern���ƣ������ڱ����ʱ����о�̬�������ڴ���䣬����Ҫ�ں�������о�̬�����Ķ��塣
	virtual void getPos()
	{
		std::cout << "Entity���ڵ�λ��Ϊx=" << m_x << " y=" << m_y << std::endl;
	};
	void getNmuber()
	{
		std::cout << "������"<<number<<"����Ա"  << std::endl;
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
	Player(int x, int y, std::string* name):Entity()//û�У�ʱĬ�ϵ����޲�Entity���캯���������Entity��û�������޲εĹ��캯��������Ҫ�ֶ��̳��в�Entity��Ҫ��Ȼ����
	{
		m_x = x;
		m_y = y;
		Playername = name;
		number++;
		getNmuber();
	};
	void getPos() override
	{
		std::cout <<"��Ա"<< *Playername << "���ڵ�λ��Ϊx=" << m_x << " y=" << m_y <<std::endl;
	}
	void getPlayname()
	{
		std::cout << "����Ա������Ϊ��" << *Playername << std::endl;
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
	player3->move(3,1);//��Ϊֻ��Entity������move��������move�е�����getPos()������������������麯�������ȵ���Entity���е�getPos()������Ҳ������⡣
	player3->getPos();
	e->getPos();
	e = player3;//��player3��ֵ����e�����û���麯������������Entity���е���getPos()��������ΪeΪEntity�࣬�������麯���󣬺����ĵ��û��Եø����������������ȵ���Player��getPos()������
	e->getPos();
	delete e;
	//delete player3;e��player3ָ��ͬһλ�ã�����ֻɾ��һ���Ϳ��ԡ�
	std::cin.get();
}