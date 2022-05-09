#include<iostream>
int main()
{
	int* arr1d = new int[50];
	int** arr2d = new int* [50];
	int*** arr3d = new int** [50];
	for (int i = 0; i < 50; i++) 
		*(arr2d+i)  = new int[50];
	for (int i = 0; i < 50; i++)
	{
		*(arr3d + i) = new int* [50];
		for (int j = 0; j < 50; j++)
			*(*(arr3d + i)+j) = new int[50];
	}
	delete[] arr1d;
	for (int i = 0; i < 50; i++)
		delete[] *(arr2d + i);
	delete[] arr2d;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			delete[] *(*(arr3d + i) + j) ;
		delete *(arr3d + i);
	}
	delete[] arr3d;
	std::cin.get();
}