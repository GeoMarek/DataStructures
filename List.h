#pragma once
#include <cstdint>

template<typename T> class List {
private:
	uint32_t count;
	T* items;
public:
	List();
	~List();
	T Get(uint32_t index);
	void Insert(uint32_t index, T value);
	uint32_t Search(T value);
	void Remove(uint32_t index);
	uint32_t Count();
};

template<typename T>
inline List<T>::List() : count(0), items(nullptr)
{
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline T List<T>::Get(uint32_t index)
{ 
	if (index < 0 or index > count) return T();
	return items[index];
}

template<typename T>
inline void List<T>::Insert(uint32_t index, T value)
{
	// bad index
	if (index<0 or index > count) return;

	// init new array
	T* old_items = items;
	++count;
	items = new T[count];

	// insert data in new array
	for (uint32_t i = 0, j = 0; i < count; ++i) 
	{
		if (index == i) 
		{
			items[i] = value;
		}
		else
		{
			items[i] = old_items[j];
			++j;
		}
	}
	// dealloc
	delete[] old_items;
}

template<typename T>
inline uint32_t List<T>::Search(T value)
{
	for (uint32_t i = 0; i < count; ++i) 
	{
		if (items[i] == value) return i;
	}

	return uint32_t();
}

template<typename T>
inline void List<T>::Remove(uint32_t index)
{
	// bad index
	if (index <0 or index > count) return;
	
	// init new array
	T* old_items = items;
	--count;
	items = new T[count];

	// insert data in new array
	for (uint32_t i = 0, j=0; i < count; ++i,++j) 
	{
		if (index == j) ++j;
		items[i] = old_items[j];
	}


	//dealloc
	delete[] old_items;
}

template<typename T>
inline uint32_t List<T>::Count()
{
	return count;
}