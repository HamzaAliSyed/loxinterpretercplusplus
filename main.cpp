#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

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

		if (!fileContents.empty()) {
			throw std::runtime_error("Scanner not implemented");
		}
		else {
			std::cout << "EOF  null" << std::endl;
		}

	} catch(const std::exception& readException) {
		std::cerr << "Error reading file: " << readException.what() << std::endl;
		std::exit(1);
	}

	return 0;
}