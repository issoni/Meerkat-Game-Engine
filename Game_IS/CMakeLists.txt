set(HEADER_FILES
	MyGame.h
)

set(SOURCE_FILES
	main.cpp
	MyGame.cpp
)

add_executable(Game_IS ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_IS Meerkat)

include_directories(../Meerkat/include) 