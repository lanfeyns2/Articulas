workspace "Articulas"
    configurations {"Debug","Release"}

g_includedirs = {"Articulas/vendor/include/","Articulas/vendor/GLFW/include/"}
outputdir  = "%{cfg.buildcfg}"

project "Articulas"
    kind "StaticLib"
    language "C++"
    location "%{prj.name}/"
    targetdir "%{wks.location}/bin/%{prj.name}/"
    objdir "%{wks.location}/bin-int/%{prj.name}/"

    pchheader "apch.h"
    pchsource "%{prj.location}/src/apch.cpp"

    links {"GLFW"}

    includedirs {g_includedirs,"%{prj.location}/src/"}

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

group "Third Party"
    include "Articulas/vendor/GLFW/premake5.lua"