/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ashar Afzal     2025/10/07      Completing lab
// Ashar Afzal	   2025/10/10      Implementing missing functions
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
 

   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }
   Account::operator bool()const {
       // An account is considered **valid** if it has a 5-digit integer account number, a non-negative balance, and a non-empty C-string for the account holder name.
	   return isValidNumber(m_number) && m_balance >= 0 && m_holderName[0];
   }

   Account::operator int()const {
	   // returns the account number
	   return m_number;
   }
   Account::operator double()const {
	   // Returns the **balance value**. This operator does not modify the **Account** object.
       return m_balance;
   }
   Account::operator const char* () const {
	   // Returns the address of the **account holder’s name**. This operator does not modify the **Account** object.
	   return m_holderName;
   }
   char& Account::operator[](int index) {
	   // Returns a reference to the character at the specified `index` in the account holder’s name. This operator allows modification of the character at that position. If the `index` is out of bounds, it should safely handle the request by looping back (e.g., `A[30]` should behave the same as `A[0]`).
	   if (index < 0) {
		   index = (index % NameMaxLen + NameMaxLen) % NameMaxLen;
	   }
	   else if (index >= NameMaxLen) {
		   index = index % NameMaxLen;
	   }
	   return m_holderName[index];
   }
   // prefix
   // Increases the account balance by 1 unit and returns the updated Account object.
   
   Account& Account::operator++() {
	   m_balance += 1.0;
	   return *this;
   }
   /* *Overload the** `+ = ` operator**to add a double value to an Account.This should act like depositing money into an Account(i.e., the value should be added to the balance).
       If the Account is invalid or the value is negative, no action should be taken.
       In any case, a reference to the** current object** (**Account**) should be returned. */
   Account& Account::operator+=(double value) {
	   m_balance += (value > 0 && *this) ? value : 0;
	   return *this;
   }
   
}