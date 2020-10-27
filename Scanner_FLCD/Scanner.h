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

	/*
	Pre: string must be valid
		 file with the given string name must exist
	Post:
	Input: string
	Output: map<string, int>
	What it does: generates the set of reserved tokens and their associated values
	*/
	std::map<std::string, int> generate_tokens(std::string file);
	
	/*
	Pre: string must be valid
		 file with the given string name must exist
		 the map<string, int> must be valid
	Post:
	Input: string
		   map<string, int>
	Output: bool
	What it does: splits the content of the file in tokens and classifies them
				  if we have an error return false, else true
	*/
	bool scan(std::string file, std::map<std::string, int> tokens);
	
	/*
	Pre: char must be valid
	Post:
	Input: char
	Output: bool
	What it does: checks if the given character is a separator
	*/
	bool Separator(char c);
	
	/*
	Pre: string must be valid
	Post:
	Input: string
	Output: bool
	What it does: checks if the given string is an identifier
	*/
	bool Identifier(std::string token);
	
	/*
	Pre: string must be valid
	Post:
	Input: string
	Output: bool
	What it does: check if the given string is a constant
	*/
	bool Constant(std::string token);
	
	/*
	Pre: char must be valid
	Post:
	Input: char
	Output: bool
	What it does: checks if the given character is an operator
	*/
	bool Operator(char c);
	
	/*
	Pre: HashTable must be initialised
	Post:
	Input:
	Output: a HashTable object
	What it does: return the HashTable corresponding to the Scanner
	*/
	HashTable getHT();
	
	/*
	Pre: PIF must be initialised
	Post:
	Input:
	Output: a PIF object
	What it does: return the PIF corresponding to the Scanner
	*/
	PIF getPIF();

	~Scanner();
};

