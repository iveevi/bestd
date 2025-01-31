#pragma once

#include <tuple>
#include <cstdlib>

namespace bestd {

template <typename ... Args>
struct tuple : std::tuple <Args...> {
	using std::tuple <Args...> ::tuple;

	template <size_t I>
	auto &get () {
		return std::get <I> (*this);
	}
	
	template <size_t I>
	const auto &get () const {
		return std::get <I> (*this);
	}
};

}