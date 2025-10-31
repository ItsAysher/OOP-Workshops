#include <iostream>
#include "cstr.h" // for any string manipulation
#include "CC.h"
using namespace std;
namespace seneca {
	void CC::prnNumber(unsigned long long no) const {
		cout << no / 1000000000000ull << " ";
		no %= 1000000000000ull;
		cout.fill('0');
		cout.width(4);
		cout.setf(ios::right);
		cout << no / 100000000ull << " ";
		no %= 100000000ull;
		cout.width(4);
		cout << no / 10000ull << " ";
		no %= 10000ull;
		cout.width(4);
		cout << no;
		cout.unsetf(ios::right);
		cout.fill(' ');
	}
	void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
		char lname[31]{};
		strcpy(lname, name, 30);
		cout << "| ";
		cout.width(30);
		cout.fill(' ');
		cout.setf(ios::left);
		cout << lname << " | ";
		prnNumber(number);
		cout << " | " << cvv << " | ";
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout.width(2);
		cout << expMon << "/" << expYear << " |" << endl;
		cout.unsetf(ios::right);
	}
	/*
	Implement this private method to validate the credit card information received through the argument list as follows:
- name: should not be a null pointer and should be more than 2 characters long
- cardNo: values between 4000000000000000ull and 4099999999999999ull 
  > `ull` makes the literal number an `unsigned long long integer`)
- cvv: a three-digit number
- expMon: values between 1 and 12
- expYear: values between 24 and 32
  
The method should return true if all the conditions are met, otherwise, it will return false

This function does not modify the object (is constant).*/
	bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const {
		bool valid = true;
		if (name == nullptr || seneca::strlen(name) < 2 || seneca::strlen(name) > 70) {
			valid = false;
		}
		if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
			valid = false;
		}
		if (cvv < 100 || cvv > 999) {
			valid = false;
		}
		if (expMon < 1 || expMon > 12) {
			valid = false;
		}
		if (expYear < 23 || expYear > 32) {
			valid = false;
		}
		return valid;
	   }

   CC::CC() {
	   ccname = nullptr;
	   set();
   }
   CC::CC(const char* name, unsigned long long number, short cvv, short expMon, short expYear) {
	   ccname = nullptr;
	   set();
	   set(name, number, cvv, expMon, expYear);
   }
   CC::~CC() {
	   clear();
   }

   //Sets the object to a safe empty state by setting all the values to zero and the name pointer to `nullptr`.
   void CC::set() {
	   clear();
	   cvv = 0;
	   expMon = 0;
	   expYear = 0;
	   ccnumber = 0;
   }
   bool CC::isEmpty() const {
	   return this->ccname != nullptr ? true : false;
   }
   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
	   clear();
	   if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
		   aloCopy(cc_name);
		   this->ccnumber = cc_no;
		   this->cvv = cvv;
		   this->expMon = expMon;
		   this->expYear = expYear;
	   }
   }
   const char* CC::getName() const {
	   return ccname;
   }
   unsigned long long CC::getNumber() const {
	   return ccnumber;
   }
   short CC::getCvv() const {
	   return cvv;
   }
   short CC::getExpMon() const {
	   return expMon;
   }
   short CC::getExpYear() const {
	   return expYear;
   }
   void CC::aloCopy(const char* name) {
	   delete[] ccname;
	   if (name != nullptr && seneca::strlen(name) > 0) {
		   ccname = new char[seneca::strlen(name) + 1];
		   strcpy(ccname, name, strlen(name) + 1);
	   }
	   else {
		   ccname = nullptr;
	   }
   }
   void CC::display() const {
	   if (!isEmpty()) {
		   cout << "Invalid Credit Card Record" << endl;
	   }
	   else {
		   display(this->ccname, this->ccnumber, this->expYear, this->expMon, this->cvv);
	   }
	}
   // Create a private method (receives and returns nothing) to deallocate the memory pointed to by the character pointer attribute of the class, and then set the pointer to `nullptr`.
   void CC::clear() {
	   delete[] ccname;
	   ccname = nullptr;
   }
}