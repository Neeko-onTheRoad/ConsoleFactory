#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <variant>

#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	class JsonNumber : public JsonToken {

	private:
		using NumberType = typename std::variant<int64_t, double>;

	private:
		NumberType _number;
		
	public:
		JsonNumber(int64_t number);
		JsonNumber(double number);
		~JsonNumber() override;

	public:
		static std::unique_ptr<JsonNumber> Parse(const std::u32string& string);
		static bool TryParse(const std::u32string& string, std::unique_ptr<JsonNumber>& out);

	private:
		static NumberType&& ParseInteger(const std::u32string_view& view);
		static NumberType&& ParseRealNumber(const std::u32string_view& view);
		static NumberType&& ParseExponent(const std::u32string_view& view);

	};

}