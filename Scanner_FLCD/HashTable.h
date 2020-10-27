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
	HashTable();
	int insertItem(std::string key);
	int searchItem(std::string key);
	int hash_funct(std::string key);
	~HashTable();
};

