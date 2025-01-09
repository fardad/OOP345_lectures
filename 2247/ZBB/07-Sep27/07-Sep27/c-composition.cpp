#include <iostream>
#include <string>
using namespace std;
/*Composition:
House has a C-style array of Room pointers.
The Room objects are created and managed by the House, and they cannot exist independently of the House.
When the House is destroyed, the Room objects are also destroyed.
*/
class House;
class Room {
   string m_name;
   Room(string name) :m_name(name) {};
public:
   friend class House;// this is the ONLY time a friend is ok to be used
   // House can access Room's private members
};

class House {
   string m_address;
   Room* m_rooms[20]{};
   size_t m_roomCount{};
public:
   House(string address) : m_address(address) {};
   void addRoom(string room_name) {
      if (m_roomCount < 20) {
         m_rooms[m_roomCount++] = new Room(room_name);
      }
   }
   virtual ~House() {
      for (size_t i = 0; i < m_roomCount; i++) {
         delete m_rooms[i];
      }
   }
};
int main() {
   cout << "OOP345 ZBB - 07-Sep27" << endl;
   // Room R("Bedroom"); cannot be done, Room is private
   House H("123 yonge street");
   H.addRoom("Bedroom");
   H.addRoom("Kitchen");
   return 0;
}