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
const char EQUAL = '=';
const char BANG = '!';
const char LESSER = '<';
const char GREATER = '>';


int main(int argc, char* argv[]) {
	int lineNumber = 1;
	bool hasError = false;
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

		for (int index = 0; index < fileContents.size(); index++) {
			char individualCharacters = fileContents[index];
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
				if (index < fileContents.size() && fileContents[index + 1] == '/') {
					while (index < fileContents.size() && fileContents[index] != '\n') {
						index++;
					}
					lineNumber++;
				}
				else
				{
					std::cout << "SLASH / null" << std::endl;
				}
			case EQUAL:
				if (index + 1 < fileContents.size() && fileContents[index + 1] == '=') {
					std::cout << "EQUAL_EQUAL == null" << std::endl;
					index++;
				}
				else
				{
					std::cout << "EQUAL = null" << std::endl;
				}
			case BANG:
				if (index + 1 < fileContents.size() && fileContents[index + 1] == '=') {
					std::cout << "BANG_EQUAL != null" << std::endl;
					index++;
				} 
				else 
				{
					std::cout << "BANG ! null" << std::endl;
				}
			case LESSER:
				if (index + 1 < fileContents.size() && fileContents[index + 1] == '=') {
					std::cout << "LESS_EQUAL <= null" << std::endl;
					index++;
				}
				else
				{
					std::cout << "LESS < null" << std::endl;
				}
			case GREATER:
				if (index + 1 < fileContents.size() && fileContents[index + 1] == '=') {
					std::cout << "GREATER_EQUAL >= null" << std::endl;
					index++;
				}
				else
				{
					std::cout << "GREATER > null" << std::endl;
				}
			case ' ':
			case '\t':
			default:
				std::cerr << "[line " << lineNumber << "] Error: Unexpected character : " << individualCharacters << std::endl;
				hasError = true;
			}
			
		}

		std::cout << "EOF  null" << std::endl;

		if (hasError) {
			std::exit(65);
		}
				

	} catch(const std::exception& readException) {
		std::cerr << "Error reading file: " << readException.what() << std::endl;
		std::exit(1);
	}

	return 0;
}