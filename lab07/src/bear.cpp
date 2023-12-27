#include "../include/bear.hpp"

bear::bear(int x, int y) : NPC(NPC_type::BEAR, x, y, "bear_" + std::to_string(id++)) {}

std::string bear::get_type() {
  return "bear";
}

int bear::get_damage_range() const {
  return 10;
}

bool bear::accept(std::shared_ptr<NPC> visitor) {
  if (visitor->fight(std::shared_ptr<bear>(this, [](bear*) {}))) {
    return true;
  }
  return false;
}

bool bear::fight(std::shared_ptr<bear> accepter) {
  return false;
}

bool bear::fight(std::shared_ptr<werewolf> accepter) {
  if (this->get_energy() > accepter->get_energy()) {
    notify_killed(accepter);
    accepter->must_die();
    return true;
  }
  return false;
}

bool bear::fight(std::shared_ptr<robber> accepter) {
  return false;
}

void bear::move(int max_x, int max_y) {
  std::lock_guard<std::shared_mutex> lck(mutex);
  double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
          dist = static_cast<double>(std::rand() % 100) / 100 * 30;

  int shift_x = static_cast<int>(dist * std::cos(angle)),
          shift_y = static_cast<int>(dist * std::sin(angle));

  if ((x + shift_x >= 0) && (x + shift_x <= max_x))
    x += shift_x;
  if ((y + shift_y >= 0) && (y + shift_y <= max_y))
    y += shift_y;
}