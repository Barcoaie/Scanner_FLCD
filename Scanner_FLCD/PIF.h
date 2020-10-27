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

	/*
	Pre: string and int must be valid
	Post: 
	Input: string
	       int
	Output: 
	What it does: inserts the given pair of string and integer into the vector of pairs
	*/
	void genPIF(std::string, int);

	/*
	Pre:
	Post:
	Input:
	Output: string
	What it does: the PIF is made readable to the console
	*/
	std::string prettyPrint();
	~PIF();
};

