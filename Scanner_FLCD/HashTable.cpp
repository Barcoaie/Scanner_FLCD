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
	return index;
}

int HashTable::searchItem(std::string key)
{
	int hash_value = hash_funct(key);
	node *current = table[hash_value];
	if (current == nullptr)
		return -1;
	while (current != nullptr) {
		if (current->data.compare(key) == 0) return hash_value;
		current = current->next;
	}
	return -1;
}

int HashTable::hash_funct(std::string key)
{
	int sum = 0;
	for (char& c : key) {
		sum += c;
	}
	return sum % 31;
}


std::string HashTable::prettyPrint()
{
	std::string res;
	for (int i = 0; i < 31; i++) {
		res = res + std::to_string(i) + ": ";
		node * curr = table[i];
		while (curr != nullptr) {
			res = res + curr->data;
			curr = curr->next;
		}
		res = res + "\n";
	}
	return res;
}

HashTable::~HashTable()
{
}
