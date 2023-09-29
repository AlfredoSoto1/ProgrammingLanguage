//#include <iostream>
//
//#include "Token.hpp"
//#include "Lexer.hpp"
//
//int main() {
//
//	using namespace PL;
//
//	std::string code = "int number = 0;";
//
//	std::vector<Token> tokens = {
//		{"ID", "[a-zA-Z][a-zA-Z0-9]*"},
//		{"INT_NUMBER", "-?[1-9][0-9]*"},
//		{"SEMICOLON", ";"}
//	};
//
//	std::vector<Token> keywords = {
//		{"INT_TYPE", "int"}
//	};
//
//	std::vector<Token> operators = {
//		{"EQUALS", "="}
//	};
//
//	Lexer lexer = Lexer(tokens, keywords, operators, code);
//
//	std::cout << "Print world" << std::endl;
//}

#include <iostream>
#include <regex>
#include <string>
#include <vector>

// Define a token structure to represent tokens.
struct Token {
    std::string type;
    std::string value;
};

int main() {
    // Input string containing text to be tokenized.
    std::string input = "x = 42; y = 3.14; z = 12345;";

    // Define a regular expression pattern to match variable names and numbers.
    std::regex tokenRegex("([a-zA-Z][a-zA-Z0-9]*)|(\\d+(\\.\\d+)?)");

    // Use std::sregex_iterator to tokenize the input string.
    std::sregex_iterator tokenIterator(input.begin(), input.end(), tokenRegex);
    std::sregex_iterator endIterator;  // End iterator

    // Vector to store tokens.
    std::vector<Token> tokens;

    while (tokenIterator != endIterator) {
        Token token;
        if ((*tokenIterator)[1].matched) {
            token.type = "VAR";
            token.value = (*tokenIterator)[1].str();
        }
        else if ((*tokenIterator)[2].matched) {
            token.type = "NUM";
            token.value = (*tokenIterator)[2].str();
        }
        tokens.push_back(token);

        ++tokenIterator;
    }

    // Print the tokens.
    for (const Token& token : tokens) {
        std::cout << "Type: " << token.type << ", Value: " << token.value << std::endl;
    }

    return 0;
}

