//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-22
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
using namespace std;
namespace sdds {
   class IOAble {
   public:
       virtual ostream& csvWrite(ostream& ostr)const = 0;
  	   virtual istream& csvRead(istream& istr) = 0;
  	   virtual ostream& write(ostream& ostr)const = 0;
  	   virtual istream& read(istream& istr) = 0;
  	   virtual ~IOAble() {};
   };
   ostream& operator<<(ostream& os, const IOAble& ro);
   istream& operator>>(istream& is, IOAble& ro);
}
#endif // !SDDS_UTILS_H_
