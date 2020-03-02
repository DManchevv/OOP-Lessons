#include <iostream>
#include <cstring>
#include "DNSRecord.h"
#include "DNSCache.h"
int main() {
	DNSRecord FirstRecord;
	DNSCache Cache;
	FirstRecord.setName("Mitko");
	FirstRecord.setIP("42069");
	Cache.add(FirstRecord);
	char* LookUpRecord = new char[1000];
	std::cout << "Enter the name of the record you are looking for: " << std::endl;
	std::cin >> LookUpRecord;
	if (Cache.lookup(LookUpRecord) != NULL) std::cout << Cache.lookup(LookUpRecord) << std::endl;
	else std::cout << "NULL" << std::endl;
	Cache.print();
	Cache.flush();
	Cache.print();
	DNSRecord SecondRecord;
	SecondRecord.setIP("0000");
	SecondRecord.setName("Mitko2");
	DNSRecord ThirdRecord;
	ThirdRecord = SecondRecord;
	Cache.add(SecondRecord);
	Cache.add(FirstRecord);
	Cache.add(ThirdRecord);
	DNSCache Cache2;
	Cache2 = Cache;
	Cache.print();
	Cache.flush();
	Cache.print();
	Cache2.print();
	return 0;
}
