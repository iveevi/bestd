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

}