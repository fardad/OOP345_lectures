#include <iostream>
using namespace std;

class Ticket {
public:
    enum class TicketType { Adult, Child };

    void set(TicketType tt) { ticketType = tt; }
    auto get() const -> TicketType; // trailing return type

private:
    TicketType ticketType;
};

auto Ticket::get() const -> TicketType {
    return ticketType;
}

ostream& operator<<(ostream& os, const Ticket::TicketType& tt) {
    switch (tt) {
    case Ticket::TicketType::Adult: os << "Adult Ticket"; break;
    case Ticket::TicketType::Child: os << "Child Ticket"; break;
    }
    return os;
}
auto main()->int {
    cout << "OOP345 NAA - May 27" << endl;
    Ticket a, b;
    a.set(Ticket::TicketType::Adult);
    b.set(Ticket::TicketType::Child);

    cout << a.get() << endl;
    cout << b.get() << endl;
    return 0;
}