project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Blaze/vendor/spdlog/include",
		"%{wks.location}/Blaze/src",
		"%{wks.location}/Blaze/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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
