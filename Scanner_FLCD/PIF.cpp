#include "PIF.h"

PIF::PIF()
{
	this->pairs = new std::vector<std::tuple<std::string, int>>();
	this->pairs->clear();
}

void PIF::genPIF(std::string token, int index)
{
	std::tuple<std::string, int> tpl = std::make_tuple(token, index);
	//tbf
	this->pairs->push_back(tpl);
}

std::string PIF::prettyPrint()
{
	std::string res = " ";
	for (std::vector<std::tuple<std::string, int>>::iterator it = this->pairs->begin(); it != this->pairs->end(); ++it) {
		res = res + std::get<0>(*it) + " " + std::to_string(std::get<1>(*it)) + "\n";
	}
	return res;
}

PIF::~PIF()
{
}
