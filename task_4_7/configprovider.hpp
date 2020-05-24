#ifndef CONFIGPROVIDER_HPP
#define CONFIGPROVIDER_HPP

#include "qt.hpp"
#include "stl.hpp"

class ConfigProvider {
public:
	static std::vector<QFileInfo>* read(const QFileInfo& configFile);
};

#endif