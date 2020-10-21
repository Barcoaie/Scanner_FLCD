#pragma once
#include<vector>

struct node {
	std::string data;
	struct node * next;
};

class HashTable
{
private:
	node *table[31];
public:
	/**
	* constructor function of the Hash Table
	*/
	HashTable();
	/**
	* inserts an item in the hash table
	* @param key a string, that is hashed and put in the table afterwards
	*/
	int insertItem(std::string key);
	/**
	* the hash function
	* @param key the string that is hashed
	*/
	int hash_funct(std::string key);
	/**
	* destructor function
	*/
	~HashTable();
};

