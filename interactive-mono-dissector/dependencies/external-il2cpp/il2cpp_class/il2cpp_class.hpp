#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <utility>
#include "../offsets/offsets.hpp"

namespace il2cpp::types
{
	class il2cpp_t;

	class il2cpp_class_t
	{
		const std::uintptr_t instance, fields_table, static_fields_table;

		std::uint16_t fields_size;

		const il2cpp_t& il2cpp;

	public:

		std::uintptr_t get_instance() const;

		std::vector<std::pair<std::string, std::uint32_t>> get_fields() const;

		il2cpp_class_t(il2cpp_class_t&&) = default;

		explicit il2cpp_class_t(const std::uintptr_t instance, const il2cpp_t& il2cpp);
	};
}