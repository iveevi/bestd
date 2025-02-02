#pragma once

#include <variant>

namespace bestd {

template <typename T, typename U, typename ... Args>
constexpr int variant_index(int i)
{
	if constexpr (std::same_as <T, U>)
		return i;

	if constexpr (sizeof...(Args))
		return variant_index <T, Args...> (i + 1);

	return -1;
}

template <typename ... Args>
struct variant : std::variant <Args...> {
	using std::variant <Args...> ::variant;

	template <typename T>
	inline bool is() const {
		return std::holds_alternative <T> (*this);
	}

	template <typename T>
	inline auto &as() {
		return std::get <T> (*this);
	}

	template <typename T>
	inline const auto &as() const {
		return std::get <T> (*this);
	}

	template <typename T>
	static constexpr int type_index() {
		return variant_index <T, Args...> (0);
	}
};

template <typename T>
struct is_variant_base : std::false_type {};

template <typename ... Args>
struct is_variant_base <variant <Args...>> : std::true_type {};

template <typename T>
concept is_variant = is_variant_base <T> ::value;

}

#define variant_case(T, K) case T::type_index <K> ()