#pragma once

#include <optional>

namespace bestd {

template <typename T>
struct optional : std::optional <T> {
	using upper = std::optional <T>;
	using upper::optional;

	template <typename F>
	requires std::is_invocable_v <F, T>
	auto feed(const F &f) const {
		using returns = decltype(f(T()));
		using result = optional <returns>;

		if (upper::has_value()) {
			return result(f(upper::value()));
		}

		return result(std::nullopt);
	}
};

template <typename T>
struct is_optional_base : std::false_type {};

template <typename T>
struct is_optional_base <optional <T>> : std::true_type {
	using inner_t = T;
};

template <typename T>
concept is_optional = is_optional_base <T> ::value;

}