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

	/*---Mutators---*/
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

	//Gets an element from a list. Used by [] operator and .at(index)
	const T& getElement(unsigned int index) const;
	T& getElement(unsigned int index);
};

/*====================METHOD=IMPLEMENTATIONS==========================*/

template<typename T>
DynamicArray<T>::DynamicArray(unsigned int capacity) {
	this->size = 0;
	this->capacity = capacity;
	data = new T[capacity];
}

template<typename T>
void DynamicArray<T>::Remove(unsigned int index) {
	if (index >= size) {
		throw "Error! Invalid index";
	}

	for (unsigned int i = index; i < size; i++) {
		data[i] = data[i + 1];
	}

	size--;
}

template<typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 0;

	data = nullptr;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	if (data != nullptr) {
		delete[] data;
	}
	data = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &d) {
	set(d);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &d) {
	set(d);
	return *this;
}

template<typename T>
void DynamicArray<T>::set(const DynamicArray<T> &d) {
	this->capacity = d.capacity;
	this->size = d.size;

	data = new T[capacity];

	for (unsigned int i = 0; i < d.size; i++) {
		data[i] = d[i];
	}
}

template<typename T>
const T& DynamicArray<T>::getElement(unsigned int index) const {
	if (index >= size) {
		throw "Error: Invalid index";
	}
	else {
		return data[index];
	}
}

template<typename T>
T& DynamicArray<T>::getElement(unsigned int index) {
	if (index >= size) {
		throw "Error: Invalid index";
	}
	else {
		return data[index];
	}
}

template<typename T>
void DynamicArray<T>::Add(const T& element) {
	//If the array is full, add an empty slot
	if (size >= capacity) {
		Resize(capacity + 1);
	}

	//Add the element to the end of the array
	data[size] = element;
	size++;
}

template<typename T>
void DynamicArray<T>::Resize(unsigned int newSize) {
	
	cout << "Resizing... old capacity: " << capacity << " New capacity: " << newSize << endl;

	T* newArr = new T[newSize];

	//Tracks the number of elements to copy into newArr.
	unsigned int j;

	if (newSize < size) { //if array is shrinking
		j = newSize;
	}
	else {
		//It's growing, loop all the way to the old size
		j = size;
	}

	for (unsigned int i = 0; i < j; i++) {
		newArr[i] = data[i];
	}

	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}

	capacity = newSize;
	size = j;
	data = newArr;
}

template<typename T>
unsigned int DynamicArray<T>::GetCapacity() const {return capacity;}

template<typename T>
unsigned int DynamicArray<T>::GetSize() const {return size;}

template<typename T>
const T* DynamicArray<T>::GetData() const {return data;}

template<typename T>
const T& DynamicArray<T>::At(unsigned int index) const {
	return getElement(index);
}

template<typename T>
T& DynamicArray<T>::At(unsigned int index) {
	return getElement(index);
}

template<typename T>
const T& DynamicArray<T>::operator[](unsigned int index) const {
	return getElement(index);
}

template<typename T>
T& DynamicArray<T>::operator[](unsigned int index) {
	return getElement(index);
}