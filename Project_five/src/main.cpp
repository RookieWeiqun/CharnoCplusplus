#include<iostream>
#include<string>
class Vector 
{
public:
	int m_x, m_y;
public:
	Vector() :m_x(0), m_y(0) {};
	Vector(int x,int y) :m_x(x), m_y(y) {};
	
	//const Vector& Add(const Vector& vector)//big big trouble here!v1.Add(v2)返回的是v1的引用，相当于v1=v1+v2，然后将v1的值又给了其他对象。正常应该返回的是一个新的Vector对象。
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
	std::cout << v3 << std::endl;//<<运算符重载
	{
	Vector* P_vec = new Vector(1,1); //用new运算符在堆上分配对象，返回对象地址以及调用Vector的构造函数
	P_vec->VectorPrint();
	v1.VectorPrint();
	delete P_vec;//当作用域结束时，P_vec指针会被销毁，但其指向的内存却还存在，因此需要手动delete释放掉这块内存。
	}
	std::cin.get();
}