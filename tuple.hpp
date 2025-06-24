#pragma once

#include <tuple>
#include <cstdlib>

namespace bestd {

template <typename ... Args>
struct tuple : std::tuple <Args...> {
	using standard = std::tuple <Args...>;
	using standard::tuple;

	template <size_t I>
	auto &get () {
		return std::get <I> (*this);
	}
	
	template <size_t I>
	const auto &get () const {
		return std::get <I> (*this);
	}
};

template <typename T>
struct is_tuple_base : std::false_type {};

template <typename ... Args>
struct is_tuple_base <tuple <Args...>> : std::true_type {};

template <typename T>
concept is_tuple = is_tuple_base <T> ::value;

} // namespace bestd