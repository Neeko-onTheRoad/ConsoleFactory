#pragma once

#include "JsonToken.Hxx"

namespace ConsoleFactory::JsonManagement {

	class JsonNull : public JsonToken {

	public:
		JsonNull();
		~JsonNull() override;

	};

}