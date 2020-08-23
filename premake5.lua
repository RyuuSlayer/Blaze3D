workspace "Blaze"
	architecture "x86_64"
	startproject "Blaze-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Blaze/vendor/GLFW/include"
IncludeDir["Glad"] = "Blaze/vendor/Glad/include"
IncludeDir["ImGui"] = "Blaze/vendor/imgui"
IncludeDir["glm"] = "Blaze/vendor/glm"
IncludeDir["stb_image"] = "Blaze/vendor/stb_image"

group "Dependencies"
	include "Blaze/vendor/GLFW"
	include "Blaze/vendor/Glad"
	include "Blaze/vendor/imgui"

group ""

project "Blaze"
	location "Blaze"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "bzpch.h"
	pchsource "Blaze/src/bzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BZ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Blaze/vendor/spdlog/include",
		"Blaze/src",
		"Blaze/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Blaze"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BZ_DIST"
		runtime "Release"
		optimize "on"

project "Blaze-Editor"
	location "Blaze-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Blaze/vendor/spdlog/include",
		"Blaze/src",
		"Blaze/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Blaze"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BZ_DIST"
		runtime "Release"
		optimize "on"