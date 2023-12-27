#pragma once

#include "observer.hpp"

class NPCFactory {
public:
  NPCFactory() = default;

  virtual ~NPCFactory() = default;

  std::shared_ptr<NPC> create_NPC(NPC_type type, int x, int y);

  void save(const set_t& s, const std::string& file_name);

  set_t load(const std::string& file_name);
};
