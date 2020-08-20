workspace "Blaze"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Blaze/vendor/GLFW/include"
IncludeDir["Glad"] = "Blaze/vendor/Glad/include"
IncludeDir["ImGui"] = "Blaze/vendor/imgui"

group "Dependencies"
	include "Blaze/vendor/GLFW"
	include "Blaze/vendor/Glad"
	include "Blaze/vendor/imgui"

group ""

project "Blaze"
	location "Blaze"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "bzpch.h"
	pchsource "Blaze/src/bzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"BZ_PLATFORM_WINDOWS",
			"BZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BZ_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Blaze/src"
	}

	links
	{
		"Blaze"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"BZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BZ_DIST"
		runtime "Release"
		optimize "On"