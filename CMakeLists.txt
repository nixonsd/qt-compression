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
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources/qt-compression.rc")

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
	add_executable(qt-compression WIN32 ${SOURCES} ${APP_ICON_RESOURCE_WINDOWS}) # ${APP_ICON_RESOURCE_WINDOWS}
elseif(UNIX)
	add_executable(qt-compression ${SOURCES} ${APP_ICON_RESOURCE_WINDOWS})
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

# Retrieve the absolute path to qmake and then use that path to find
# the binaries
get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS ${CMAKE_PREFIX_PATH}/bin)

add_custom_command(TARGET qt-compression
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_CURRENT_BINARY_DIR}/windeployqt"
		COMMAND set PATH="${_qt_bin_dir}"
        COMMAND "${WINDEPLOYQT_EXECUTABLE}" --dir "${CMAKE_CURRENT_BINARY_DIR}/windeployqt" --verbose 0 --no-compiler-runtime --no-translations --no-angle --release --no-opengl-sw "$<TARGET_FILE:qt-compression>"
    )

	# copy deployment directory during installation
    install(
        DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/windeployqt/"
        DESTINATION "."
    )

set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
include(InstallRequiredSystemLibraries)

install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Release/" DESTINATION ".")

install(
    TARGETS qt-compression 
    RUNTIME DESTINATION "."
    CONFIGURATIONS ${CMAKE_CONFIGURATION_TYPES}
)