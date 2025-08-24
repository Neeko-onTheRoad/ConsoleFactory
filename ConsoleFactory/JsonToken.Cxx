#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	std::unique_ptr<JsonToken> JsonToken::Parse(const std::u32string& token) {
		
		throw std::invalid_argument(
			"Wrong json format."
		);

	}

	bool JsonToken::TryParse(const std::u32string& token, std::unique_ptr<JsonToken>& out) {

		try {
			out = Parse(token);
			return true;
		}
		catch (std::exception) {
			return false;
		}

	}
	
}