#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient():Patient(nextCovidTicket, fileIO()) {
     nextCovidTicket++;
   }

   char CovidPatient::type() const {
     return 'C';
   }

   ostream& CovidPatient::csvWrite(ostream& ostr) const {
     Patient::csvWrite(ostr);
     return ostr;
   }

   istream& CovidPatient::csvRead(istream& istr) {
     Patient::csvRead(istr);
     nextCovidTicket = (Patient::number() + 1);
     return istr;
   }

   ostream& CovidPatient::write(ostream& ostr) const {
     if (fileIO()) {
       Patient::csvWrite(ostr);
     } else {
       ostr << "COVID TEST" << '\n';
       Patient::write(ostr) << '\n';
     }
     return ostr;
   }

   istream& CovidPatient::read(istream& istr) {
     if (fileIO()) {
       csvRead(istr);
     } else {
       Patient::read(istr);
     }
     return istr;
   }
}
