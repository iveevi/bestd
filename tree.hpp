#pragma once

#include <map>

#include "optional.hpp"

namespace bestd {

// Optional returns for trees
template <typename K, typename V>
struct tree : std::map <K, V> {
	using standard = std::map <K, V>;
	using standard::map;

	optional <V> get(const K &k) {
		if (this->count(k))
			return this->operator[](k);

		return std::nullopt;
	}

	optional <V> get(const K &k) const {
		if (this->count(k))
			return this->at(k);

		return std::nullopt;
	}
};

} // namespace bestd