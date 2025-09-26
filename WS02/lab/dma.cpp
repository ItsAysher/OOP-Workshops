#include "dma.h"
#include "cstr.h"         // For strlen, strcpy

using namespace seneca;
using namespace std;

Samples* CreateSamples(const char* title) {
	Samples* sample = new Samples;
	sample->m_title = new char[seneca::strlen(title) + 1];
	seneca::strcpy(sample->m_title, title);
	sample->m_data = nullptr;
	sample->m_size = 0;
	return sample;
}

void add(Samples& S, const int data[], int size) {
	if (S.m_data == nullptr) {
		S.m_data = new int[size];
		for (int i = 0; i < size; i++) {
			S.m_data[i] = data[i];
		}
		S.m_size = size;
	}
	else {
		append(S.m_data, S.m_size, data, size);
		S.m_size += size;
	}
}

void append(int*& data, int size, const int appendedData[], int dataSize) {
	int* newData = new int[size + dataSize];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	for (int i = 0; i < dataSize; i++) {
		newData[size + i] = appendedData[i];
	}
	delete[] data;
	data = newData;
}

void freemem(Samples*& s) {
	delete[] s->m_title;
	delete[] s->m_data;
	delete s;
	s = nullptr;
}