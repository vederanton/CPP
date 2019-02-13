#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class RingBuffer {
	std::vector<T> vec;
public:
	RingBuffer() {}

	RingBuffer(std::initializer_list<T> l) :
		vec(l)
	{}

	RingBuffer(const RingBuffer& myVec) {
		for (size_t i = 0; i < myVec.size(); ++i) {
			vec[i] = myVec.vec[i];
		}
	}

	RingBuffer(RingBuffer&& myVec) {
		for (size_t i = 0; i < myVec.size(); ++i) {
			vec[i] = myVec[i];
		}
		myVec.vec.clear();
		myVec.vec.shrink_to_fit();
	}

	virtual ~RingBuffer() {}

	void print() const {
		for (size_t i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}

	void push(const T elem) {
		if (vec.size() == vec.capacity()) {
			vec.erase(vec.begin());
			vec.push_back(elem);
		}
		else {
			vec.push_back(elem);
		}
	}

	void erase(const int index) {
		vec.erase(vec.begin() + index);
	}

	T at(const size_t index) const {
		if (index >= vec.size() || index < 0) {
			return 0;
		}
		return vec[index];
	}

	int size() const {
		return vec.size();
	}

	int capacity() const {
		return vec.capacity();
	}

	void resize(const size_t count) {
		if (count <= vec.size()) {
			return;
		}
		vec.shrink_to_fit();
		vec.reserve(count);
	}
};