 -- Blaze Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Blaze/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Blaze/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/Blaze/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Blaze/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Blaze/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Blaze/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Blaze/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Blaze/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/Blaze/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Blaze/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/Blaze/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/Blaze/vendor/VulkanSDK/Bin"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"
LibraryDir["VulkanSDK_DLL"] = "%{wks.location}/Blaze/vendor/VulkanSDK/Bin"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"