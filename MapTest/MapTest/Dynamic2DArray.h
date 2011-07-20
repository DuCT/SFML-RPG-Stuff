#ifndef DYNAMIC2DARRAY_H
#define DYNAMIC2DARRAY_H

class Dynamic2DArray{
	public:
		Dynamic2DArray(int,int);
		~Dynamic2DArray();
		
		int getAtPoint(int, int);
		void setAtPoint(int, int, int);
	private:
		int** basePtr;
		int height;
		int length;
};

#endif
		