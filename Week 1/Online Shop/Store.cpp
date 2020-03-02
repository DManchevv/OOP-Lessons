#include "Store.h"
#include <iostream>
#include <cstring>
Store::Store() {
	count = 0;
	TShirts = new Product[count];
}
Store::~Store() {
	delete[] TShirts;
}
Store::Store(const Store& CopyFrom) {
	count = CopyFrom.count;
	for (size_t i = 0; i < count; i++) {
		TShirts[i] = CopyFrom.TShirts[i];
	}
}
Store& Store::operator=(const Store& other) {
	return *this;
}
void Store::Add(Product NewProduct) {
	std::cout << "--------------------------------------------------" << std::endl;
	Product* NewTshirt = new Product[count + 1];
	for (size_t i = 0; i < count; i++) {
		NewTshirt[i] = TShirts[i];
	}
	NewTshirt[count] = NewProduct;
	delete[] TShirts;
	TShirts = NewTshirt;
	count++;
	std::cout << "Product successfully added! " << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}
void Store::Change() {
	std::cout << "--------------------------------------------------" << std::endl;
	Product ChangedProduct;
	char* tmpSKU = new char[100];
	bool IsFound = false;
	std::cout << "Please, enter the SKU of the product you want to change." << std::endl;
	std::cin >> tmpSKU;
	for (size_t i = 0; i < count; i++) {
		if (strcmp(TShirts[i].getSKU(), tmpSKU) == 0) {
			std::cout << "Please, type the information about the new product. " << std::endl;
			ChangedProduct.Create();
			TShirts[i] = ChangedProduct;
			IsFound = true;
		}
	}
	if (!IsFound) std::cout << "The SKU is invalid, please try again!" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}
void Store::Delete() {
	std::cout << "--------------------------------------------------" << std::endl;
	Product* NewList = new Product[count - 1];   // Creating the new list of objects after the deletion
	std::cout << "Please, enter the SKU of the product you want to delete." << std::endl;
	char* tmpSKU = new char[100];
	int delete_index;	// The index of the object that needs to be deleted;
	bool IsFound = false;
	std::cin >> tmpSKU;
	for (size_t i = 0; i < count; i++) {
		if (strcmp(TShirts[i].getSKU(), tmpSKU) == 0) {
			delete_index = i;
			IsFound = true;
			break;
		}
	}
	if (IsFound) {
		int helper = 0;
		for (size_t i = 0; i < count; i++) {
			if (i != delete_index) {
				NewList[helper] = TShirts[i];
				helper++;
			}
		}
		delete[] TShirts;
		TShirts = NewList;
		count--;
		std::cout << "Product successfully deleted!" << std::endl;
	}
	else std::cout << "The SKU is invalid, please try again!" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}
void Store::Display() {
	std::cout << "--------------------------------------------------" << std::endl;
	if (count > 0) {
		std::cout << "The current products in the store are: " << std::endl;
		for (size_t i = 0; i < count; i++) {
			std::cout << "T-Shirt number " << i + 1 << std::endl;
			std::cout << "SKU: " << TShirts[i].getSKU() << std::endl;
			std::cout << "Brand: " << TShirts[i].getBrand() << std::endl;
			std::cout << "Model: " << TShirts[i].getModel() << std::endl;
			std::cout << "Colour: " << TShirts[i].getColour() << std::endl;
			std::cout << "Size: " << TShirts[i].getSize() << std::endl;
			std::cout << "Price: " << TShirts[i].getPrice() << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
		}
	}
	else {
		std::cout << "There are no products in the store at the moment! " << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
}
