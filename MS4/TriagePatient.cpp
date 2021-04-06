
//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-04-01
#include<cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient():Patient(nextTriageTicket, fileIO()) {
     symptoms = nullptr;
     nextTriageTicket++;
   }

   TriagePatient::~TriagePatient() {
     delete[] symptoms;
     symptoms = nullptr;
   }

   char TriagePatient::type() const {
     return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& ostr)const {
     Patient::csvWrite(ostr);
     ostr << "," << symptoms;
     return ostr;
   }

   istream& TriagePatient::csvRead(istream& istr) {
     char new_symptom[511];
     delete[] symptoms;
     symptoms = nullptr;
     Patient::csvRead(istr);
     istr.ignore(511, ',');
     istr.get(new_symptom, 511, '\n');
     symptoms = new char[strlen(new_symptom) + 1];
     strcpy(symptoms, new_symptom);
     nextTriageTicket = (Patient::number() + 1);
     return istr;
   }

   ostream& TriagePatient::write(ostream& ostr) const {
     if (fileIO()) {
       csvWrite(ostr);
     } else {
       ostr << "TRIAGE" << '\n';
       Patient::write(ostr) << '\n';
       ostr << "Symptoms: " << symptoms << '\n';
     }
     return ostr;
   }

   istream& TriagePatient::read(istream& istr) {
     if (fileIO()) {
       csvRead(istr);
     } else {
       char new_symptom[511];
       delete[] symptoms;
       symptoms = nullptr;
       Patient::read(istr);
       cout << "Symptoms: ";
       istr.get(new_symptom, 511, '\n');
       istr.ignore(511, '\n');
       symptoms = new char[strlen(new_symptom) + 1];
       strcpy(symptoms, new_symptom);
     }
     return istr;
   }
}
