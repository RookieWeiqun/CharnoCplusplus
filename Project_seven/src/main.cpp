#include<iostream>
#include<string>
#define Log(x) std::cout << x << std::endl
//void Fun(int size) 
//{
//	int value[size] = { 0 };
//}
//not allowed!! We cant get the value of size in compile progress, but we could have this:
template<typename Type,int N>
class Array
{
private:
	Type m_array[N];
public:

	Array(const Type& x)
	{
		for (int i = 0; i < N; i++)
			m_array[i] = x;	
	}
	int GetSize()const { return m_array[0]; }
};
//��Ϊģ�������ڱ��������ɵģ��ڱ���ʱ�����ɣ�
//class Array
//{
//private:
//	int m_array[5];
//public:G
//	int GetSize()const { return 5; }
//}�Ĵ��룬�ñ�����Ϊ����д���룡Pretty cool!

int main()
{
	int size = 5;
	size = size + 1;
	int test[] = {1};//һ�����˳�ֵ�Ͳ��ܸı��С��ͨ��=���ұ�ȷ��ջ��Ҫ����Ĵ�С��
	int* value = new int[size];//��̬�����ڴ���䣨�ɶѷ��䣩��������˼��һ�ǿ��Բ�ָ������ռ�Ĵ�С������󣬶����ڳ�������ʱ�ɳ���Ա��������ռ���������������ӡ�����̬���䣨��ջ���䣩ָ�����ڱ���׶��ɱ������Ϳ��Է����С�磺int value[5] = { 0 }��
	for (int i = 0; i < size; i++)
	{
		value[i] = i;
		Log(value[i]);
	}
	Array<char, 5> array('a');
	Log(array.GetSize());
}