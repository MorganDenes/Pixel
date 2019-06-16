workspace "Pixel"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
			"Debug",
			"Release",
			"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pixel"
	location "Pixel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pxlpch.h"
	pchsource "Pixel/src/pxlpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines  
		{
			"PXL_PLATFORM_WINDOWS",
			"PXL_BUILD_DLL"
		}

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}

	filter "configurations:Debug"
		defines "PXL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PXL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PXL_DIST"
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
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Pixel/vendor/spdlog/include",
		"Pixel/src"
	}

	links
	{
		"Pixel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines  
		{
			"PXL_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PXL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PXL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PXL_DIST"
		optimize "On"
