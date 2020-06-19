CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ENABLE_TESTING()

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
#	ADD_DEFINITIONS("-Wall -Wextra -Weffc++ -Werror")
endif()

ADD_SUBDIRECTORY(2out)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(tutorial)

ADD_CUSTOM_TARGET(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
