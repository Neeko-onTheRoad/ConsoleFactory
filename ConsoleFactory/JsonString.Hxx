#pragma once

#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	class JsonString : public JsonToken {

	private:
		std::u32string _string;

	public:
		JsonString(std::u32string string);
		~JsonString() override;

	};

}