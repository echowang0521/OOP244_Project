//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-04-01
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds {
  Patient::Patient(int ticket_num, bool io) : ticket(ticket_num) {
    file_io = io;
  }

  Patient::~Patient() {
    delete[] patient_name;
  }

  bool Patient::fileIO()const {
    return file_io;
  }

  void Patient::fileIO(bool io) {
    file_io = io;
  }

  bool Patient::operator==(const char another_char)const {
    return another_char == type();
  }

  bool Patient::operator==(const Patient& another_patient)const {
    return type() == another_patient.type();
  }

  void Patient::setArrivalTime() {
    ticket.resetTime();
  }

  Patient::operator Time()const {
    return Time(ticket);
  }

  int Patient::number()const {
    return ticket.number();
  }

  ostream& Patient::csvWrite(ostream& ostr)const {
    ostr << type() << ',' << patient_name << ',' << ohip_num << ',';
    ticket.csvWrite(ostr);
    return ostr;
  }

  istream& Patient::csvRead(istream& istr) {
    char a[80];
    istr.get(a, 80, ',');
    delete[] patient_name;
    patient_name = new char[strlen(a) + 1];
    strcpy(patient_name, a);
    istr.ignore(1000, ',');
    istr >> ohip_num;
    istr.ignore(1000, ',');
    ticket.csvRead(istr);
    return istr;
  }

  ostream& Patient::write(ostream& ostr)const {
    ticket.write(ostr) << endl;
    if (strlen(patient_name) > 26) {
      char newPatient[26];
      strncpy(newPatient, patient_name, 26);
      newPatient[25]='\0';
      ostr << newPatient << ", OHIP: " << ohip_num;
    } else {
      ostr << patient_name << ", OHIP: " << ohip_num;
    }
    return ostr;
  }

  istream& Patient::read(istream& istr) {
    char a[51];
    int num;
    bool status = false;
    cout << "Name: ";
    istr.get(a, 51, '\n');
    delete[] patient_name;
    patient_name = new char[strlen(a) + 1];
    strcpy(patient_name, a);
    istr.ignore(1000, '\n');

    cout << "OHIP:";
    while(!status) {
      istr >> num;
      if (istr.fail()) {
        cout << "Bad integer value, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
      } else {
        if (num < 100000000 || num > 999999999) {
          cout << "Invalid OHIP Number, [100000000 <= value <= 999999999]: ";
          cin.ignore(1000, '\n');
        } else {
          ohip_num = num;
          cin.ignore(1000, '\n');
          status = true;
        }
      }
    }

    return istr;
  }
}
