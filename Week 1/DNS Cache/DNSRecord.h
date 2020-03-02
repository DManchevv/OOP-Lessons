#pragma once
#include <cstring>
struct DNSRecord {
private:
	char* domainName;
	char* ipAddress;
public:
	DNSRecord();
	~DNSRecord();
	DNSRecord& operator=(const DNSRecord& other);
	DNSRecord(const DNSRecord& CopyFrom);
	const char* getIP() const;
	void setIP(const char* newIP);
	const char * getName() const;
	void setName(const char* Name);
};

