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

project "Blaze"
	location "Blaze"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BZ_PLATFORM_WINDOWS",
			"BZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox")
		}

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BZ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BZ_DIST"
		optimize "On"