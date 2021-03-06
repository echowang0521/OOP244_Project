//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-04-01
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
namespace sdds {
  class Time {
     unsigned int m_min;
  public:
     Time& reset();
     Time(unsigned int min = 0);
     std::ostream& write(std::ostream& ostr) const;
     std::istream& read(std::istream& istr);
     operator int()const;
     Time& operator *= (int val);
     Time& operator-=(const Time& D);
  };
   std::ostream& operator<<(std::ostream& ostr, const Time& D);
   std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H
