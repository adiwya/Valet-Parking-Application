// Name: Aparajeeta Diwya

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#define MAX_NO_OF_ITEMS 10
#include <iostream>
namespace sdds {
   class MenuItem {
      char givenText[51];
      MenuItem();
      MenuItem(const char* text);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      void setEmpty();
      MenuItem(const MenuItem& src) = delete;
      MenuItem& operator=(const MenuItem& src) = delete;
   public:
      friend class Menu;
   };
   class Menu {
      char givenTitle[51];
      MenuItem givenItem [MAX_NO_OF_ITEMS];
      int givenNoItems;
      int givenIndentation;
      Menu(const Menu& src) = delete;
      Menu& operator=(const Menu& src) = delete;
   public:
      Menu();
      Menu(const char* text, int indentation=0);
      Menu& operator=(const char* title);
      Menu& operator<<(const char* item);
      void add(const char* item);
      operator bool()const;
      bool isEmpty()const;
      void setEmpty();
      operator int()const;
      void clear();
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      std::ostream& indent(std::ostream& coutRef = std::cout)const;
      int run()const;
      int noOfItems()const;
   };
}
#endif