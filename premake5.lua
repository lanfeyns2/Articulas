workspace "Articulas"
    configurations {"Debug","Release"}

g_includedirs = {"Articulas/vendor/include/"}

project "Articulas"
    kind "StaticLib"
    language "C++"
    location "%{prj.name}/"
    targetdir "%{wks.location}/bin/%{prj.name}/"
    objdir "%{wks.location}/bin-int/%{prj.name}/"

    includedirs {g_includedirs}

    files {"%{prj.location}/src/**.h","%{prj.location}/src/**.cpp"}
    buildoptions {"/utf-8"}

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    location "%{prj.name}/"
    targetdir "%{wks.location}/bin/%{prj.name}/"
    objdir "%{wks.location}/bin-int/%{prj.name}/"

    includedirs {g_includedirs,"Articulas/src/"}

    files {"%{prj.location}/src/**.h","%{prj.location}/src/**.cpp"}
    links {"Articulas"}
    buildoptions {"/utf-8"}