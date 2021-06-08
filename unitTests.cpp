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