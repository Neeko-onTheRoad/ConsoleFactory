#pragma once

#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	class JsonBoolean : public JsonToken {

	private:
		bool _boolean;

	public:
		JsonBoolean(bool boolean);
		~JsonBoolean() override;

	public:
		static std::unique_ptr<JsonBoolean> Parse(const std::u32string& string);
		static bool TryParse(const std::u32string& string, std::unique_ptr<JsonBoolean>& out);

	};

}