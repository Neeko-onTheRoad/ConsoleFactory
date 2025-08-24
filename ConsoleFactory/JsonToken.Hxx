#pragma once

#include <memory>
#include <xstring>

namespace ConsoleFactory::JsonManagement {

	class JsonToken {

	public:
		virtual ~JsonToken() = 0;

	public:
		static std::unique_ptr<JsonToken> Parse(std::u32string token);
		static bool TryParse(std::u32string token, std::unique_ptr<JsonToken>& out);

	};

}