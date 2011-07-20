#include <iostream>
#include <fstream>
#include <sstream>
#include "Dynamic2DArray.h"

Dynamic2DArray::Dynamic2DArray(int a, int b)
{
	height = a;
	length = b;
	basePtr = new int*[height];
	
	for (int row = 0; row < height; row++)
	{
		basePtr[row] = new int [length];
	}
}

Dynamic2DArray::~Dynamic2DArray()
{
	for (int i = 0; i < height; i++)
	{
		delete[] basePtr[i];
		delete[] basePtr;
	}
}

int Dynamic2DArray::getAtPoint(int a, int b)
{
	/*if (a < 1 || a > height || b < 1 || b > height)
	{
		std::cout << "Accessing out-of-bounds of the Array";
		return EXIT_FAILURE;
	}*/
	//else
	//{
		return basePtr[a][b];
	//}
}

void Dynamic2DArray::setAtPoint(int a, int b, int set)
{
	/*if (a < 1 || a > height || b < 1 || b > height)
	{
		std::cout << "Accessing out-of-bounds of the Array";
		return EXIT_FAILURE;
	}*/
	//else
	//{
		basePtr[a][b] = set;
	//}
}
