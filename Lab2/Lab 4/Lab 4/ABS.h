#pragma once
#include <iostream>
template<typename T>
class ABS {
	float scaleFactor = 2.0f;
	/*top acts as the size of the stack, 
	and the index of the next empty space to push to.*/
	unsigned int top, capacity;
	T* data;
	unsigned int numResizes = 0;

	void growArr();
	void shrinkArr();
	
	//Use: copy constructor and = operator
	void set(const ABS& d);
public:
	ABS();
	ABS(unsigned int capacity);
	ABS(const ABS& d);
	ABS<T>& operator=(const ABS& d);
	~ABS();
	
	void setSF(float scale);

	//Add to the stack.
	void push(T data);
	//Return top and remove it.
	T pop();
	//Return top without removing.
	T peek();

	//Accessors
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	unsigned int getNumResizes();
	float getsf();
};

template<typename T>
void ABS<T>::growArr() {
	std::cout << "growing..." << std::endl;
	//Make the new array
	capacity = (int)(capacity * scaleFactor);
	T* newArr = new T[capacity];

	//Fill it in
	for (unsigned int i = 0; i < top; i++) {
		newArr[i] = data[i];
	}

	if (data != nullptr) {
		delete[] data;
	}

	data = newArr;
	numResizes++;
}

template<typename T>
void ABS<T>::shrinkArr() {
	//Make the new array
	capacity = (int)(capacity / scaleFactor);
	T* newArr = new T[capacity];

	//Fill it in
	for (unsigned int i = 0; i < top; i++) {
		newArr[i] = data[i];
	}

	if (data != nullptr) {
		delete[] data;
	}

	data = newArr;
	numResizes++;
}

template<typename T>
void ABS<T>::set(const ABS& d) {
	capacity = d.capacity;
	top = d.top;
	data = new T[capacity];

	for (unsigned int i = 0; i < d.getSize; i++) {
		data[i] = d[i];
	}
}

template<typename T>
ABS<T>::ABS() {
	top = 0;
	capacity = 1;
	data = new T[capacity];
}

template<typename T>
ABS<T>::ABS(unsigned int capacity) {
	top = 0;
	this->capacity = capacity;
	data = new T[capacity];
}

template<typename T>
ABS<T>::ABS(const ABS& d) {
	set(d);
}

template<typename T>
ABS<T>& ABS<T>::operator=(const ABS& d) {
	set(d);
	return *this;
}

template<typename T>
ABS<T>::~ABS() {
	delete[] data;
}

template<typename T>
void ABS<T>::setSF(float scale) {
	scaleFactor = scale;
}

template<typename T>
void ABS<T>::push(T data) {
	if (top >= capacity) {
		growArr();
	}

	this->data[top++] = data;
}

template<typename T>
T ABS<T>::pop() {
	if (top == 0) {
		throw -1;
	}
	else {
		T e = data[--top];

		if (top < (float)capacity / 2) {
			shrinkArr();
		}

		return e;
	}
}

template<typename T>
T ABS<T>::peek() {
	if (top == 0) {
		throw -1;
	}
	else {
		return data[top - 1];
	}
}

template<typename T>
unsigned int ABS<T>::getSize() {
	return top;
}

template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
	return capacity;
}

template<typename T>
T* ABS<T>::getData() {
	return data;
}

template<typename T>
unsigned int ABS<T>::getNumResizes() {
	return numResizes;
}

template<typename T>
inline float ABS<T>::getsf() {
	return scaleFactor;
}
