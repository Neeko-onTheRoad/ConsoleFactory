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
		static std::unique_ptr<JsonBoolean> Parse(std::string);

	};

}