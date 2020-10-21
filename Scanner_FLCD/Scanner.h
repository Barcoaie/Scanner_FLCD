#pragma once
#include "HashTable.h"
#include "PIF.h"
#include <fstream>
class Scanner
{
private:
	HashTable * ht;
	PIF * pif;
public:
	Scanner();
	void scan(std::string file);
	void readLine(std::string line);
	~Scanner();
};

