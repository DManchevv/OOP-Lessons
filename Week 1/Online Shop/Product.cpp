#include "Product.h"
#include <cstring>
#include <iostream>
Product::Product() {
	SKU = nullptr;
	Brand = nullptr;
	Model = nullptr;
	Colour = nullptr;
	Size = nullptr;
	Price = Count = 0;
}
Product::~Product() {
	delete[] SKU;
	delete[] Brand;
	delete[] Model;
	delete[] Colour;
	delete[] Size;
}
Product::Product(const Product& CopyFrom) {
	SKU = nullptr;
	Brand = nullptr;
	Model = nullptr;
	Colour = nullptr;
	Size = nullptr;
	setSKU(CopyFrom.SKU);
	setBrand(CopyFrom.Brand);
	setModel(CopyFrom.Model);
	setColour(CopyFrom.Colour);
	setSize(CopyFrom.Size);
	Price = CopyFrom.Price;
}
Product& Product::operator=(const Product& other) {
	if (this != &other) {
		setSKU(other.SKU);
		setBrand(other.Brand);
		setModel(other.Model);
		setColour(other.Colour);
		setSize(other.Size);
		Price = other.Price;
	}
	return *this;
}
void Product::setSKU(const char* newSKU) {
	delete[] SKU;
	SKU = new char[strlen(newSKU) + 1];
	strcpy(SKU, newSKU);
}
void Product::setBrand(const char* newBrand) {
	delete[] Brand;
	Brand = new char[strlen(newBrand) + 1];
	strcpy(Brand, newBrand);
}
void Product::setModel(const char* newModel) {
	delete[] Model;
	Model = new char[strlen(newModel) + 1];
	strcpy(Model, newModel);
}
void Product::setColour(const char* newColour) {
	delete[] Colour;
	Colour = new char[strlen(newColour) + 1];
	strcpy(Colour, newColour);
}
void Product::setSize(const char* newSize) {
	delete[] Size;
	Size = new char[strlen(newSize) + 1];
	strcpy(Size, newSize);
}
void Product::setPrice(const double newPrice) {
	Price = newPrice;
}
const char* Product::getSKU() const {
	return SKU;
}
const char* Product::getBrand() const {
	return Brand;
}
const char* Product::getModel() const {
	return Model;
}
const char* Product::getColour() const {
	return Colour;
}
const char* Product::getSize() const {
	return Size;
}
const double Product::getPrice() const {
	return Price;
}
void Product::Create() {
	SKU = new char[100];
	Brand = new char[100];
	Model = new char[100];
	Colour = new char[20];
	Size = new char[20];
	std::cout << "Type the SKU (Stock Keeping Unit) of the product: " << std::endl;
	std::cin >> SKU;
	std::cout << "Type the Brand of the product: " << std::endl;
	std::cin >> Brand;
	std::cout << "Type the Model of the product: " << std::endl;
	std::cin >> Model;
	std::cout << "Type the Colour of the product: " << std::endl;
	std::cin >> Colour;
	std::cout << "Set the Size of the product: " << std::endl;
	std::cin >> Size;
	std::cout << "Set the Price of the product: " << std::endl;
	std::cin >> Price;
}
