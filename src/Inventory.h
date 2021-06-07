#pragma once
#include <vector>

enum Item { Iron = 0, Salt = 1, Coal = 2, End = 3};

class Inventory {
private:
	std::vector<double> content = std::vector<double>(Item::End);
public:
	int getQuant(int item);
	void add(int item, double quant);
};