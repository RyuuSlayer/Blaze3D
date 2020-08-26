include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Blaze"
	architecture "x86_64"
	startproject "Blaze-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Blaze/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Blaze/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Blaze/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Blaze/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Blaze/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Blaze/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Blaze/vendor/GLFW"
	include "Blaze/vendor/Glad"
	include "Blaze/vendor/imgui"
group ""

include "Blaze"
include "Sandbox"
include "Blaze-Editor"
