// Scanner_FLCD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PIF.h"
#include "HashTable.h"
#include "Scanner.h"
#include <fstream>
void testPIF();
void testST();

int main()
{
	Scanner * scanner = new Scanner();
	//testPIF();
	//testST();

	std::map<std::string, int> tokens = scanner->generate_tokens("token.in");

	//for (auto& n : tokens) {
	//	std::cout << n.first<<" " ;
	//}

	std::ofstream fout("ST.out");
	std::ofstream gout("PIF.out");

	bool trial1 = scanner->scan("p1.txt", tokens);

	if (trial1) {
		std::cout << "\n\n\n";
		std::cout << "---------------Symbol Table\n";
		std::cout << scanner->getHT().prettyPrint() << "\n";
		fout << "Symbol Table using a hash function\n";
		fout << scanner->getHT().prettyPrint() << "\n";
		std::cout << "---------------PIF\n";
		gout << "PIF" << "\n";
		gout << scanner->getPIF().prettyPrint() << "\n";
		std::cout << scanner->getPIF().prettyPrint() << "\n";
	}
	else {
		std::cout << "\n\n\n";
		std::cout << "lexical error";
	}
	return 0;
}

void testPIF() {
	PIF * pif = new PIF();
	pif->genPIF("\"adssad\"", 3);
	pif->genPIF("int", 0);
	pif->genPIF("char", 0);
	std::cout << pif->prettyPrint();
}

void testST() {
	HashTable * ht = new HashTable();
	ht->insertItem("a");
	std::cout << ht->insertItem("a") << "\n";
	std::cout << ht->insertItem("a") << "\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
