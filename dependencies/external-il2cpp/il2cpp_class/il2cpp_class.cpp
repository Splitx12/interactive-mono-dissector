#include "il2cpp_class.hpp"

#include "../il2cpp/il2cpp.hpp"

std::uintptr_t il2cpp::types::il2cpp_class_t::get_instance() const
{
	return instance;
}

std::vector<std::pair<std::string, std::uint32_t>> il2cpp::types::il2cpp_class_t::get_fields() const
{
	std::vector<std::pair<std::string, std::uint32_t>> fields;

	for (auto current_field = fields_table; current_field < fields_table + (fields_size * 0x20); current_field += 0x20)
			fields.emplace_back(il2cpp.read_string(il2cpp.read<std::uintptr_t>(current_field)), il2cpp.read<std::int32_t>(current_field + 0x18));

	return fields;
}

il2cpp::types::il2cpp_class_t::il2cpp_class_t(const std::uintptr_t instance, const il2cpp_t& il2cpp)
:
	instance{ instance },
	il2cpp{ il2cpp },

	fields_size{ il2cpp.read<std::uint16_t>(instance + 0x11C) },
	fields_table{ il2cpp.read<std::uintptr_t>(instance + 0x80) },
	static_fields_table{ il2cpp.read<std::uintptr_t>(instance + 0xB8) }
{}
