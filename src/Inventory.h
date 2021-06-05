#pragma once
#include <vector>

enum Item { Iron = 0, Salt = 1, Coal = 2 };

class Inventory {
private:
	std::vector<double> content;
public:
	int getQuant(int item);
	void add(int item, double quant);
};