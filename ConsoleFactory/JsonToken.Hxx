#pragma once

#include <memory>
#include <xstring>
#include <stdexcept>

namespace ConsoleFactory::JsonManagement {

	class JsonToken {

	public:
		virtual ~JsonToken() = 0;

	public:
		static std::unique_ptr<JsonToken> Parse(const std::u32string& token);
		static bool TryParse(const std::u32string& token, std::unique_ptr<JsonToken>& out);

	};

}