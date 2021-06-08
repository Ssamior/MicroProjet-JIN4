#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "pugixml.hpp"
#include "GameWorld.h"
#include "Mine.h"



TEST(TestMapLoading, TestMapLoading1) {
    char* s = R"(<?xml version="1.0"?>
<IronMine x="7" y="12" level="1" rate="2" />
<Inventory ingot="0" iron="100" stone="200" coal="300" wood="1000" pollution="10" />)";
    GameWorld gameWorldTest(s, false);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Ingot), 0);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Iron), 100);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Stone), 200);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Coal), 300);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Wood), 1000);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Pollution), 10);
}

TEST(TestMine, TestMine1) {
    char* str = "image";
    auto mine = std::make_unique<Mine>(str, Item::Iron, 3, 4, 0, 0, 1);
    Inventory inventory = Inventory();

    EXPECT_EQ(inventory.getQuant(Item::Iron), 0);

    mine->update(sf::seconds(1), &inventory);
    EXPECT_EQ(inventory.getQuant(Item::Iron), 3);
    EXPECT_EQ(inventory.getQuant(Item::Coal), 0);
    EXPECT_EQ(inventory.getQuant(Item::Ingot), 0);
}

TEST(TestConsumer, TestConsumer1) {
    char* str = "image";
    //creation d'une mine qui utilise cree 3 Iron par seconde, et 4 Pollution
    auto mine = std::make_shared<Mine>(str, Item::Iron, 3, 4, 0, 0, 1);
    Inventory inventory = Inventory();
    EXPECT_EQ(inventory.getQuant(Item::Iron), 0);
    mine->update(sf::seconds(1), &inventory);
    EXPECT_EQ(inventory.getQuant(Item::Iron), 3);
    EXPECT_EQ(inventory.getQuant(Item::Coal), 0);
    EXPECT_EQ(inventory.getQuant(Item::Ingot), 0);
    EXPECT_EQ(inventory.getQuant(Item::Pollution), 4);
    //creation d'une fonderie qui utilise 3 Iron pour créer 1 Ingot toutes les secondes, et 4 Pollution
    auto mine2 = std::make_shared<Mine>(str, Item::Ingot, 3, 2, 0, 0, 1);
    auto furnace = std::make_shared<Consumer>(Item::Iron, 1, mine2);
    //Process de une seconde de la fonderie
    furnace->update(sf::seconds(1), &inventory);
    EXPECT_EQ(inventory.getQuant(Item::Iron), 2);
    EXPECT_EQ(inventory.getQuant(Item::Coal), 0);
    EXPECT_EQ(inventory.getQuant(Item::Ingot), 3);
    EXPECT_EQ(inventory.getQuant(Item::Pollution), 6);
}