#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      void aloCopy(const char* name);

	  char* ccname;
	  short cvv;
	  short expMon;
	  short expYear;
	  unsigned long long ccnumber;
	  bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
	  void clear();

   public:
	   CC();
	   CC(const char* name, unsigned long long number, short cvv, short expMon = 12, short expYear = 26);
	   ~CC();
	   //Sets the object to a safe empty state by setting all the values to zero and the name pointer to `nullptr`.
	   void set();
	   bool isEmpty() const;
	   void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
	   const char* getName() const;
	   unsigned long long getNumber() const;
	   short getCvv() const;
	   short getExpMon() const;
	   short getExpYear() const;
	   void display() const;
   };

}
#endif // !SENECA_CC_H_


