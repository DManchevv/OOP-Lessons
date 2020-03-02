#include "IntStack.h"
#include <iostream>
IntStack::IntStack() {
	size = 0;
	num = new int[size];
}
IntStack::~IntStack() {
	delete[] num;
}
void IntStack::setNumbers(int* newNum) {
	delete[] num;
	num = new int[size + 1];
	for (size_t i = 0; i < size; i++) {
		num[i] = newNum[i];
	}
}
IntStack::IntStack(const IntStack& CopyFrom) {
	num = nullptr;
	size = CopyFrom.size;
	setNumbers(CopyFrom.num);
}
void IntStack::print()  {
	std::cout << "The current numbers are: " << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}
const int IntStack::getSize() const {
	return size;
}
IntStack& IntStack::operator=(const IntStack& other) {
	if (this != &other) {
		num = nullptr;
		size = other.size;
		setNumbers(other.num);
	}
	return *this;
}
void IntStack::add(int Num) {
	int* tmp = new int[size + 1];
	for (size_t i = 0; i < size; i++) {
		tmp[i] = num[i];
	}
	tmp[size] = Num;
	delete[] num;
	num = tmp;
	size++;
}
void IntStack::pop() {
	int* tmp = new int[size - 1];
	for (size_t i = 0; i < size - 1; i++) {
		tmp[i] = num[i];
	}
	delete[] num;
	num = tmp;
	size--;
}
