#pragma once
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
public:
	//Accessors
	unsigned int GetCapacity() const;
	unsigned int GetSize() const;
	const T* GetData() const;

	//Return a specific element from the internal array
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	
	//Just like the brakcets operator, but with a function
	const T& At(unsigned int index) const;
	T &At(unsigned int index);

	//Mutators
	//Add an item onto the end of the array, if there is room.
	//If not, resize it to accomodate space
	void Add(const T& element);

	//This is the beefcake of a function that does the resizing.
	void Resize(unsigned int newSize);

	//Removes an element from an array, 
	//and then shrinks the array to fill the gap.
	void Remove(unsigned int index);

	//Constructors
	DynamicArray();
	DynamicArray(unsigned int);

	//Trilogy of Evil
	DynamicArray(const DynamicArray& d);
	DynamicArray& operator=(const DynamicArray& d);
	~DynamicArray();

private:
	//Pointer to the array which holds the data
	T* data;
	//Number of elements in data
	unsigned int size;
	//Maximum size of the current array
	unsigned int capacity;

	void set(const DynamicArray& d);
};

/*====================METHOD=IMPLEMENTATIONS==========================*/

template<typename T>
DynamicArray<T>::DynamicArray(unsigned int capacity) {
	this->size = 0;
	this->capacity = capacity; //this-> ?
	data = new T[capacity];
}

template<typename T>
void DynamicArray<T>::Remove(unsigned int index) {
	for (unsigned int i = index; i < size; i++) {
		data[i] = data[i + 1]; //exception, the size is 0
	}

	Resize(capacity - 1);
	size--;
}

//Initializes an empty array with 10 capacity.
template<typename T>
DynamicArray<T>::DynamicArray() {
	this->size = 0;
	capacity = 10;

	data = new T[capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] data;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& d) {set(d);}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& d) {
	set(d);
	return *this;
}

template<typename T>
void DynamicArray<T>::set(const DynamicArray& d) {
	capacity = d.capacity;
	this->size = 0;
	if(data != nullptr)
		delete[] data;

	data = new T[capacity];

	for (unsigned int i = 0; i < d.size; i++) {
		data[i] = d[i];
		size++;
	}
}


template<typename T>
void DynamicArray<T>::Add(const T& element) {
	//While the array is full, add slots
	if (size >= capacity) {
		Resize(capacity + 1);
	}

	//Add the element to the end of the array
	data[capacity - 1] = element;
	size++;
}

//double and half this array!
template<typename T>
void DynamicArray<T>::Resize(unsigned int newSize) {
	T* newArr = new T[newSize];
	size = 0;
	capacity = newSize;

	for (unsigned int i = 0; i < newSize; i++) {
		newArr[i] = data[i]; //shallow copy?
		size++;
	}
	
	if (data != nullptr)
		delete[] data;
	
	data = newArr;
}

template<typename T>
unsigned int DynamicArray<T>::GetCapacity() const {return capacity;}

template<typename T>
unsigned int DynamicArray<T>::GetSize() const {return size;}

template<typename T>
const T* DynamicArray<T>::GetData() const {return data;}

template<typename T>
const T& DynamicArray<T>::At(unsigned int index) const {return data[index];}

template<typename T>
T& DynamicArray<T>::At(unsigned int index) {return data[index];}

template<typename T>
const T& DynamicArray<T>::operator[](unsigned int index) const {return data[index];}

template<typename T>
T& DynamicArray<T>::operator[](unsigned int index) {return data[index];}