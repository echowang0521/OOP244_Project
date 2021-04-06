//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-26
#include "Time.h"
#include "utils.h"
#include <ctype.h>
using namespace std;
namespace sdds {
  Time& Time::setToNow() {
    m_min = getTime();
    return *this;
  }

  Time::Time(unsigned int min) {
    m_min = min;
  }

  std::ostream& Time::write(std::ostream& ostr) const {
    string hour = to_string(m_min / 60);
    string min = to_string(m_min % 60);
    if (hour.length() < 2) {
      hour = "0" + hour;
    }
    if (min.length() < 2) {
      min = "0" + min;
    }

    ostr << hour << ":" << min;
    return ostr;
  }

  std::istream& Time::read(std::istream& istr) {
    string line;
    istr >> line;
    if (line.find(':') == std::string::npos) {
      istr.setstate(ios::failbit);
      return istr;
    } else {
      string hour;
      string min;
      bool first = false;
      for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != ':' && isdigit(line[i])) {
          if (!first) {
            hour += line[i];
          } else {
            min += line[i];
          }
        } else if (line[i] == ':') {
          first = true;
        } else {
          istr.setstate(ios::failbit);
          return istr;
        }
      }
      if (stoi(hour) >= 0 && stoi(min) >= 0) {
        this->m_min = stoi(hour) * 60 + stoi(min);
        return istr;
      }
    }
    istr.setstate(ios:: failbit);
    return istr;
  }

  Time& Time::operator-=(const Time& D) {
    int source_m = D.m_min;
    int target_m = this->m_min;
    if (target_m >= source_m) target_m -= source_m;
    else if (target_m < source_m) {
      while(target_m < source_m) {
        target_m += 1440;
      }
      target_m -= source_m;
    }
    this->m_min = target_m;
    return *this;
  }

  Time Time::operator-(const Time& D)const {
    int source_m = D.m_min;
    int target_m = this->m_min;
    if (target_m >= source_m) target_m -= source_m;
    else if (target_m < source_m) {
      while(target_m < source_m) {
        target_m += 1440;
      }
      target_m -= source_m;
    }
    Time t(target_m);
    return t;
  }

  Time& Time::operator+=(const Time& D) {
    int source_m = D.m_min;
    int target_m = this->m_min;
    target_m += source_m;
    this->m_min = target_m;
    return *this;
  }

  Time Time::operator+(const Time& D)const {
    int source_m = D.m_min;
    int target_m = this->m_min;
    target_m += source_m;
    Time t(target_m);
    return t;
  }

  Time& Time::operator=(unsigned int val) {
    this->m_min = val;
    return *this;
  }

  Time& Time::operator *= (unsigned int val) {
    int target_m = this->m_min;
    this->m_min = val * target_m;
    return *this;
  }

  Time& Time::operator /= (unsigned int val) {
    int target_m = this->m_min;
    this->m_min = target_m / val;
    return *this;
  }

  Time Time::operator * (unsigned int val)const {
    int target_m = this->m_min;
    int res = target_m * val;
    Time t(res);
    return t;
  }

  Time Time::operator / (unsigned int val)const {
    int target_m = this->m_min;
    int res = target_m / val;
    Time t(res);
    return t;
  }

  Time::operator unsigned int()const {
    return this->m_min;
  }

  Time::operator int()const {
    return (int)this->m_min;
  }

  ostream& operator<<(ostream& ostr, const Time& D) {
    D.write(ostr);
    return ostr;
  }

  istream& operator>>(istream& istr, Time& D) {
    D.read(istr);
    return istr;
  }

}
