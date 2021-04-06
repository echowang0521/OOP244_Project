//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-15
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <strings.h>
#include <cstring>
#include <regex>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h

   int getInt() {
     int v;
      bool b;
      char c;
      do {
         b = false;
         cin >> v;
         if (cin.fail()) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(3000, '\n');
            b = true;
         }
         else {
           c = cin.get();
           if (c != '\n') {
             cout << "Enter only an integer, try again: ";
             cin.ignore(3000, '\n');
             b = true;
           }
         }
     } while(b);
     return v;
   }

   int getInt(const char* type, int num) {
     int value;
     value = getInt();
     if (strcmp(type, "OHIP") == 0) {
       while (value < 100000000 || value > 999999999) {
         cout << "Invalid option [100000000 <= value <= 999999999]: ";
         cin.clear();
         value = getInt();
       }
     }
      else if (strcmp(type, "MENU") == 0) {
        while (value < 0 || value > num) {
          cin.clear();
          cout << "Invalid option [0 <= value <= " << num << "]: ";
          value = getInt();
        }
      }
      return value;
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
