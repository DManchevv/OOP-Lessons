#include <iostream>
#include "DNSCache.h"
DNSCache::DNSCache() {
	size = 0;
	records = new DNSRecord[size];
}
DNSCache::~DNSCache() {
	delete[] records;
}
DNSCache::DNSCache(const DNSCache& CopyFrom) {
	size = CopyFrom.size;
	records = nullptr;
	records = new DNSRecord[size + 1];
	for (size_t i = 0; i < size; i++) {
		records[i] = CopyFrom.records[i];
	}
}
DNSCache& DNSCache::operator=(const DNSCache& other) {
	if (this != &other) {
		size = other.size;
		records = new DNSRecord[size];
		for (size_t i = 0; i < size; i++) {
			records[i] = other.records[i];
		}
	}
	return *this;
}
void DNSCache::add(DNSRecord record) {
	DNSRecord * newRecords = new DNSRecord[size + 1];
	for (int i = 0; i < size; i++) {
		newRecords[i] = records[i];
	}
	newRecords[size] = record;
	delete[] records;
	records = newRecords;
	size++;
}
const char* DNSCache::lookup(const char* LookRecord) {
	for (size_t i = 0; i < size; i++) {
		if (strcmp(records[i].getName(), LookRecord) == 0) return records[i].getIP();
	}
	return NULL;
}
void DNSCache::flush() {
	delete[] records;
	size = 0;
	records = new DNSRecord[size];
}
void DNSCache::print() {
	std::cout << "The current cache is: " << std::endl;
	if (size == 0) std::cout << " --------------------------------------- " << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::cout << records[i].getName() << " " << records[i].getIP() << std::endl;
	}
}
