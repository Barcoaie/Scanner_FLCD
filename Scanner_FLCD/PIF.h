#pragma once
#include<tuple>
#include<string>
#include<vector>
class PIF
{
private:
	std::vector<std::tuple<std::string, int>>* pairs;
public:
	PIF();
	void genPIF(std::string, int);
	std::string prettyPrint();
	~PIF();
};

