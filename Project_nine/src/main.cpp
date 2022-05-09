#include<iostream>
#include<thread>
#include<chrono>
struct memery_record //存储有关内存占用的数据
{
	size_t m_ConstructMemory,m_DistroyMemory, m_OccupiedMemory;
	size_t& memory_occupied()
	{
		m_OccupiedMemory = m_ConstructMemory - m_DistroyMemory;
		return m_OccupiedMemory;
	}
};
memery_record MemeryRecord;
void* operator new(size_t size)//重载new运算符用来监视内存
{
	MemeryRecord.m_ConstructMemory += size;
	std::cout << "Construct" << size << "bytes!" << std::endl;
	return malloc(size);
}
void operator delete(void* ptr, size_t size)//重载delete运算符用来监视内存
{
	MemeryRecord.m_DistroyMemory += size;
	std::cout << "Distroy" << size << "bytes!" << std::endl;
	free(ptr);
}
static void PrintMemory()//实时打印内存占用情况
{
	std::cout<<"Occupied memory is:"<<MemeryRecord.memory_occupied()<<"bytes!"<<std::endl;
}

class Entity
{
public:
	int m_x, m_y,m_z;
	Entity(int x, int y,int z) :m_x(x), m_y(y) ,m_z(z){};
	void PrintFuc() { std::cout << "x:"<< m_x <<"y:"<< m_y << std::endl; }
	~Entity() {};
};
int main()
{
	{
		PrintMemory();
		std::shared_ptr<Entity> Sptr1 = std::make_shared<Entity>(5, 0, 0);//首先Sptr1是个对象，里面存储的是两个地址，一个是创建的Entity实例的地址，一个是控制块的地址，一次性为他们分配内存。Sptr1->PrintFuc()是将->进行运算符重载，使的Sptr看起来像指针，->运算符返回Sptr存储是创建的Entity实例的地址。
		PrintMemory();
		Entity* ptr = new Entity(5, 2, 1);
		std::shared_ptr<Entity> Sptr2(ptr);
		PrintMemory();
		std::shared_ptr<Entity> Sptr3(new Entity(5, 2, 1)); //首先Sptr3是个对象，里面存储的是两个地址，一个是创建的Entity实例的地址，一个是控制块的地址(包括计数、weak值等)，分两次为他们分配内存。相比于make_share来说，他需要的内存大，效率也慢。
	}
	PrintMemory();
	/*std::chrono::time_point<std::chrono::steady_clock> start1 std::chrono::high_resolution_clock::now();	*/
	//auto start = std::chrono::high_resolution_clock::now();
	std::cin.get();
}