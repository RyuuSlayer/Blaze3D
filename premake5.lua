include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Blaze/vendor/GLFW"
	include "Blaze/vendor/Glad"
	include "Blaze/vendor/imgui"
	include "Blaze/vendor/yaml-cpp"
group ""

include "Blaze"
include "Sandbox"
include "Blaze-Editor"
