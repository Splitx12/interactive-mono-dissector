#include <ranges>
#include "dependencies/imgui/imgui_win32_directx12.hpp"
#include "dependencies/external-il2cpp/il2cpp/il2cpp.hpp"

std::uint32_t main()
{
	auto il2cpp = il2cpp::types::il2cpp_t{ "Rust" };

	const auto& images = il2cpp.get_images();

	std::optional<std::reference_wrapper<const std::pair<std::string, il2cpp::types::il2cpp_image_t>>> current_image;

	std::optional<std::reference_wrapper<const std::pair<std::string, il2cpp::types::il2cpp_class_t>>> current_class;

	imgui_render
	(
		950, 550, 
		
		[&]()
		{
			ImGui::SetNextWindowPos({ 0, 0 }), ImGui::SetNextWindowSize({ 950, 550 });

			ImGui::Begin("", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
			{
				ImGui::Text("Images");
				ImGui::ListBoxHeader(" ", { 450, 225 });
				{
					for (const auto& current_image_name : std::views::keys(images))
						if (ImGui::Selectable(current_image_name.c_str(), current_image->get().first == current_image_name))
							current_image = il2cpp.get_image(current_image_name);
				}
				ImGui::EndListBox();

				if (current_image.has_value())
				{
					ImGui::Text("Classes");
					ImGui::ListBoxHeader("  ", { 450, 225 });
					{
						for (const auto& current_class_name : std::views::keys(current_image->get().second.get_classes()))
							if (ImGui::Selectable(current_class_name.c_str(), current_class->get().first == current_class_name))
								current_class = current_image->get().second.get_class(current_class_name);
					}
					ImGui::EndListBox();
				}

				if (current_class.has_value())
				{
					ImGui::SetCursorPos({ 475, 10 });

					ImGui::Text("Fields");

					ImGui::SetCursorPos({ 475, 25 });

					ImGui::ListBoxHeader("   ", { 450, 470 });
					{
						for (const auto& [current_field_name, current_field_offset] : current_class->get().second.get_fields())
							ImGui::Text(current_field_name.c_str()), ImGui::SameLine(0, 420 - (current_field_name.size() * 7)), ImGui::Text(std::to_string(current_field_offset).c_str());
					}
					ImGui::EndListBox();
				}
			}
			ImGui::End();
		}
	);

	return 1;
}