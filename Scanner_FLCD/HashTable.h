#pragma once
#include<vector>
#include<string>

struct node {
	std::string data;
	struct node * next;
};

class HashTable
{
private:
	node *table[31];
public:
	HashTable();

	/*
	Pre: string must be valid
	Post: 
	Input: string
	Output: integer
	What it does: inserts an item inside the hash table and return the hash value that the string key was hashed
				  if a similar string is present, it returns just the value it is associated to
	*/
	int insertItem(std::string key);

	/*
	Pre: string must be valid
	Post: 
	Input: string
	Output: integer
	What it does: return the value linked to the searched key
	*/
	int searchItem(std::string key);

	/*
	Pre: string must be valid
	Post:
	Input: string
	Output: integer
	What it does: hashes the value of the input to an integer between 0 and 31 
	*/
	int hash_funct(std::string key);

	/*
	Pre:
	Post:
	Input:
	Output: string
	What it does: the HashTable is made readable to the console
	*/
	std::string prettyPrint();
	~HashTable();
};

