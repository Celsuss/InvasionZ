/*
	Read lua files
*/

#pragma once
#include <string>
#include "lua.hpp"

class LuaConfig{
public:
	LuaConfig(const std::string name);
	~LuaConfig();
	int getInt(const std::string name);
	//int getInt(const int name);
	std::string getString(const std::string name);
	std::string getString(const std::string name, const int index);
private:
	lua_State* m_LuaState;
};