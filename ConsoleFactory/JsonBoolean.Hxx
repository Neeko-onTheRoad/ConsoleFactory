#pragma once

#include <stdexcept>

#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	class JsonBoolean : public JsonToken {

	private:
		bool _boolean;

	public:
		JsonBoolean(bool boolean);
		~JsonBoolean() override;

	public:
		static std::unique_ptr<JsonBoolean> Parse(std::u32string string);
		static bool TryParse(std::u32string string, std::unique_ptr<JsonBoolean>& out);

	};

}