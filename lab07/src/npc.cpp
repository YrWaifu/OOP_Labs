#include "../include/npc.hpp"

NPC::NPC(NPC_type type, int x, int y, const std::string& name) : type(type), x(x), y(y), name(name) {}

const int NPC::get_x() const {
  std::shared_lock<std::shared_mutex> lock(mutex);
  return x;
}

const int NPC::get_y() const {
  std::shared_lock<std::shared_mutex> lock(mutex);
  return y;
}

int NPC::get_energy() const {
  return std::rand() % 6 + 1;
}

const std::string& NPC::get_name() const {
  return name;
}

bool NPC::alive() const {
  std::shared_lock<std::shared_mutex> lock(mutex);
  return _alive;
}

void NPC::attach(std::shared_ptr<Observer> observer) {
  std::lock_guard<std::shared_mutex> lck(mutex);
  observers.push_back(observer);
}

void NPC::notify_killed(const std::shared_ptr<NPC> defender) {
  std::shared_lock<std::shared_mutex> lock(mutex);
  for (auto& o: observers) {
    o->report_killed(std::shared_ptr<NPC>(this, [](NPC*) {}), defender);
  }
}

bool NPC::near(const std::shared_ptr<NPC>& enemy, size_t distance) const {
  std::shared_lock<std::shared_mutex> lock(mutex);
  return std::pow(x - enemy->x, 2) + std::pow(y - enemy->y, 2) <= std::pow(distance, 2);
}

void NPC::must_die() {
  std::lock_guard<std::shared_mutex> lck(mutex);
  _alive = false;
}

std::ostream& operator<<(std::ostream& out, const NPC& npc) {
  return out << npc.name << " {x : " << npc.x << ", y : " << npc.y << "}";
}

int NPC::id = 0;