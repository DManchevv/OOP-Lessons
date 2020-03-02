#pragma once
class IntStack {
	int* num;
	int size;
public:
	void print();
	IntStack();
	~IntStack();
	IntStack& operator=(const IntStack &other);
	IntStack(const IntStack& CopyFrom);
	void setNumbers(int* newNum);
	const int getSize() const;
	void add(int Num);
	void pop();
	friend IntStack& sortStack(IntStack& obj);
};
