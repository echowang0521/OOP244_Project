//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-22
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   class Menu {
      char* m_text; // holds the menu content dynamically
      int m_noOfSel;  // holds the number of options displayed in menu content
      void display()const;
   public:
      Menu(const char* MenuContent, int NoOfSelections);
      virtual ~Menu();
      int& operator>>(int& Selection);
      Menu& operator=(const Menu&);
      // add safe copying logic
   };
}
#endif // !SDDS_UTILS_H_
