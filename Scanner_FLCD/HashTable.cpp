#include "HashTable.h"

HashTable::HashTable()
{
	for (int i = 0; i < 31; i++) {
		this->table[i] = nullptr;
	}
}

int HashTable::insertItem(std::string key)
{
	int index = this->hash_funct(key);
	node * nod = new node;
	nod->data = key;
	nod->next = nullptr;
	node * curr = this->table[index];
	if (curr == nullptr) {
		table[index] = nod;
	}
	else {
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = nod;
	}
	return index;
}

int HashTable::hash_funct(std::string key)
{
	int sum = 0;
	for (char& c : key) {
		sum += c;
	}
	return sum % 31;
}


HashTable::~HashTable()
{
}
