#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstdio>
#include <cstddef>
#include <iostream>

namespace seneca {
	struct PhoneRec {
		char first[16];
		char last[26];
		long long number;
	};
	
	void read(char* name);
	void print(long long phone);
	void print(const PhoneRec& rec, size_t& row, const char* name = nullptr);
	bool read(PhoneRec& rec, std::FILE* fptr);
	void print(const PhoneRec* const recs[], size_t num, const char* name = nullptr);
	void sort(PhoneRec* recs[], size_t num, bool byLast);
	void setPointers(PhoneRec* pRecs[], PhoneRec recs[], size_t num);
}

#endif // !SENECA_IO_H