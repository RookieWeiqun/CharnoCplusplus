#include<iostream>
#include<string>
#include<array>


int main() 
{ 
	/*fist example; */
	int first[5] = { 1, 2, 3, 4, 5 };//实际上数组就是指针，规定了指针的结束位置（00）
	int* ptr = first;
	*(int*)((char*)first + 4) = 0;//将a数组的第二个数变为零
	std::cout << "first数组的第二个数为" << first[1] << std::endl;
	std::cout << "first数组的大小为：" << sizeof(first) << std::endl;


	/*second example;*/
	int* second = new int[5]{0,1,2,3,4};//与first数组本质相同（同为指针），只不过创建在堆上。
	std::cout << "second数组的第二个数为" << second[1] << std::endl;
	std::cout << "second数组的大小为" << sizeof(second) << std::endl;//此时计算的是int*指针大小
	delete[] second;

	//third example;
	std::array<int, 5> third{0,1,2,3,4};//存贮在栈中，应该多用array，记录数组大小同时还有边界检测
	std::cout << "third数组的第二个数为" << third.at(1) << std::endl;


	/*forth example;*/
	char name1[5] ="abas";// 编译器在栈上创建一个字符串name1，把"abas"从常量区复制到name1，修改name[1]就相当于修改数组元素一样，是可以的。
	const char* name2 = "Duncan";// name2是一个指针，直接指向常量区，修改p[0]就是修改常量区的内容，这是不允许的。
	std::string name3 = "Dog";//+"s";name1和name2是指针，name3是字符串,"Dog"+"s"是两个const指针相加
	name3 += "ss";
	std::cout << "name1字符串为为" << name1 << std::endl;
	std::cout << "name2字符串为为" << name2 << std::endl;
	std::cout << "name3字符串为为" << name3 << std::endl;



	std::cin.get();
}