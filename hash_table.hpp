#pragma once

#include <unordered_map>

#include "optional.hpp"

namespace bestd {

// Optional returns for hash tables
template <typename K, typename V>
struct hash_table : std::unordered_map <K, V> {
	using standard = std::unordered_map <K, V>;
	using standard::unordered_map;

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