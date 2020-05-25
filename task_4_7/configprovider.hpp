#ifndef CONFIGPROVIDER_HPP
#define CONFIGPROVIDER_HPP

#include "qt.hpp"
#include "stl.hpp"

/*
	
	Config file provider. Reads file and parses file pathes.

*/
class ConfigProvider {
public:
	static std::vector<QFileInfo> read(const QFileInfo& configFile);
};

#endif