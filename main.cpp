#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

const char LEFT_PARENTHESIS = '(';
const char RIGHT_PARENTHESIS = ')';
const char LEFT_BRACES = '{';
const char RIGHT_BRACES = '}';
const char DOT = '.';
const char COMMA = ',';
const char SEMICOLON = ';';
const char PLUS = '+';
const char MINUS = '-';
const char STAR = '*';
const char DIVIDE = '/';

int main(int argc, char* argv[]) {
	std::cerr << "Logs from Interperters will be displayed here" << std::endl;
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " tokenize " << std::endl;
		std::exit(1);
	}
	std::string command = argv[1];
	if (command != "tokenize") {
		std::cerr << "Unknown command: " << command << std::endl;
		std::exit(1);
	}

	std::string fileName = argv[2];
	std::string fileContents;

	try {
		std::ifstream file(fileName);
		if (!file) {
			throw std::runtime_error("Unable to open file");
		}

		std::stringstream buffer;
		buffer << file.rdbuf();
		fileContents = buffer.str();

		//Try it with reference later.
		//Use auto

		for (char individualCharacters : fileContents) {
			switch (individualCharacters) {
			case LEFT_PARENTHESIS:
				std::cout << "LEFT_PAREN ( null" << std::endl;
			case RIGHT_PARENTHESIS: 
				std::cout << "RIGHT_PAREN ) null" << std::endl;
			case LEFT_BRACES:
				std::cout << "LEFT_BRACE { null" << std::endl;
			case RIGHT_BRACES:
				std::cout << "RIGHT_BRACE } null" << std::endl;
			case DOT:
				std::cout << "DOT . null" << std::endl;
			case COMMA:
				std::cout << "COMMA , null" << std::endl;
			case SEMICOLON:
				std::cout << "SEMICOLON ; null" << std::endl;
			case PLUS:
				std::cout << "PLUS + null" << std::endl;
			case MINUS:
				std::cout << "MINUS - null" << std::endl;
			case STAR:
				std::cout << "STAR * null" << std::endl;
			case DIVIDE:
				std::cout << "DIVIDE / null" << std::endl;
			}
			
		}

		std::cout << "EOF  null" << std::endl;
				

	} catch(const std::exception& readException) {
		std::cerr << "Error reading file: " << readException.what() << std::endl;
		std::exit(1);
	}

	return 0;
}