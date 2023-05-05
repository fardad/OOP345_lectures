#include "IOAble.h"
namespace sdds {
   std::ostream& operator<<(std::ostream& os, const IOAble& T) {
      return T.display(os);
   }
   std::istream& operator>> (std::istream& is, IOAble& T) {
      return T.read(is);
   }
   IOAble::~IOAble() {
   }

   HideSubContent& HideSubContent::setOs(std::ostream& os) {
      m_os = &os;
      return *this;
   }
   HideSubContent& operator<<(std::ostream& os, HideSubContent& hs) {
      return hs.setOs(os);
   }
   std::ostream& HideSubContent::operator<<(const IOAble& obj) {
      IOAble* ptr = const_cast<IOAble*>(&obj);
      ptr->hideSubContent();
      return (*m_os) << obj;
   }
   HideSubContent hideNextSubContent;
}