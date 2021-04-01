//important note: task 1,2,3 and 5 is in this file
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
private:
	T* array;
	int size;
	int current;
public:
	Stack()
	{
		array = nullptr;
		size = 1;
		current = 0;

	}
	Stack(int siz)
	{
		size = siz;
	}
	Stack(Stack& obj)
	{
		for (int i = 0; i < obj.current; i++)
		{
			array[i] = obj.array[i];

		}
		current = obj.current;
		size = obj.size;
		current = obj.current;

	}
	//task 5
	void AscendingSort()
	{
		T max = array[0];
		for (int i = 0; i < current; i++)
		{
			if (array[i]>max)
			{
				T temp = array[i];
				array[i] = max;
				max = temp;
			}
		 }
	}
	bool isfull()
	{

		if (current == size)
		{

			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (current <= 0)
		{
			return true;
		}
		return false;
	}
	T Top()
	{
		return array[current];
	}
	int Size()
	{
		return size;
	}
	void push(T element)
	{
		if (array == nullptr)
		{
			Stack<T>::array = new T[size];
		}
		if (isfull())
		{
			size++;
			T* newarray = new T[size];
			for (int i = 0; i < current; i++)
			{
				newarray[i] = array[i];

			}
			delete[] array;
			array = newarray;


		}

		array[current++] = element;
	}
	T pop()
	{
		current--;
		return array[current];

	}
	void display()
	{
		for (int i = 0; i < current; i++)
		{
			cout << array[i] << "\n";
		}
		

	}
	~Stack()
	{
		delete[] array;
	}
 friend	void ShowStack(Stack<T> Obj);
};
template<typename H>
void ShowStack(Stack<H> Obj)
{
	for (int i = 0; i < Obj.current; i++)
	{
		cout <<Obj.array[i] << "\n";
	}
}
