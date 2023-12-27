#include "../include/factory.hpp"

std::shared_ptr<NPC> NPCFactory::create_NPC(NPC_type type, int x, int y) {
  std::shared_ptr<NPC> result;
  switch (type) {
    case BEAR:
      result = std::make_shared<bear>(x, y);
      break;
    case WEREWOLF:
      result = std::make_shared<werewolf>(x, y);
      break;
    case ROBBER:
      result = std::make_shared<robber>(x, y);
      break;

    default:
      break;
  }

  return result;
}

void NPCFactory::save(const set_t& s, const std::string& file_name) {
  std::ofstream out(file_name);
  out << s.size() << std::endl;
  for (auto& npc: s) {
    out << npc->get_type() << std::endl
        << npc->get_x() << std::endl
        << npc->get_y() << std::endl;
  }

  out.flush();
  out.close();
}

set_t NPCFactory::load(const std::string& file_name) {
  set_t result;
  std::ifstream in(file_name);
  std::shared_ptr<Observer> console_observer, file_observer;
  console_observer = std::make_shared<ConsoleObserver>();
  file_observer = std::make_shared<FileObserver>();

  if (in.good() && in.is_open()) {
    int count;
    in >> count;
    while (count--) {
      std::shared_ptr<NPC> npc;
      int x, y;
      std::string type;
      in >> type;
      if (type == "bear") {
        in >> x >> y;
        npc = std::make_shared<bear>(x, y);
        result.insert(npc);
      } else if (type == "werewolf") {
        in >> x >> y;
        npc = std::make_shared<werewolf>(x, y);
        result.insert(npc);
      } else if (type == "robber") {
        in >> x >> y;
        npc = std::make_shared<robber>(x, y);
        result.insert(npc);
      }
      npc->attach(console_observer);
      npc->attach(file_observer);
    }
  }

  return result;
}