#include "IntStack.h"
#include <iostream>

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
IntStack& sortStack(IntStack& obj) {
	for (size_t i = 0; i < obj.getSize() - 1; i++) {
		for (size_t j = 0; j < obj.getSize() - 1; j++) {
			if (obj.num[j] > obj.num[j + 1]) swap(obj.num[j], obj.num[j + 1]);
		}
	}
	std::cout << "Numbers are sorted!" << std::endl;
	return obj;
}

int main() {
	IntStack A;
	A.add(1);
	A.add(2);
	A.add(0);
	A.add(13);
	A.add(5);
	A.print();
	sortStack(A);
	A.pop();
	A.print();
	A.add(7);
	A.add(-3);
	A.print();
	sortStack(A);
	A.print();
	IntStack B;
	B = A;
	B.add(0);
	B.add(23);
	B.add(123);
	sortStack(B);
	B.pop();
	B.print();
}
