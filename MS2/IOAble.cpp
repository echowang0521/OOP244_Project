//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-22
#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds {
  ostream& operator<<(ostream& os, const IOAble& ro) {
    return ro.write(os);
  }
  istream& operator>>(istream& is, IOAble& ro) {
    return ro.read(is);
  }
}
