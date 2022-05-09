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
//因为模板类是在编译是生成的，在编译时会生成：
//class Array
//{
//private:
//	int m_array[5];
//public:G
//	int GetSize()const { return 5; }
//}的代码，让编译器为我们写代码！Pretty cool!

int main()
{
	int size = 5;
	size = size + 1;
	int test[] = {1};//一旦赋了初值就不能改变大小，通过=号右边确定栈上要分配的大小；
	int* value = new int[size];//动态分配内存分配（由堆分配）有两层意思，一是可以不指定分配空间的大小例如对象，二是在程序运行时由程序员自主分配空间例如现在这个例子。而静态分配（由栈分配）指的是在编译阶段由编译器就可以分配大小如：int value[5] = { 0 }。
	for (int i = 0; i < size; i++)
	{
		value[i] = i;
		Log(value[i]);
	}
	Array<char, 5> array('a');
	Log(array.GetSize());
}