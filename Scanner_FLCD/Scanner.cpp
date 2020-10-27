#include "Scanner.h"

Scanner::Scanner()
{
	this->ht = new HashTable();
	this->pif = new PIF();
}

std::map<std::string, int> Scanner::generate_tokens(std::string file)
{
	std::map<std::string, int> tokens;
	std::ifstream infile(file);
	int value;
	std::string token;
	while (infile >> value >> token) {
		if (token.compare("<space>") == 0) {
			token = " ";
		}
		tokens[token] = value;
	}
	return tokens;
}

bool Scanner::scan(std::string file, std::map<std::string, int> tokens)
{
	bool res = true;
	std::ifstream infile(file);
	std::string line;
	bool in_string = false;
	int line_count = 0;
	while (std::getline(infile, line)) {
		std::cout << line << std::endl;
		line_count++;
		std::string current_string = "";
		for (char& c : line) {
			if ((c == '\"' || c == '\'') && in_string) {
				in_string = false;
				current_string += c;
				continue;
			}
			if ((c == '\"' || c == '\'') && !in_string)
				in_string = true;

			if (in_string) current_string += c;
			else {
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
					|| (c >= '0' && c <= '9') || c == '_')
					current_string += c;
				if (c == ' ' || Separator(c) || Operator(c)) {
					if (Separator(c) || Operator(c))
						pif->genPIF(std::string(1, c), tokens[std::string(1, c)]);
					if (tokens.count(current_string))
						pif->genPIF(current_string, tokens[current_string]);
					else {
						if (!current_string.empty()) {
							if (Constant(current_string) || Identifier(current_string)) {
								int value = ht->searchItem(current_string);
								if (value == -1) value = ht->insertItem(current_string);
								if (Constant(current_string))
									pif->genPIF("CONST", value);
								if (Identifier(current_string))
									pif->genPIF("IDENTIFIER", value);
							}
							else {
								std::cout << "Erorr on line " << line_count << " : " << current_string << " is not defined" << std::endl;
								res = false;
							}
						}
					}
					current_string = "";
				}
			}
		}
		if (!current_string.empty()) {
			if (tokens.count(current_string))
				pif->genPIF(current_string, tokens[current_string]);
			else {
				if (Constant(current_string) || Identifier(current_string)) {
					int value = ht->searchItem(current_string);
					if (value == -1) value = ht->insertItem(current_string);
					if (Constant(current_string))
						pif->genPIF("CONST", value);
					if (Identifier(current_string))
						pif->genPIF("IDENTIFIER", value);
				}
				else {
					std::cout << "Erorr on line " << line_count << " : " << current_string << " is not defined" << std::endl;
					res = false;
				}
			}
		}
	}
	return res;
}

bool Scanner::Separator(char c)
{
	return (c == '[' || c == ']' || c == '(' || c == ')' || c == ';' || c == ',' || c == '{' || c == '}');
}

bool Scanner::Identifier(std::string token)
{
	bool digit = false;
	bool underscore = false;
	bool fletter = false;
	bool afterus = true;

	for (char& c : token) {
		if (c == '_') {
			if (!fletter) return false;
			if (underscore) return false;
			if (digit) return false;
			underscore = true;
		}
		else if (c >= '0' && c <= '9') {
			if (!fletter) return false;
			if (underscore && afterus) return false;
			digit = true;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (!fletter) fletter = true;
			if (underscore && afterus) afterus = false;
			if (digit) return false;
		}
		return false;
	}
	if (underscore && afterus) return false;
	return true;
}

bool Scanner::Constant(std::string token)
{
	if (token.compare("true") == 0 || token.compare("false") == 0) return true;
	
	if (token.compare("0") == 0) return true;

	char first_char = token.c_str()[0];

	if (first_char == 'n' && token.substr(0, 3).compare("not") != 0) return false;

	if (first_char == '\"') {
		char last_char = ' ';
		for (char& c : token.substr(1)) {
			if (last_char == '\"') return false;
			if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' &&c != '\"') return false;
			last_char = c;
		}
		if (last_char != '\"') return false;
		return true;
	}

	if (first_char == '\'') {
		if (token.length() != 3) return false;
		if (token.c_str()[2] != '\'') return false;
		if ((token.c_str()[1] < '0' || token.c_str()[1] > '9') && (token.c_str()[1] < 'a' || token.c_str()[1] > 'z') && (token.c_str()[1] < 'A' || token.c_str()[1] > 'Z') && token.c_str()[1] != ' ')
			return false;
		return true;
	}

	if (token.substr(0, 3).compare("not") == 0) {
		if (token.substr(3).c_str()[0] == '0') return false;
		for (char& c : token.substr(3)) {
			if (c < '0' || c > '9') return false;
		}
		return true;
	}

	if (first_char >= '1' && first_char <= '9') {
		for (char& c : token.substr(1)) {
			if (c < '0' || c > '9') return false;
		}
		return true;
	}


	return true;
}

bool Scanner::Operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '%' || c == '<' || c == '<=' || c == '=='
		|| c == '<>' || c == 'not' || c == '!' || c == '!='
		|| c == '>=' || c == '>' || c == '||' || c == '&&' || c == ':=');
}

HashTable Scanner::getHT()
{
	return *this->ht;
}

PIF Scanner::getPIF()
{
	return *this->pif;
}

Scanner::~Scanner()
{
}
