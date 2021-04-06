//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-04-01
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
using namespace std;
namespace sdds {
  class Patient : public IOAble {
    char* patient_name = nullptr;
    int ohip_num = 0;
    Ticket ticket;
    bool file_io;
  public:
    Patient(int ticket_num = 0, bool io = false);
    ~Patient();
    virtual char type()const = 0;
    bool fileIO()const;
    void fileIO(bool io);
    bool operator==(const char another_char)const;
    bool operator==(const Patient& another_patient)const;
    void setArrivalTime();
    operator Time()const;
    int number()const;
    virtual ostream& csvWrite(ostream&)const;
    virtual istream& csvRead(istream&);
    virtual ostream& write(ostream&)const;
    virtual istream& read(istream&);
   };
  }
  #endif // !SDDS_PATIENT_H_
