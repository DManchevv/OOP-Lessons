#pragma once
#include "Product.h"
class Store {
	Product* TShirts;
	int count;
public:
	Store();
	~Store();
	Store(const Store& CopyFrom);
	Store& operator=(const Store& other);
	void Add(Product NewProduct);
	void Delete();
	void Change();
	void Display();
};
