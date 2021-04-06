//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-04-01
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Patient.h"
using namespace std;
namespace sdds {
  class TriagePatient : public Patient {
    char* symptoms;
  public:
    TriagePatient();
    ~TriagePatient();
    virtual char type() const;
    virtual ostream& csvWrite(ostream&) const;
    virtual istream& csvRead(istream&);
    virtual ostream& write(ostream&) const;
    virtual istream& read(istream&);
  };
}
#endif // !SDDS_TRIAGEPATIENT_H
