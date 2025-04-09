
include_directories("../Articulas/src/")
add_executable(Articulas-Editor  "src/main.cpp")
target_link_libraries(Articulas-Editor PRIVATE Articulas)