#include<iostream>
#include<string>
#include<array>


int main() 
{ 
	/*fist example; */
	int first[5] = { 1, 2, 3, 4, 5 };//ʵ�����������ָ�룬�涨��ָ��Ľ���λ�ã�00��
	int* ptr = first;
	*(int*)((char*)first + 4) = 0;//��a����ĵڶ�������Ϊ��
	std::cout << "first����ĵڶ�����Ϊ" << first[1] << std::endl;
	std::cout << "first����Ĵ�СΪ��" << sizeof(first) << std::endl;


	/*second example;*/
	int* second = new int[5]{0,1,2,3,4};//��first���鱾����ͬ��ͬΪָ�룩��ֻ���������ڶ��ϡ�
	std::cout << "second����ĵڶ�����Ϊ" << second[1] << std::endl;
	std::cout << "second����Ĵ�СΪ" << sizeof(second) << std::endl;//��ʱ�������int*ָ���С
	delete[] second;

	//third example;
	std::array<int, 5> third{0,1,2,3,4};//������ջ�У�Ӧ�ö���array����¼�����Сͬʱ���б߽���
	std::cout << "third����ĵڶ�����Ϊ" << third.at(1) << std::endl;


	/*forth example;*/
	char name1[5] ="abas";// ��������ջ�ϴ���һ���ַ���name1����"abas"�ӳ��������Ƶ�name1���޸�name[1]���൱���޸�����Ԫ��һ�����ǿ��Եġ�
	const char* name2 = "Duncan";// name2��һ��ָ�룬ֱ��ָ���������޸�p[0]�����޸ĳ����������ݣ����ǲ�����ġ�
	std::string name3 = "Dog";//+"s";name1��name2��ָ�룬name3���ַ���,"Dog"+"s"������constָ�����
	name3 += "ss";
	std::cout << "name1�ַ���ΪΪ" << name1 << std::endl;
	std::cout << "name2�ַ���ΪΪ" << name2 << std::endl;
	std::cout << "name3�ַ���ΪΪ" << name3 << std::endl;



	std::cin.get();
}