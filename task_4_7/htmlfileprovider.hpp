#ifndef HTMLFILEPROVIDER_HPP
#define HTMLFILEPROVIDER_HPP

#include "qt.hpp"
#include "stl.hpp"

class HTMLFileProvider {
public:
	static std::vector<std::tuple<int, int, QString>> read(const QFileInfo& file, QRegExp& pattern);
};

#endif