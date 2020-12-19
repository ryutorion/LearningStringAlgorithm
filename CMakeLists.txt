cmake_minimum_required(VERSION 3.19.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
	LearningStringAlgorithms
	VERSION 0.0.1
	LANGUAGES CXX
)

if(MSVC)
	add_compile_options(
		/W4
		/WX
		/permissive-
	)
endif()

add_executable(naive naive.cpp)
