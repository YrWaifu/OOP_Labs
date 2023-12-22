#include "wolf.hpp"

#include "bear.hpp"
#include "robber.hpp"

Wolf::Wolf(int x, int y) : NPC(WolfType, x, y) {}
Wolf::Wolf(std::istream &is) : NPC(WolfType, is) {}

void Wolf::print() { std::cout << *this; }

void Wolf::save(std::ostream &os) {
    os << WolfType << std::endl;
    NPC::save(os);
}

void Wolf::print(std::ostream &outfs) { outfs << *this; }

bool Wolf::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Wolf> This = std::make_shared<Wolf>(*this);
    return visitor->visit(This);
}

bool Wolf::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, true);
    return true;
}

bool Wolf::fight(std::shared_ptr<Wolf> other) {
    fight_notify(other, false);
    return false;
}

bool Wolf::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Wolf &wolf) {
    os << "Wolf 🐺: " << *static_cast<NPC *>(&wolf) << std::endl;
    return os;
}