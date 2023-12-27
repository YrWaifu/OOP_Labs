#pragma once

#include "werewolf.hpp"
#include "npc.hpp"
#include "robber.hpp"

class bear : public NPC {
public:
  bear(int x, int y);

  std::string get_type() override;

  int get_damage_range() const override;

  bool accept(std::shared_ptr<NPC> visitor) override;

  bool fight(std::shared_ptr<bear> accepter) override;

  bool fight(std::shared_ptr<werewolf> accepter) override;

  bool fight(std::shared_ptr<robber> accepter) override;

  void move(int max_x, int max_y) override;
};

