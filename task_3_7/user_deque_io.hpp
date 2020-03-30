#ifndef USER_DEQUE_IO_HPP
#define USER_DEQUE_IO_HPP

#include "user_deque.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, const UserDeque<T>& deque) {
	size_t size = deque.size();
	auto data = deque.const_data();
	for (int i = 0; i < size; i++) {
		os << data[i];
		if (i < size - 1)
			os << ' ';
	}
	return os;
}

#endif