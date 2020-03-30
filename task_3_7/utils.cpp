#include "task_3_7.hpp"

std::string to_lower(const std::string& str) {
	std::string result;
	std::for_each(str.cbegin(), str.cend(), [&result](char c) {
		result += std::tolower(c);
	});
	return result;
}