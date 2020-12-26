cmake_minimum_required(VERSION 3.10)

project(qt-compression)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin )

add_definitions(-DUNICODE -D_UNICODE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(OpenGL)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)

#======================= INCLUSION OF Our Code ======================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

if (WIN32)
	add_executable(qt-compression WIN32 ${SOURCES})
elseif(UNIX)
	add_executable(qt-compression ${SOURCES})
endif()

# Add the target includes
target_include_directories(qt-compression PRIVATE ${FORMS_DIR})
target_include_directories(qt-compression PRIVATE ${INCLUDE_DIR})
target_include_directories(qt-compression PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(qt-compression Qt5::Core)
target_link_libraries(qt-compression Qt5::OpenGL)
target_link_libraries(qt-compression Qt5::Xml)
target_link_libraries(qt-compression Qt5::Widgets)
target_link_libraries(qt-compression ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

include(InstallRequiredSystemLibraries)

install(
    TARGETS qt-compression 
    RUNTIME DESTINATION "."
    CONFIGURATIONS ${CMAKE_CONFIGURATION_TYPES}
)

install (FILES
    $<TARGET_FILE:Qt5::Widgets>
    $<TARGET_FILE:Qt5::Core>
    $<TARGET_FILE:Qt5::Gui>
    DESTINATION "."
)

install (FILES
    ${CMAKE_PREFIX_PATH}/plugins/styles/qwindowsvistastyle.dll
    DESTINATION "styles"
)

install (FILES
    ${CMAKE_PREFIX_PATH}/plugins/platforms/qwindows.dll
    ${CMAKE_PREFIX_PATH}/plugins/platforms/qminimal.dll
    ${CMAKE_PREFIX_PATH}/plugins/platforms/qdirect2d.dll
    ${CMAKE_PREFIX_PATH}/plugins/platforms/qoffscreen.dll
    DESTINATION "platforms"
)