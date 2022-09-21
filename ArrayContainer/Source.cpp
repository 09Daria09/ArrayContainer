#include<iostream>
using namespace std;
template<class T = int>
class MyArray
{
	T* arr;
	int size;
	int capacity;
public:
	MyArray();
	MyArray(int s);// size=s; capacity=size;
	MyArray(const MyArray& obj);
	MyArray& operator=(const MyArray& obj);
	void Print();
	void Random();
	int GetSize()const;
	MyArray<T>& SetSize(int s,int grow);
	int GetUpperBound()const;
	bool IsEmpty()const;
	MyArray<T>& FreeExtra();
	MyArray<T>& RemoveAll();
	T operator[](int index);
	T GetAt(int index);
	T SetAt(int index, T value);
	MyArray<T>& Add(T value);
	MyArray<T>& Append(const MyArray& obj);
	T GetData(int index);
	MyArray<T>& InsertAt(int index,int value);
	MyArray<T>& RemoverAt(int index);
	~MyArray(); 
	 
};
template<class T>
MyArray<T>::MyArray()
{
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<class T>
MyArray<T>::MyArray(int s)
{
	size = s;
	capacity = s;
	arr = new T[capacity];
}

template<class T>
MyArray<T>::MyArray(const MyArray& obj)
{
	size=obj.size;
	capacity=obj.capacity;
	arr = new T[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		if (i > size - 1)
		{
			arr[i] = 0;
		}
		arr[i] = obj.arr[i];
	}	
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	/*if (arr != nullptr)
	{
		~MyArray();
	}*/
	arr = new T[capacity];
	size = obj.size;
	for(int i = 0; i < size; ++i)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

template<class T>
void MyArray<T>::Print()
{
	for (int i = 0; i < size; ++i)
	{
		cout<<"|"<<arr[i]<<"|"<<" ";
	}
	cout << endl<<"**********************************************************" << endl;
}

template<class T>
bool MyArray<T>::IsEmpty() const
{
	if (arr[0]==true)
	{
		cout << "Array is full"<<endl;
		return false;
	}
	cout << "Array is empty"<<endl;
	return true;
}

template<class T>
MyArray<T>& MyArray<T>::FreeExtra()
{
	if (capacity > size)
	{
		MyArray<T>obj(capacity);
		obj.arr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (i > size - 1)
			{
				obj.arr[i] = 0;
			}
			obj.arr[i] = arr[i];
		}
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::RemoveAll()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = 0;
	}
	return *this;
}

template<class T>
T MyArray<T>::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		return arr[index];
	}
	return 0;
}

template<class T>
T MyArray<T>::GetAt(int index)
{
	if (index<0 || index>size - 1)
	{
		cout << "Wrong index" << endl;
		return 0;
	}
	cout << "Your value by index \"" << index << "\": " << arr[index] << endl;;
	return arr[index];
}

template<class T>
T MyArray<T>::SetAt(int index, T value)
{
	if (index<0 || index>size - 1)
	{
		cout << "Wrong index" << endl;
		return 0;
	}
	arr[index] = value;
	return arr[index];
}

template<class T>
MyArray<T>& MyArray<T>::Add(T value)
{
	if (capacity < size)
	{
		MyArray<T>obj(capacity);
		obj.arr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (i > size - 1)
			{
				obj.arr[i] = 0;
			}
			obj.arr[i] = arr[i];
		}
		capacity += 1;
		arr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (i > size)
			{
				arr[i] = 0;
			}
			arr[i] = obj.arr[i];

		}

	}

	arr[size] = value;
	size += 1;
	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::Append(const MyArray& obj)
{
	if (size < obj.size)
	{
		MyArray<T>a;
		a.arr = new T[obj.size];
		for (int i = 0; i < size; i++)
		{
			a.arr[i] = arr[i];
		}
		for (int i = size; i < obj.size; i++)
		{
			a.arr[i] = 0;
		}
		arr = new T[obj.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = a.arr[i];
		}
		for (int i = size; i < obj.size; i++)
		{
			arr[i] = 0;
		}
	for (int i = 0; i < obj.size; i++)
	{
		arr[i] = arr[i] + obj.arr[i];
	}
	size = obj.size;
	capacity = obj.capacity;
	return *this;
	}
	MyArray<T>a;
	a.arr = new T[size];
	for (int i = 0; i < obj.size; i++)
	{
		a.arr[i] = obj.arr[i];
	}
	for (int i = obj.size; i <size; i++)
	{
		a.arr[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr[i] + a.arr[i];
	}
	return *this;
}

template<class T>
T MyArray<T>::GetData(int index)
{
	cout << "Array address: " << arr + index <<" Array value: " << *(arr + index) << endl;
	return *(arr + index);
}

template<class T>
MyArray<T>& MyArray<T>::InsertAt(int index,int value)
{
	arr[index] = value;
	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::RemoverAt(int index)
{
	MyArray<T>obj;
	obj.arr = new T[size-1];
	for (int i = 0; i < index; i++)
	{
		obj.arr[i] = arr[i];
	}
	int j = index;
	for (int i = index+1; i < size; i++,j++)
	{
		obj.arr[j] = arr[i];
	}
	arr = new T[size - 1];
	size =size- 1;
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

template<class T>
MyArray<T>::~MyArray()
{
	delete[]arr;
}

template<class T>
void MyArray<T>::Random()
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 * 1.6;
	}
}

template<class T>
int MyArray<T>::GetSize()const
{
	return size;
}

template<class T>
MyArray<T>& MyArray<T>::SetSize(int s, int grow)
{
	if (capacity < size)
	{
		MyArray<T>obj(s);
		obj.arr = new T[s];
		for (int i = 0; i < s; i++)
		{
			if (i > size - 1)
			{
				obj.arr[i] = 0;
			}
			obj.arr[i] = arr[i];
		}
		capacity += grow;
		arr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (i > size - 1)
			{
				arr[i] = 0;
			}
			arr[i] = obj.arr[i];
		}

	}
	if (size > s)
	{ 
		size = s;
		return*this;
	}
	if (size < s)
	{
		for (int i = 0; i < s; i++)
		{
			if (i > size - 1)
			{
				arr[i] = 0;
			}
		}
		size = s;
		return*this;
	}
	if (size == s)
	{
		return *this;
	}
}

template<class T>
int MyArray<T>::GetUpperBound()const
{
	cout << "Last index in array: ";
	cout << "[" << size - 1 << "]" << endl;
	return size-1;
}

int main()
{
	MyArray<>obj1(10);
	obj1.Random();
	obj1.Print();
	obj1.SetSize(4,1);
	obj1.Print();
	obj1.GetUpperBound();
	obj1.IsEmpty();
	obj1.GetAt(0);
	obj1.SetAt(2, 144);
	obj1.Print();
	obj1.Add(345);
	obj1.Print();
	MyArray<>obj2(13);
	obj2.Random();
	obj2.Print();
	obj2.Append(obj1);
	obj2.Print();
	MyArray<>obj22(obj2);
	obj22.Print();
	cout<<obj1.GetData(2);
	obj1.RemoverAt(4);
	obj1.Print();

}
