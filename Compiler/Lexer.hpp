#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Token.hpp"

namespace PL {

	class Lexer {
	public:
		/*
		* 
		*/
	public:
		/*
		* 
		*/
		explicit Lexer(
			const std::vector<Token> tokens,
			const std::vector<Token> keywords,
			const std::vector<Token> operators,
			const std::string& input) noexcept;
		
		~Lexer();

		void tokenize();

	private:
		/*
		* Skips any whitespace inside the input source code
		*/
		void skipWhiteSpace();

	private:
		std::string input;
		size_t linePosition;

		std::vector<Token> tokens;
		std::vector<Token> keywords;
		std::vector<Token> operators;
	};
}