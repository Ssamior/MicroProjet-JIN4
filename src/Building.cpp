#include "Building.h"

int Building::getX() {
	return x;
}
void Building::setX(int x) {
	this->x = x;
}
int Building::getY() {
	return y;
}
void Building::setY(int y) {
	this->y = y;
}
int Building::getLevel() {
	return level;
}
void Building::setLevel(int l) {
	this->level = level;
}

void Building::display() {
	//image.display(x, y);
}

//� ajouter quand Sprite est impl�ment�
// 
//Sprite Building::getImage() {
//	return level;
//}
//void Building::setImage(Sprite s) {
//	this->image = s;
//}