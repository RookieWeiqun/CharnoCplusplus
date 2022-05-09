#include<iostream>
#include<string>
class Vector 
{
public:
	int m_x, m_y;
public:
	Vector() :m_x(0), m_y(0) {};
	Vector(int x,int y) :m_x(x), m_y(y) {};
	
	//const Vector& Add(const Vector& vector)//big big trouble here!v1.Add(v2)���ص���v1�����ã��൱��v1=v1+v2��Ȼ��v1��ֵ�ָ���������������Ӧ�÷��ص���һ���µ�Vector����
	//{
	//	m_x += vector.m_x;
	//	m_y += vector.m_y;
	//	return *this;
	//};
	Vector Add(const Vector& vector)const 
	{
		Vector temp(this->m_x + vector.m_x, this->m_y + vector.m_y);
		return temp;
	}
	const Vector& Multiply(const Vector& vector)//big big trouble here!
	{
		m_x *= vector.m_x;
		m_y *= vector.m_y;
		return *this;
	};
	 Vector operator +(const Vector& vector)
	{
		return Add(vector);
	}
	 Vector operator *(const Vector& vector)
	{
		return Multiply(vector);
	}
	
	void VectorPrint(  )const 
	{
		std::cout << this->m_x << "," << this->m_y << std::endl;
	}

};
std::ostream& operator <<(std::ostream& steam, const Vector& x)
{
	steam << x.m_x << "," << x.m_y;
	return steam;
}
int main()
{
	Vector v1(1, 2);
	Vector v2(2, 1);
	Vector v4(1, 2);
    Vector v3;
	v3 = v4*(v1+v2);
	v3.VectorPrint();
	v1.VectorPrint();
	std::cout << v3 << std::endl;//<<���������
	{
	Vector* P_vec = new Vector(1,1); //��new������ڶ��Ϸ�����󣬷��ض����ַ�Լ�����Vector�Ĺ��캯��
	P_vec->VectorPrint();
	v1.VectorPrint();
	delete P_vec;//�����������ʱ��P_vecָ��ᱻ���٣�����ָ����ڴ�ȴ�����ڣ������Ҫ�ֶ�delete�ͷŵ�����ڴ档
	}
	std::cin.get();
}