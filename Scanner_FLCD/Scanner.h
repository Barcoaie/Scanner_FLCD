#pragma once
#include "HashTable.h"
#include "PIF.h"
#include <fstream>
#include <map>
#include <iostream>
class Scanner
{
private:
	HashTable * ht;
	PIF * pif;
public:
	Scanner();
	std::map<std::string, int> generate_tokens(std::string file);
	bool scan(std::string file, std::map<std::string, int> tokens);
	bool Separator(char c);
	bool Identifier(std::string token);
	bool Constant(std::string token);
	bool Operator(char c);
	HashTable getHT();
	PIF getPIF();
	~Scanner();
};

