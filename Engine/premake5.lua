project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/Bin/%{cfg.buildcfg}/%{cfg.architecture}")

	files {
		"Source/**.h",
		"Source/**.hpp",
		"Source/**.cpp",
		"Resources/**.vert",
		"Resources/**.frag",
		"%{wks.location}/vendor/glad/include/glad.c"
	}

	includedirs {
		"Source",
		"%{wks.location}/Vendor/spdlog/include",
		"%{wks.location}/Vendor/glfw/include",
		"%{wks.location}/Vendor/glad/include",
		"%{wks.location}/Vendor/glm/include"
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
		defines {
			"DEBUG"
		}
		
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines {
			"RELEASE"
		}
		
		runtime "Release"
		optimize "on"
