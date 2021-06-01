#include <gtest/gtest.h>
#include <string>
#include "pugixml.hpp"
#include "Group.h"
#include <iostream>

TEST(TestReadXML, TestCircle) {
    std::string s = R"(<?xml version = "1.0"?>
<Circle label="testCircle" x="0" y="1" r="2" color="Black"/>)";
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(s.c_str());
    EXPECT_NE(0, result);
    Circle c(doc.child("Circle"));
    EXPECT_EQ(c.getlabel(), "testCircle");
    EXPECT_EQ(c.getx(), 0);
    EXPECT_EQ(c.gety(), 1);
    EXPECT_EQ(c.getr(), 2);
    EXPECT_EQ(c.getcolor(), "Black");
}

TEST(TestReadXML, TestGroup1) {
    std::string s = R"(<?xml version = "1.0"?>
<Group label="testGroup1" x="0" y="1">
     <Circle label="testCircle" x="2" y="3" r="4" color="Black"/>
     <Group label="testGroup2" x="5" y="6"/>
</Group>)";
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(s.c_str());
    auto d = result.description();
    ASSERT_TRUE(result) << result.description();
    Group g(doc.child("Group"));
    EXPECT_EQ(g.getlabel(), "testGroup1");
    EXPECT_EQ(g.getx(), 0);
    EXPECT_EQ(g.gety(), 1);
    EXPECT_EQ(((Circle*) g.getmember(0).get())->getcolor(), "Black");
}

TEST(TestAbsoluteCoord, Test1) {
    auto G1 = std::make_unique<Group>("G1", 0, 1);
    auto G2 = std::make_unique<Group>("G2", 2, 3);
    auto C21 = std::make_unique<Circle>("C21", 4, 5, 1, "Black");
    auto C22 = std::make_unique<Circle>("C22", 7, 8, 1, "Black");
    G2->add(move(C21));
    G2->add(move(C22));
    G1->add(move(G2));
    absoluteCoord abs = absoluteCoord();
    G1->computeAbsolute(abs);
    EXPECT_EQ(abs.members[0]->members[0]->x, 6);
    EXPECT_EQ(abs.members[0]->members[0]->y, 9);
    EXPECT_EQ(abs.members[0]->members[1]->x, 9);
    EXPECT_EQ(abs.members[0]->members[1]->y, 12);
}