#pragma once
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds {
   class IOAble {
   public:
      virtual std::ostream& display(std::ostream& os = std::cout)const = 0;
      virtual std::istream& read(std::istream& is = std::cin) = 0;
      virtual void hideSubContent() = 0;
      virtual ~IOAble();
   };





   // this is an IOAble manipulator to change the state of IOAble in next
   // printout
   class HideSubContent {
      // ostream pointer to keep the ostream so it can be returned after
      // the manipulation is complete
      std::ostream* m_os = &std::cout;
   public:
      // sets the m_os to the ostream in first stage of manipulation
      HideSubContent& setOs(std::ostream& os);
      // recieves the IOAble for manipulation and then 
      // passes the object to the ostream for ouput
      std::ostream& operator<<(const IOAble& obj);
   };
   std::ostream& operator<<(std::ostream& os, const IOAble& T);
   std::istream& operator>> (std::istream& is, IOAble& T);

   HideSubContent& operator<<(std::ostream& os, HideSubContent& hs);
   extern HideSubContent hideNextSubContent;
}
#endif 