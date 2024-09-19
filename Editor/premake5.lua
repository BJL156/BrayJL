project "Editor"
	kind "ConsoleApp"
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
		"%{wks.location}/vendor/glad/include/glad.c",
		"%{wks.location}/Vendor/imgui/include/**.cpp"
	}

	externalincludedirs {
		"%{wks.location}/Vendor/imgui/include"
	}
	
	vpaths {
		["External Libraries"] = { 
			"%{wks.location}/Vendor/imgui/include/**.h",
			"%{wks.location}/Vendor/imgui/include/**.cpp"
		},
	}

	includedirs {
		"Source",
		"%{wks.location}/Engine/source",
		"%{wks.location}/Vendor/spdlog/include",
		"%{wks.location}/Vendor/glfw/include",
		"%{wks.location}/Vendor/glad/include",
		"%{wks.location}/Vendor/glm/include",
		"%{wks.location}/Vendor/assimp/include",
		"%{wks.location}/Vendor/stb/include",
		"%{wks.location}/Vendor/imgui/include"
	}

	libdirs {
		"%{wks.location}/vendor/glfw/lib",
		"%{wks.location}/vendor/assimp/lib"
	}

	links {
		"Engine",
		"glfw3",
		"opengl32",
		"assimp-vc143-mt"
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
