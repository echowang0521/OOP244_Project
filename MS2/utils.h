//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-15
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files

   // int getTime();
   int getInt();
   int getInt(const char* type, int num);
   int getTime(); // returns the time of day in minutes
   bool is_number(const std::string &s);
   char* getcstr(
       const char* prompt = nullptr,   // User entry prompt
       std::istream& istr = std::cin,  // the Stream to read from
       char delimiter = '\n'    // Delimiter to mark the end of data
    );
}
#endif // !SDDS_UTILS_H_
