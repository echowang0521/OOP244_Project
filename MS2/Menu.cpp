//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-22
#include "Time.h"
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
  Menu::Menu(const char* text, int NoOfSelections) {
        m_text = nullptr;
        delete[] m_text;
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
        m_noOfSel = NoOfSelections;
    }
    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }
    void Menu::display()const {
        cout << m_text << endl;
        cout << "0- Exit\n" << "> ";
    }

    int& Menu::operator>>(int& Selection) {
        display();

        Selection = getInt("MENU", m_noOfSel);
        return Selection;
    }

}
