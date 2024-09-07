project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}")

	files {
		"source/**.h",
		"source/**.cpp",
		"%{wks.location}/vendor/glad/include/glad.c"
	}

	includedirs {
		"source",
		"%{wks.location}/vendor/spdlog/include",
		"%{wks.location}/vendor/glfw/include",
		"%{wks.location}/vendor/glad/include"
	}

	libdirs {
		"%{wks.location}/vendor/glfw/lib"
	}

	links {
		"glfw3",
		"opengl32"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"