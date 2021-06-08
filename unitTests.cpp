#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "pugixml.hpp"
#include "GameWorld.h"


TEST(TestMapLoading, TestMapLoading1) {
    char* s = R"(<?xml version="1.0"?>
        <Mine x="0" y="0" level="1" />
        <Mine x="2" y="2" level="2" />
        <Inventory ingot="50" iron="100" coal="150" />)";
    GameWorld gameWorldTest(s, false);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Ingot), 50);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Iron), 100);
    EXPECT_EQ(gameWorldTest.getInventory().getQuant(Item::Coal), 150);
}
