#pragma once
#include "DNSRecord.h"
#include <cstring>
class DNSCache {
private:
	DNSRecord * records;
	int size = 0;
public:
	DNSCache();
	~DNSCache();
	DNSCache(const DNSCache& CopyFrom);
	DNSCache& operator=(const DNSCache& other);
	void add(DNSRecord record);
	const char* lookup(const char* LookRecord);
	void flush();
	void print();
};
