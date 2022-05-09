#include<iostream>
#include<thread>
#include<chrono>
struct memery_record //�洢�й��ڴ�ռ�õ�����
{
	size_t m_ConstructMemory,m_DistroyMemory, m_OccupiedMemory;
	size_t& memory_occupied()
	{
		m_OccupiedMemory = m_ConstructMemory - m_DistroyMemory;
		return m_OccupiedMemory;
	}
};
memery_record MemeryRecord;
void* operator new(size_t size)//����new��������������ڴ�
{
	MemeryRecord.m_ConstructMemory += size;
	std::cout << "Construct" << size << "bytes!" << std::endl;
	return malloc(size);
}
void operator delete(void* ptr, size_t size)//����delete��������������ڴ�
{
	MemeryRecord.m_DistroyMemory += size;
	std::cout << "Distroy" << size << "bytes!" << std::endl;
	free(ptr);
}
static void PrintMemory()//ʵʱ��ӡ�ڴ�ռ�����
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
		std::shared_ptr<Entity> Sptr1 = std::make_shared<Entity>(5, 0, 0);//����Sptr1�Ǹ���������洢����������ַ��һ���Ǵ�����Entityʵ���ĵ�ַ��һ���ǿ��ƿ�ĵ�ַ��һ����Ϊ���Ƿ����ڴ档Sptr1->PrintFuc()�ǽ�->������������أ�ʹ��Sptr��������ָ�룬->���������Sptr�洢�Ǵ�����Entityʵ���ĵ�ַ��
		PrintMemory();
		Entity* ptr = new Entity(5, 2, 1);
		std::shared_ptr<Entity> Sptr2(ptr);
		PrintMemory();
		std::shared_ptr<Entity> Sptr3(new Entity(5, 2, 1)); //����Sptr3�Ǹ���������洢����������ַ��һ���Ǵ�����Entityʵ���ĵ�ַ��һ���ǿ��ƿ�ĵ�ַ(����������weakֵ��)��������Ϊ���Ƿ����ڴ档�����make_share��˵������Ҫ���ڴ��Ч��Ҳ����
	}
	PrintMemory();
	/*std::chrono::time_point<std::chrono::steady_clock> start1 std::chrono::high_resolution_clock::now();	*/
	//auto start = std::chrono::high_resolution_clock::now();
	std::cin.get();
}