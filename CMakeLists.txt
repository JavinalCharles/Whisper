cmake_minimum_required(VERSION 3.15)

project(
	SpooktoberSubmission
	VERSION 0.1
	DESCRIPTION "A submission attempt for Sppoktober Game Jam."
	LANGUAGES CXX
)

option(DEBUG "Enables DEBUG_MODE_ON Macro." ON)
option(DEBUG_VERBOSE "Enables DEBUG_VERBOSE_ENABLED" OFF)
option(BUILD_EXAMPLES "Instructs cmake to build the example programs as well, after building the library" OFF)

if(DEBUG)
add_compile_definitions(DEBUG_MODE_ON)
if(DEBUG_VERBOSE)
add_compile_definitions(DEBUG_VERBOSE_ENABLED)
endif()
endif()

set(SOURCES
	src/Components/RollingText.cpp
	src/Scenes/MenuScene.cpp
	src/main.cpp
)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)
target_compile_options(compiler_flags INTERFACE 
	"$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wunused;-Wno-unused-parameter;-O2>"
)

add_executable(whisper ${SOURCES})

# set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

target_include_directories(whisper
	PUBLIC
	${PROJECT_SOURCE_DIR}/include/
)

set(SDL_LIBS
	-lSDL2
	-lSDL2_image
	-lSDL2_mixer
	-lSDL2_ttf
)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set(SDL_LIBS
		-lSDL2main
		${SDL_LIBS}
		-lwinmm -limm32 -lversion -lsetupapi
	)
	set(SDL_INCLUDE_DIRS
		${PROJECT_SOURCE_DIR}/deps/include
	)

	set(SDL_LIBRARY_DIRS
		${PROJECT_SOURCE_DIR}/deps/lib
	)
	include_directories(${SDL_INCLUDE_DIRS})
	link_directories(${SDL_LIBRARY_DIRS})
endif()
target_link_libraries(whisper -lBA ${SDL_LIBS} compiler_flags)


