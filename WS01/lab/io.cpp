#define _CRT_SECURE_NO_WARNINGS

#include "io.h"
#include "cstr.h"
#include <iostream>
#include <cstdio>


using namespace std;
namespace seneca {

	void read(char* name) {
		cout << "Name\n> ";
		cin >> name;
	}

	void print(long long phone) {
		cout << '(' << phone / 10000000 << ") " << (phone / 10000) % 1000 << '-' << phone % 10000;
	}

	void print(const PhoneRec& rec, size_t& row, const char* name) {
		if (!name || strstr(rec.first, name) || strstr(rec.last, name)) {
			cout << row++ << ": " << rec.first << " " << rec.last << " ";
			print(rec.number);
			cout << endl;
		}
	}
		
	bool read(PhoneRec& rec, FILE* fptr) {
		return fscanf(fptr, "%15[^\t]\t%25[^\t]\t%lld\n", rec.first, rec.last, &rec.number) == 3;
	}

	void print(const PhoneRec* const recs[], size_t num, const char* name) {
		size_t row = 1;
		for (size_t i = 0; i < num; i++) {
			print(*recs[i], row, name);
		}
	}

	void sort(PhoneRec* recs[], size_t num, bool byLast) {
		for (size_t i = 0; i < num - 1; i++) {
			for (size_t j = i + 1; j < num; j++) {
				if (byLast) {
					if (seneca::strcmp(recs[i]->last, recs[j]->last) > 0) {
						PhoneRec* temp = recs[i];
						recs[i] = recs[j];
						recs[j] = temp;
					}
				}
				else {
					if (seneca::strcmp(recs[i]->first, recs[j]->first) > 0) {
						PhoneRec* temp = recs[i];
						recs[i] = recs[j];
						recs[j] = temp;
					}
				}
			}
		}

	}

	void setPointers(PhoneRec* pRecs[], PhoneRec recs[], size_t num) {
		for (size_t i = 0; i < num; i++) {
			pRecs[i] = &recs[i];
		}
	}

}