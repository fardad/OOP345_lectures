// file: auto_return.cpp
#include <iostream>
using namespace std;

class Ticket {
public:
   enum class TicketType { Adult, Child };

   void set(TicketType tt) { ticketType = tt; }
   auto get() const->TicketType; // trailing return type

private:
   TicketType ticketType;
};

auto Ticket::get() const -> TicketType {
   return ticketType;
}

auto operator<<(ostream& os, const Ticket::TicketType& tt)->ostream& {
   switch (tt) {
   case Ticket::TicketType::Adult: os << "Adult Ticket"; break;
   case Ticket::TicketType::Child: os << "Child Ticket"; break;
   }
   return os;
}

int main() {
   Ticket a, b;
   a.set(Ticket::TicketType::Adult);
   b.set(Ticket::TicketType::Child);

   auto tt = a.get();

   cout << a.get() << endl;
   cout << b.get() << endl;
   return 0;
}