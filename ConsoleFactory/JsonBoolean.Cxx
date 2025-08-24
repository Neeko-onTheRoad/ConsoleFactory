#include "JsonBoolean.Hxx" 

namespace ConsoleFactory::JsonManagement {

	JsonBoolean::JsonBoolean(bool boolean) :
		_boolean(boolean) {}

	JsonBoolean::~JsonBoolean() {}

	std::unique_ptr<JsonBoolean> JsonBoolean::Parse(std::u32string string) {
		
		if (string == U"true") 
			return std::make_unique<JsonBoolean>(true);

		if (string == U"false")
			return std::make_unique<JsonBoolean>(false);

		throw new std::invalid_argument(
			"The boolean value must be 'true' or 'false'."
		);

	}

	bool JsonBoolean::TryParse(std::u32string string, std::unique_ptr<JsonBoolean>& out) {

		try {
			out = Parse(string);
			return true;
		}
		catch (std::exception) {
			return false;
		}

	}

}