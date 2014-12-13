#include "LuaConfig.h"
#include <sstream>

#include <iostream>

static const int STACK_TOP = -1;
static const int STACK_BOTTOM = 1;

LuaConfig::LuaConfig(std::string name){
	std::string filename = "./Scripts/" + name + ".lua";
	m_LuaState = luaL_newstate();

	if (0 == m_LuaState){
		std::cout << "Could not create lua state." << std::endl;
	}

	luaL_openlibs(m_LuaState);

	luaL_dofile(m_LuaState, filename.c_str());
}

LuaConfig::~LuaConfig(){}

int LuaConfig::getInt(const std::string name){
	lua_getglobal(m_LuaState, name.c_str());

	if (!lua_isnumber(m_LuaState, STACK_TOP)){
		std::cout << name + " is not a valid int variable." << std::endl;
	}

	int x = int(lua_tonumber(m_LuaState, STACK_TOP));
	lua_pop(m_LuaState, 1);
	return x;
}

std::string LuaConfig::getString(const std::string name){
	lua_getglobal(m_LuaState, name.c_str());

	if (!lua_isstring(m_LuaState, STACK_TOP)){
		std::cout << name + " is not a valid string variable." << std::endl;
	}
	
	std::string x = std::string(lua_tostring(m_LuaState, STACK_TOP));
	lua_pop(m_LuaState, 1);
	return x;
}

std::string LuaConfig::getString(const std::string name, const int index){
	std::ostringstream convert;
	convert << index;
	std::string indexStr = convert.str();

	lua_getglobal(m_LuaState, name.c_str());
	lua_getfield(m_LuaState, STACK_TOP, indexStr.c_str());
	
	if (!lua_isstring(m_LuaState, STACK_TOP)){
		std::cout << name + " is not a valid strubg variable." << std::endl;
	}

	std::string x = std::string(lua_tostring(m_LuaState, STACK_TOP));
	lua_pop(m_LuaState, 1);
	return x;
}