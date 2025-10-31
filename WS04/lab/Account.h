/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Ashar Afzal	   2025/10/07      Completing lab
//Ashar Afzal	   2025/10/10      Implementing missing functions
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;
      // state check, checks if account is valid or invalid
	  operator bool()const;
	  // int conversion operator, returns the account number
	  operator int()const;
      //  Double. Returns the **balance value**. This operator does not modify the **Account** object.
	  operator double()const;
      // char. Returns the address of the **account holder’s name**. This operator does not modify the **Account** object.
	  operator const char* ()const;
      // char& operator[](int index). Returns a reference to the character at the specified `index` in the account holder’s name. This operator allows modification of the character at that position. If the `index` is out of bounds, it should safely handle the request by looping back (e.g., `A[30]` should behave the same as `A[0]`).
	  char& operator[](int index);
      // sets the account to an empty state
	  void setEmpty();

      Account& operator=(double balance);
      Account& operator=(int number);
      Account& operator<<(Account&);
	  Account& operator>>(Account&);
	  Account& operator+=(double value);
	  Account& operator-=(double value);
	  Account& operator++(); // prefix
   };
}
#endif // SENECA_ACCOUNT_H_