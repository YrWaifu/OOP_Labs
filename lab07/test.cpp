#include "./include/factory.hpp"
#include "./include/fight.hpp"
#include "gtest/gtest.h"

TEST(NPCFactoryTest, CreateNPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
        std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
        std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.create_NPC(NPC_type::BEAR, 1, 2));
        s.insert(factory.create_NPC(NPC_type::WEREWOLF, 3, 4));
        s.insert(factory.create_NPC(NPC_type::ROBBER, 5, 6));
        factory.save(s, "test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<bear>(1, 2);
    std::stringstream expected_output;
    expected_output << "bear_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
    std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 5, 6);

    EXPECT_EQ(bear->get_type(), "bear");
    EXPECT_EQ(werewolf->get_type(), "werewolf");
    EXPECT_EQ(squirrel->get_type(), "robber");

    EXPECT_TRUE(bear->alive());
    EXPECT_TRUE(werewolf->alive());
    EXPECT_TRUE(squirrel->alive());

    EXPECT_EQ(bear->get_x(), 1);
    EXPECT_EQ(werewolf->get_x(), 3);
    EXPECT_EQ(squirrel->get_x(), 5);
    EXPECT_EQ(bear->get_y(), 2);
    EXPECT_EQ(werewolf->get_y(), 4);
    EXPECT_EQ(squirrel->get_y(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 1);
    std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 50, 1);
    std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 100, 1);

    EXPECT_FALSE(bear->near(werewolf, 10));
    EXPECT_TRUE(bear->near(werewolf, 60));
    EXPECT_FALSE(bear->near(squirrel, 90));
    EXPECT_TRUE(bear->near(squirrel, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 1);
    std::shared_ptr<Observer> console_observer, file_observer;
    console_observer = std::make_shared<ConsoleObserver>();
    file_observer = std::make_shared<FileObserver>();
    bool test = true;
    try {
        bear->attach(console_observer);
        bear->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(bearTest, ConstructorAndGetters) {
    bear bear(1, 2);
    EXPECT_EQ(bear.get_x(), 1);
    EXPECT_EQ(bear.get_y(), 2);
    EXPECT_TRUE(bear.alive());
    EXPECT_EQ(bear.get_type(), "bear");
}

TEST(bearTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
    std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 5, 6);

    EXPECT_FALSE(bear->accept(bear));
    EXPECT_FALSE(bear->accept(squirrel));
    EXPECT_TRUE(bear->alive());
}

TEST(werewolfTest, ConstructorAndGetters) {
    werewolf werewolf(1, 2);
    EXPECT_EQ(werewolf.get_x(), 1);
    EXPECT_EQ(werewolf.get_y(), 2);
    EXPECT_TRUE(werewolf.alive());
    EXPECT_EQ(werewolf.get_type(), "werewolf");
}

TEST(werewolfTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 5, 6);

    EXPECT_FALSE(werewolf->accept(werewolf));
    EXPECT_FALSE(werewolf->accept(squirrel));
    EXPECT_TRUE(werewolf->alive());
}

TEST(SquirrelTest, ConstructorAndGetters) {
    robber squirrel(1, 2);
    EXPECT_EQ(squirrel.get_x(), 1);
    EXPECT_EQ(squirrel.get_y(), 2);
    EXPECT_TRUE(squirrel.alive());
    EXPECT_EQ(squirrel.get_type(), "robber");
}

TEST(SquirrelTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
    std::shared_ptr<NPC> squirrel = factory.create_NPC(NPC_type::ROBBER, 5, 6);

    EXPECT_FALSE(squirrel->accept(bear));
    EXPECT_TRUE(squirrel->alive());
    remove("battle_stats.txt");
    remove("test.txt");
}

TEST(FightManagerTest, GetReturnsSingletonInstance) {
    FightManager& instance1 = FightManager::get();
    FightManager& instance2 = FightManager::get();

    EXPECT_EQ(&instance1, &instance2);
}

TEST(FightManagerTest, AddEventAddsEventToQueue) {
    FightManager& manager = FightManager::get();
    FightEvent event;

    bool test = true;
    try {
        manager.add_event(std::move(event));
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}