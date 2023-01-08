// Name: Aparajeeta Diwya

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   MenuItem::MenuItem(){
      setEmpty();
   }
   MenuItem::MenuItem(const char* text){
      if (text != nullptr) {
         strcpy(givenText, text, 50);
         givenText[50] = 0;
      }
      else {
         setEmpty();
      }
   }
   ostream& MenuItem::display(ostream& coutRef) const{
      if (givenText[0] != 0) {
         coutRef << givenText << endl;
      }
      return coutRef;
   }
   void MenuItem::setEmpty(){
      givenText[0] = 0;
   }
   Menu::Menu(){
      setEmpty();
   }
   Menu::Menu(const char* text, int indentation){
      if (text != nullptr) {
         strcpy(givenTitle, text, 50);
         givenTitle[50] = 0;
         givenNoItems = 0;
         givenIndentation = indentation;
      }
      else {
         setEmpty();
      }
   }
   Menu::operator bool() const{
      return (givenTitle[0] != 0);
   }
   bool Menu::isEmpty() const{
      return (givenTitle[0] == 0);
   }
   void Menu::setEmpty(){
      givenTitle[0] = 0;
      for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
         givenItem[i].givenText[0] = '\0';
      }
      givenNoItems = 0;
      givenIndentation = 0;
   }
   std::ostream& Menu::display(std::ostream& coutRef) const{
      if (givenTitle[0] == 0){
         coutRef << "Invalid Menu!" << endl;
      }
      else if (givenNoItems == 0){
         indent(coutRef) << givenTitle << endl;
         coutRef << "No Items to display!" << endl;
      }
      else {
         indent(coutRef) << givenTitle << endl;
         for (int i = 0; i < givenNoItems; i++)
         {
            indent(coutRef) << i + 1 << "-";
            coutRef << " " << givenItem[i].givenText << endl;
         }
         indent(coutRef) << "> ";
      }
      return coutRef;
   }
   std::ostream& Menu::indent(std::ostream& coutRef) const{
      if (givenIndentation != 0) {
         for (int i = 0; i < givenIndentation; i++)
         {
            coutRef << "    ";
         }
      }
      return coutRef;
   }
    Menu& Menu::operator=(const char* title){
      if (title != nullptr) {
         strcpy(givenTitle, title, 50);
         givenTitle[50] = 0;
      }
      return *this;
   }
   Menu& Menu::operator<<(const char* item){
      if (item != nullptr) {
         add(item);
      }
      else {
         setEmpty();
      }
      return *this;

   }
   void Menu::add(const char* item){
      if (givenItem[9].givenText[0] != '\0' || isEmpty()) {
      }
      else {
         if (item == nullptr) {
            setEmpty();
         }
         else {
            if (givenItem[givenNoItems].givenText[0] == '\0') {
               strcpy(givenItem[givenNoItems].givenText, item, 50);
               givenNoItems++;
            }
         }
      }
   }
   int Menu::run() const{
      int select;
      display();
      if (givenNoItems == 0 || isEmpty())
      {
         select = 0;
      }
      else
      {
         do {
            do {
               if (cin.fail()) {
                  cin.clear();
                  cin.ignore(256, '\n');
                  cout << "Invalid Integer, try again: ";
               }
               cin >> select;
            } while (cin.fail());
            if (select < 1 || select > givenNoItems) {
               cout << "Invalid selection, try again: ";
            }
         } while (select < 1 || select > givenNoItems);
         
      }
      return select;
   }
   int Menu::noOfItems() const{
      return givenNoItems;
   }
   Menu::operator int() const{
      return run();
   }
   void Menu::clear(){
      for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
         givenItem[i].givenText[0] = '\0';
      }
      givenNoItems = 0;
      givenNoItems = 0;
   }
}