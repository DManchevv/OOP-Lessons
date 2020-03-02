#include "Product.h"
#include "Store.h"
#include <iostream>
void PrintMenu() {
	std::cout << "Please enter one of the letters displayed below. The current operations are: " << std::endl;
	std::cout << "A:   Add new product." << std::endl;
	std::cout << "X:   Delete product." << std::endl;
	std::cout << "C:   Change product." << std::endl;
	std::cout << "D:   Display product." << std::endl;
	std::cout << "Q:   Quit." << std::endl;
}
int main() {
	std::cout << "Hello and welcome to my online store for T-Shirts. The menu with the operations will be desplayed below. " << std::endl;
	std::cout << "Please, enter only UNIQUE Stock Keeping Unit (SKU), else the program will not work and enter only one word " << std::endl;
	std::cout << "for each SKU, Brand, Model, Colour, Size. Type anything to proceed. " << std::endl;
	char* Start = new char[100];
	std::cin >> Start;
	if (Start != " ") {
		char Menu;
		Store Store;
		while (true) {
			PrintMenu();
			std::cin >> Menu;
			switch (Menu) {
			case 'A':
			{
				Product A;
				std::cout << "Please enter the details of the product you want to add." << std::endl;
				A.Create();
				Store.Add(A);
				break;
			}
			case 'Q':
				return 0;
				break;
			case 'D':
				Store.Display();
				break;
			case 'X':
				Store.Delete();
				break;
			case 'C':
				Store.Change();
				break;
			}
		}
	}
}
