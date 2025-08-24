#include "JsonNumber.Hxx"

namespace ConsoleFactory::JsonManagement {

	JsonNumber::JsonNumber(int64_t number) :
		_number(number) {}

	JsonNumber::JsonNumber(double number) :
		_number(number) {}

	JsonNumber::~JsonNumber() {}

	std::unique_ptr<JsonNumber> JsonNumber::Parse(const std::u32string& string) {

		bool isNegative = false;
		std::u32string_view view(string);

		// Check minus sign
		if (view.starts_with(U'-')) {
			isNegative = true;
			view.remove_prefix(1);
		}

		// Throw if empty or "-"
		if (view.length() == 0)
			throw std::invalid_argument("Invalid number format.");
		
		NumberType number;

		if (view.contains(U'e') || view.contains(U'E'))
			number = ParseExponent(view);

		else if (view.contains(U'.'))
			number = ParseRealNumber(view);

		else
			number = ParseInteger(view);

	}

	JsonNumber::NumberType&& JsonNumber::ParseExponent(const std::u32string_view& view) {

		int splitIndex = view.find(U'e');

		if (splitIndex == std::u32string_view::npos)
			splitIndex = view.find(U'E');

		if (splitIndex == std::u32string_view::npos)
			throw std::invalid_argument("Invalid number format.");

		auto exponentView = view.substr(splitIndex + 1);
		auto coefficientView = view.substr(0, splitIndex);

	}

	JsonNumber::NumberType&& JsonNumber::ParseRealNumber(const std::u32string_view& view) {

	}

	JsonNumber::NumberType&& JsonNumber::ParseInteger(const std::u32string_view& view) {

	}

	bool JsonNumber::TryParse(const std::u32string& string, std::unique_ptr<JsonNumber>& out) {

		try {
			out = Parse(string);
			return true;
		}
		catch (std::exception) {
			return false;
		}
		
	}

}