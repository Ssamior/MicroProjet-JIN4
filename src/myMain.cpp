#include "myMain.h"
#include "Group.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <fstream>

int myMain()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("visage.xml");
    auto d = result.description();
    Group g(doc.child("Group"));
    int c = 0;
    int rank = 0;
    int numact = 0;

    while (true) {
        window.clear(sf::Color::White);
        g.print(std::cout, c, 0, 0, window);
        c = 0;
        window.display();
        std::cout << "Rank of object to modify ?\n";
        std::cin >> rank;
        std::cout << "\n";
        Shape* shape;
        Group* parent;
        g.reach(rank, c, shape, parent);
        c = 0;
        std::cout << "1 : Change color\n2 : Copy\n3 : Translation\n4 : Save\n";
        std::cin >> numact;
        std::cout << "\n";
        shape->action(numact, parent);
        rank = 0;
        numact = 0;
    }
    return 0;
}