#include "Lexer.hpp"
#include "Token.hpp"

namespace PL {

	Lexer::Lexer(
		const std::vector<Token> tokens,
		const std::vector<Token> keywords,
		const std::vector<Token> operators, const std::string& input) noexcept :
		input(input),
		linePosition(0)
	{

	}

	Lexer::~Lexer() {

	}
}