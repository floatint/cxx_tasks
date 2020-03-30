#ifndef USER_DEQUE_HPP
#define	USER_DEQUE_HPP

const int REALLOC_FACTOR = 2;
const size_t INITIAL_CAPACITY = 1;

template<typename T>
class UserDeque {
public:
	UserDeque() {
		m_capacity = INITIAL_CAPACITY;
		m_data = new T[m_capacity];
		m_originalDataPtr = m_data;
		m_size = 0;
	}
	//Вставка в конец
	void push_back(const T& val) {
		if (m_size == m_capacity)
			data_realloc();
		m_data[m_size++] = val;
	}

	void push_front(const T& val) {
		if (m_size == m_capacity)
			data_realloc();
		right_shift();
		m_data[0] = val;
		m_size++;
	}

	T pop_back() {
		if (m_size == 0)
			throw std::exception("Deque is empty");
		else {
			T tmp = m_data[m_size - 1];
			--m_size;
			return tmp;
		}
	}

	
	T pop_front() {
		if (m_size == 0)
			throw std::exception("Deque is empty");
		else {
			T tmp = m_data[0];
			left_shift();
			--m_size;
			return tmp;
		}
	}

	//Get deque size
	size_t size() const {
		return m_size;
	}

	//Get raw array
	const T* const_data() const {
		return m_data;
	}

private:
	//currrent data pointer
	T *m_data;
	//original data pointer(without shifts)
	T *m_originalDataPtr;
	//current size
	size_t m_size;
	size_t m_capacity;


	//Left shift by 1 elem
	void left_shift() {
		++m_data; //Just shift the beginning of the block to the right by 1 elem
	}

	//Right shift by 1 elem
	void right_shift() {
		for (int i = m_size; i > 0; i--) {
			m_data[i] = m_data[i - 1];
		}
	}

	//Memory reallocation
	void data_realloc() {
		//inc capacity
		m_capacity *= REALLOC_FACTOR;
		//alloc new block
		T* tmp = new T[m_capacity];
		//copy
		std::copy_n(m_data, m_size, tmp);
		m_data = tmp;
		//clean
		delete[] m_originalDataPtr;
		
		m_originalDataPtr = m_data;
	}
};

#endif // ! USER_DEQUE_HPP
