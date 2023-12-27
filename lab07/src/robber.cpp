#include "../include/robber.hpp"

robber::robber(int x, int y) : NPC(NPC_type::ROBBER, x, y, "robber_" + std::to_string(id++)) {}

std::string robber::get_type() {
  return "robber";
}

int robber::get_damage_range() const {
  return 5;
}

bool robber::accept(std::shared_ptr<NPC> visitor) {
  if (visitor->fight(std::shared_ptr<robber>(this, [](robber*) {}))) {
    return true;
  }
  return false;
}

bool robber::fight(std::shared_ptr<robber> accepter) {
  return false;
}

bool robber::fight(std::shared_ptr<werewolf> accepter) {
  return false;
}

bool robber::fight(std::shared_ptr<bear> accepter) {
  if (this->get_energy() > accepter->get_energy()) {
    notify_killed(accepter);
    accepter->must_die();
    return true;
  }
  return false;
}

void robber::move(int max_x, int max_y) {
  std::lock_guard<std::shared_mutex> lck(mutex);
  double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
          dist = static_cast<double>(std::rand() % 100) / 100 * 5;

  int shift_x = static_cast<int>(dist * std::cos(angle)),
          shift_y = static_cast<int>(dist * std::sin(angle));

  if ((x + shift_x >= 0) && (x + shift_x <= max_x))
    x += shift_x;
  if ((y + shift_y >= 0) && (y + shift_y <= max_y))
    y += shift_y;
}