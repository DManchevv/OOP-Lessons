#include <iostream>
#include "DNSRecord.h"
DNSRecord::DNSRecord() {
	domainName = nullptr;
	ipAddress = nullptr;
}
DNSRecord::~DNSRecord() {
	delete[] domainName;
	delete[] ipAddress;
}
DNSRecord::DNSRecord(const DNSRecord& CopyFrom) {
	domainName = nullptr;
	ipAddress = nullptr;
	setIP(CopyFrom.ipAddress);
	setName(CopyFrom.domainName);
}
const char* DNSRecord::getIP() const {
	return ipAddress;
}
const char * DNSRecord::getName() const {
	return domainName;
}
void DNSRecord::setIP(const char* newIP) {
		delete[] ipAddress;
		ipAddress = new char[strlen(newIP) + 1];
		strcpy(ipAddress, newIP);
}
void DNSRecord::setName(const char* Name) {
		delete[] domainName;
		domainName = new char[strlen(Name) + 1];
		strcpy(domainName, Name);
}
DNSRecord& DNSRecord::operator=(const DNSRecord& other) {
	if (this != &other) {
		setName(other.domainName);
		setIP(other.ipAddress);
	}
	return *this;
}
