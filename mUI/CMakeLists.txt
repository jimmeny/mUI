CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(TARGET_NAME mUI)
ADD_DEFINITIONS(-DMUI_EXPORTS)

SET(DIR_WITH_SRC . 
	System 
	System/Delegate 
	System.ComponentModel 
	System.Drawing 
	System.Drawing/Internals
	System.Forms 
	System.Threading
	Extra
)
	
INCLUDE_DIRECTORIES(. 
	${PROJECT_SOURCE_DIR}/HGE/include 
	${PROJECT_SOURCE_DIR}/Pal)
	
SET(IGNORED_LIBS "libc.lib")

find_package(freetype2 245)
if (FT2_FOUND)
	include_directories(${FT2_INCLUDE_DIR})
	link_directories(${FT2_LIBRARY_DIR})
else ()
	message(FATAL_ERROR "Unable to find FreeType2")
endif ()

SET(DEPENDENCY_LIBS Pal HGE hgehelp 
	debug debug/freetype245MT_D
	optimized release/freetype245MT_D
)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/dependency/freetype2/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/dependency/freetype2/lib
	${PROJECT_SOURCE_DIR}/dependency/hge/lib/vc)

SET(SRC_FILES "")
FOREACH(DIR IN LISTS DIR_WITH_SRC)
	
	FILE(GLOB FILE_H ${DIR}/*.h)
	FILE(GLOB FILE_CPP ${DIR}/*.cpp ${DIR}/*.c)
	
	STRING(REPLACE "/" "\\\\" SRCGROUP ${DIR})

	IF (${SRCGROUP} STREQUAL .)
		SOURCE_GROUP("${TARGET_NAME}" FILES ${FILE_H} ${FILE_CPP})
	ELSE (${SRCGROUP} STREQUAL .)
		SOURCE_GROUP("${SRCGROUP}" FILES ${FILE_H} ${FILE_CPP})
	ENDIF()	
	
	SET(SRC_FILES ${SRC_FILES} ${FILE_H} ${FILE_CPP})
ENDFOREACH()

ADD_LIBRARY(${TARGET_NAME} SHARED ${SRC_FILES})
TARGET_LINK_LIBRARIES(${TARGET_NAME} ${DEPENDENCY_LIBS})
SET_TARGET_PROPERTIES(${TARGET_NAME} PROPERTIES LINK_INTERFACE_LIBRARIES "")

SET_TARGET_PROPERTIES(${TARGET_NAME} 
	PROPERTIES 
	LINK_FLAGS /NODEFAULTLIB:\"${IGNORED_LIBS}\")
