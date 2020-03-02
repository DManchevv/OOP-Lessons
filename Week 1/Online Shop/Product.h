#pragma once
class Product { // The chosen product is T-Shirt
	char* SKU;
	char* Brand;
	char* Model;
	char* Colour; // Colour of the Tshirt
	char* Size; // The size of the TShirt
	double Price;
	int Count;
public:
	Product();
	~Product();
	Product(const Product& CopyFrom);
	Product& operator=(const Product& other);
	void setSKU(const char* newSKU);
	void setBrand(const char* newBrand);
	void setModel(const char* newModel);
	void setColour(const char* newColour);
	void setSize(const char* newSize);
	void setPrice(const double newPrice);
	const char* getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const char* getColour() const;
	const char* getSize() const;
	const double  getPrice() const;
	void Create();
};
