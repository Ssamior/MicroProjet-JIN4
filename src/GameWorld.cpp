#include <iostream>
#include "GameWorld.h"



GameWorld::GameWorld(char* const& xmlfile, bool fileMode)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Close | sf::Style::Titlebar);
    
    this->load(xmlfile, fileMode);
    //Background texture
    if (!backgroundTexture.loadFromFile(backgroundStr, sf::IntRect(0, 0, 1600, 900))) { return; }
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);
}


void GameWorld::load(char* const& string, bool fileMode) {
    //Load the map
    pugi::xml_document doc;
    pugi::xml_parse_result result;
    //Load from a file ...
    if (fileMode) {
        result = doc.load_file(string);
    }
    //.. or load from a string
    else {
        result = doc.load_string(string);
        std::cout << string;
    }

    if (!result) {
        //Error
        std::cout << "Error while loading GameWorld map... \n";
        return;
    }

    //Loading each object
    buildings.clear();
    for (auto child : doc.children()) {
        std::string name = child.name();
        if (name.compare("Inventory") == 0) {
            //Fill inventory
            int i = 0;
            for (auto ite = child.attributes().begin(); ite != child.attributes().end(); ite++) {
                inventory.add(i, ite->as_int());
                i++;
            }
        }
        else if (name.compare("IronMine") == 0) {
            //Create Mine according to parameters
            auto mine = std::make_shared<Mine>(
                ironMineStr,
                Item::Iron,
                child.attribute("rate").as_double(),
                child.attribute("rate").as_double() * 2,
                child.attribute("x").as_int(),
                child.attribute("y").as_int(),
                child.attribute("level").as_int()
                );
            buildings.push_back(mine);
        }

        else if (name.compare("CoalMine") == 0) {
            //Create Mine according to parameters
            auto mine = std::make_shared<Mine>(
                coalMineStr,
                Item::Coal,
                child.attribute("rate").as_double(),
                child.attribute("rate").as_double() * 1.5,
                child.attribute("x").as_int(),
                child.attribute("y").as_int(),
                child.attribute("level").as_int()
                );
            buildings.push_back(mine);
        }

        else if (name.compare("StoneMine") == 0) {
            //Create Mine according to parameters
            auto mine = std::make_shared<Mine>(
                stoneMineStr,
                Item::Stone,
                child.attribute("rate").as_double(),
                child.attribute("rate").as_double(),
                child.attribute("x").as_int(),
                child.attribute("y").as_int(),
                child.attribute("level").as_int()
                );
            buildings.push_back(mine);
        }

        else if (name.compare("WoodMine") == 0) {
            //Create Mine according to parameters
            auto mine = std::make_shared<Mine>(
                woodMineStr,
                Item::Wood,
                child.attribute("rate").as_double(),
                0,
                child.attribute("x").as_int(),
                child.attribute("y").as_int(),
                child.attribute("level").as_int()
                );
            buildings.push_back(mine);
        }

        else if (name.compare("Tree") == 0) {
            //Create Tree
            char* textureTreeStr = "";
            if (child.attribute("type").as_int() == 0) {
                textureTreeStr = tree0Str;
            }
            else {
                textureTreeStr = tree1Str;
            }
            auto tree = std::make_shared<Consumer>(
                textureTreeStr,
                Item::Pollution,
                0.2,
                child.attribute("x").as_int(),
                child.attribute("y").as_int()
                );
            buildings.push_back(tree);
        }
    }

    //Load the UI with buttons
    //supprButton
    auto it = std::find_if(UI.begin(), UI.end(), [&supprButtonName = "supprButton"](UIElement const& obj){return obj.name == supprButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(supprButtonStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 0);
    }
    //furnaceButton
    it = std::find_if(UI.begin(), UI.end(), [&furnaceButtonName = "furnaceButton"](UIElement const& obj){return obj.name == furnaceButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(furnaceStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 50);
    }
    //ironMineButton
    it = std::find_if(UI.begin(), UI.end(), [&ironMineButtonName = "ironMineButton"](UIElement const& obj){return obj.name == ironMineButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(ironMineStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 100);
    }
    //coalMineButton
    it = std::find_if(UI.begin(), UI.end(), [&coalMineButtonName = "coalMineButton"](UIElement const& obj){return obj.name == coalMineButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(coalMineStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 150);
    }
    //stoneMineButton
    it = std::find_if(UI.begin(), UI.end(), [&stoneMineButtonName = "stoneMineButton"](UIElement const& obj){return obj.name == stoneMineButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(stoneMineStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 200);
    }
    //woodMineButton
    it = std::find_if(UI.begin(), UI.end(), [&woodMineButtonName = "woodMineButton"](UIElement const& obj){return obj.name == woodMineButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(woodMineStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 250);
    }
    //recyclingUnitButton
    it = std::find_if(UI.begin(), UI.end(), [&recyclingUnitButtonName = "recyclingUnitButton"](UIElement const& obj){return obj.name == recyclingUnitButtonName; });
    if (it != UI.end()) {
        //Loading texture and applying it to sprite
        if (!it->texture.loadFromFile(recyclingUnitStr)) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 300);
    }
}

Inventory GameWorld::getInventory() const {
    return this->inventory;
}

bool GameWorld::processEvents() {
    //If the game ended
    if (isLost || isWon) {
        return true;
    }

    window->pollEvent(event);
    //Check the type of the event
    switch (event.type)
    {
        //Window closed
    case sf::Event::Closed:
        window->close();
        return true;
        break;

    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            int x = event.mouseButton.x - event.mouseButton.x % 50;
            int y = event.mouseButton.y - event.mouseButton.y % 50;
            //Do not call handleClick() for clicks on UI
            if (!showUI || x<1550) { handleClick(x, y); }
            

            //Checking if we are clicking on UI
            for (int i = 0; i < UI.size(); i++) {
                //If we desactivate the button
                if (UI[i].isActive && UI[i].sprite.getGlobalBounds().contains((float)x, (float)y)) {
                    isGlobalUIActive = false;
                    UI[i].isActive = !UI[i].isActive;
                    UI[i].sprite.setColor(sf::Color(255, 255, 255, 50));
                }
                //If no other UI elements are in use and we click on the button
                else if (!isGlobalUIActive && UI[i].sprite.getGlobalBounds().contains((float)x, (float)y)) {
                    isGlobalUIActive = true;
                    UI[i].isActive = !UI[i].isActive;
                    UI[i].sprite.setColor(sf::Color::White);
                }
            }
        }
        //Pause the input processing, else one mouse press activates the button too much times
        _sleep(250);
        break;
        //Key pressed
    case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            window->close();
            return true;
            break;
        case sf::Keyboard::I:
            showInventory = !showInventory;
            break;
        case sf::Keyboard::U:
            showUI = !showUI;
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
    return false;
}

void GameWorld::handleClick(int x, int y) {
    //x and y are scaled so that X and Y correspond to tile coordinates rather than absolute coordinates
    //Supress mode
    if (UI[0].isActive) {
        auto it = std::find_if(buildings.begin(), buildings.end(), [X = x/50, Y = y/50](std::shared_ptr<InterfaceBuilding>& obj) { return (obj->getX() == X && obj->getY() == Y); });

        if (it != buildings.end()) {
            auto retval = std::move(*it);
            buildings.erase(it);
            auto finalval = std::move(retval);
        }
    }
    //Ingot furnace creation
    if (UI[1].isActive && inventory.getQuant(Item::Stone) >= 200 && inventory.getQuant(Item::Coal) >= 100) {
        //use 200 Stone and 100 Coal
        inventory.add(Item::Stone, -200);
        inventory.add(Item::Coal, -100);
        //Mine shared_ptr for Ingot production
        auto mine = std::make_shared<Mine>(furnaceStr, Item::Ingot, 1, 3, x / 50, y / 50, 1);
        //Consumer decorator for iron consumption
        auto cons = std::make_shared<Consumer>(Item::Iron, 3, mine);
        //Consumer decorator for coal consumption
        auto cons2 = std::make_shared<Consumer>(Item::Coal, 3, cons);
        buildings.push_back(cons2);
    }
    //Iron mine creation
    if (UI[2].isActive && inventory.getQuant(Item::Stone) >= 100 && inventory.getQuant(Item::Coal) >= 100) {
        //use 100 Stone and 100 Coal
        inventory.add(Item::Stone, -100);
        inventory.add(Item::Coal, -100);
        //Mine shared_ptr
        auto mine = std::make_shared<Mine>(ironMineStr, Item::Iron, 1, 2, x/50, y/50, 1);
        buildings.push_back(mine);
    }
    //Coal mine creation
    if (UI[3].isActive && inventory.getQuant(Item::Stone) >= 100 && inventory.getQuant(Item::Wood) >= 100) {
        //use 100 Stone and 100 Wood
        inventory.add(Item::Stone, -100);
        inventory.add(Item::Wood, -100);
        //Mine shared_ptr
        auto mine = std::make_shared<Mine>(coalMineStr, Item::Coal, 2, 3, x / 50, y / 50, 1);
        buildings.push_back(mine);
    }
    //Stone mine creation
    if (UI[4].isActive && inventory.getQuant(Item::Wood) >= 100) {
        //use 100 Wood
        inventory.add(Item::Wood, -100);
        //Mine shared_ptr
        auto mine = std::make_shared<Mine>(stoneMineStr, Item::Stone, 2, 2, x / 50, y / 50, 1);
        buildings.push_back(mine);
    }
    //Wood mine creation
    if (UI[5].isActive && inventory.getQuant(Item::Wood) >= 50) {
        //use 50 Wood
        inventory.add(Item::Wood, -50);
        //Mine shared_ptr
        auto mine = std::make_shared<Mine>(woodMineStr, Item::Wood, 1, 0, x / 50, y / 50, 1);
        buildings.push_back(mine);
    }
    //Recycling unit creation
    if (UI[6].isActive && inventory.getQuant(Item::Ingot) >= 10 && inventory.getQuant(Item::Wood) >= 100) {
        //use 10 Ingot and 100 Wood
        inventory.add(Item::Ingot, -10);
        inventory.add(Item::Wood, -100);
        //Mine shared_ptr for Ingot production
        auto cons = std::make_shared<Consumer>(recyclingUnitStr, Item::Pollution, 0.5, x / 50, y / 50, 1);
        //Consumer decorator for wood consumption
        auto cons2 = std::make_shared<Consumer>(Item::Wood, 3, cons);
        buildings.push_back(cons2);
    }
}

void  GameWorld::update(sf::Time timeElapsed) {
    //Updating inventories of each building
    for (int i = 0; i < buildings.size(); i++) {
        buildings[i]->update(timeElapsed, &inventory);
    }
    //Checking if we lost the game due to pollution
    if (inventory.getQuant(Item::Pollution) > POLLUTION_MAX) {
        isLost = true;
    }
    //checking if we win the game
    if (inventory.getQuant(Item::Ingot) > INGOT_MIN) {
        isWon = true;
    }
}

void GameWorld::render() const {
    //Setup
    window->clear();
    window->draw(background);
    
    //Buildings rendering
    for (int i = 0; i < buildings.size(); i++) {
        buildings[i]->render(*window);
    }
    //Inventory rendering
    if (showInventory) {
        inventory.render(*window);
    }
    //UI rendering
    if (showUI) {
        for (int i = 0; i < UI.size(); i++) {
            window->draw(UI[i].sprite);
        }
    }
    //If we lost the game
    if (isLost) {
        window->clear(sf::Color::Black);
        sf::Texture loosingScreenTexture;
        sf::Sprite loosingScreenSprite;
        //Sprite
        if (!loosingScreenTexture.loadFromFile(loosingScreenStr, sf::IntRect(0, 0, 1600, 900))) { return; }
        loosingScreenTexture.setSmooth(true);
        loosingScreenSprite.setTexture(loosingScreenTexture);
        //Text
        sf::Text losingText;
        sf::Font font;
        font = inventory.getFont();
        losingText.setFont(font);
        losingText.setString("Science sans conscience n'est que ruine de l'âme. (Rabelais)");
        losingText.setFillColor(sf::Color::Red);
        losingText.setCharacterSize(40);
        losingText.setPosition((WIDTH - losingText.getGlobalBounds().width) /2, (HEIGHT - losingText.getGlobalBounds().height) /2);
        window->draw(loosingScreenSprite);
        window->draw(losingText);
        window->display();
        _sleep(3500);
    }
    //If we won the game
    if (isWon) {
        window->clear(sf::Color::Black);
        sf::Texture winningScreenTexture;
        sf::Sprite winningScreenSprite;
        //Sprite
        if (!winningScreenTexture.loadFromFile(winningScreenStr, sf::IntRect(0, 0, 1600, 900))) { return; }
        winningScreenTexture.setSmooth(true);
        winningScreenSprite.setTexture(winningScreenTexture);
        //Text
        sf::Text winningText;
        sf::Font font;
        font = inventory.getFont();
        winningText.setFont(font);
        winningText.setString("You won !");
        winningText.setFillColor(sf::Color::White);
        winningText.setCharacterSize(50);
        winningText.setPosition((WIDTH - winningText.getGlobalBounds().width) / 2, 200);
        window->draw(winningScreenSprite);
        window->draw(winningText);
        window->display();
        _sleep(3500);
    }
    window->display();
}
