//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-15
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <regex>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h

   int getInt(
      int min,   // minimum acceptable value
      int max,   // maximum acceptable value
      const char* prompt,  // User entry prompt
      const char* errorMessage, // Invalid value error message
      bool showRangeAtError    // display the range if invalud value entered
   ) {
     int num = getInt(prompt);
     if (num < min || num > max) {
       if (errorMessage != nullptr) cout << errorMessage;
       if (showRangeAtError) cout << "[" + to_string(min) + " <= value <= " + to_string(max) + "]: ";
       return getInt(min, max, "", errorMessage);
     }
     return num;
   }
   int getInt(const char* prompt) {
     if (prompt != nullptr) cout << prompt;

     string s;
     getline(cin >> ws, s);
     bool isValid = is_number(s);
     if (isValid) {
       return stoi(s);
     } else if (isdigit(s[0])) {
       return getInt("Enter only an integer, try again: ");
     } else {
       return getInt("Bad integer value, try again: ");
     }
   }

   bool is_number(const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
      if (!isdigit(s[i]) || s[i] == ' ') return false;
    }
    return true;
  }
   int getTime() {
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   char* getcstr(
       const char* prompt,   // User entry prompt
       std::istream& istr,  // the Stream to read from
       char delimiter    // Delimiter to mark the end of data
    ) {
      if (prompt != nullptr) cout << prompt;
      string line;
      getline(istr >> ws, line);
      char* result = new char[strlen(line.c_str()) + 1];
      strcpy(result, line.c_str());
      return result;
    }

  // int getTime() {
  //   return ( time( 0 ) % 3600 ) / 60;
  // }
}
