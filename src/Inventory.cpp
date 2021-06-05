#pragma once
#include "Inventory.h"

int Inventory::getQuant(int item) {
	return (int)round(content[item]);
}
void Inventory::add(int item, double quant) {
	content[item] += quant;
}

