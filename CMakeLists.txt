cmake_minimum_required(VERSION 3.30)

project(postmachine VERSION 0.3.6 LANGUAGES CXX)

# C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CPack
set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_NAME "post-machine")
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CMAKE_SYSTEM_NAME}-v${CPACK_PACKAGE_VERSION}")
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/package")

# QT
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools)
qt_standard_project_setup()

# Files
file(GLOB PROJECT_SOURCES
     src/*.hpp
     src/*.cpp
     src/*.ui
)
include_directories(src)

# Resources
if (WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/data/info.rc")
endif ()


# App
qt_add_executable(${CMAKE_PROJECT_NAME}
                ${PROJECT_SOURCES}
                ${APP_ICON_RESOURCE_WINDOWS}
                data/recources.qrc)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# Translation
file(GLOB TRANSLATIONS_FILES
     locales/*.ts
)

qt_add_translations(${CMAKE_PROJECT_NAME} TS_FILES ${TRANSLATIONS_FILES} QM_FILES_OUTPUT_VARIABLE qm_files)

add_dependencies(${CMAKE_PROJECT_NAME} postmachine_lupdate)
add_dependencies(${CMAKE_PROJECT_NAME} postmachine_lrelease)

# Deploy
include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(LINUX)
set(CPACK_GENERATOR "TGZ")
install(FILES ${qm_files} DESTINATION ${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}/locales)
install(FILES ${CMAKE_SOURCE_DIR}/data/postmachine.png DESTINATION ${CMAKE_INSTALL_DATADIR}/pixmaps)
install(FILES ${CMAKE_SOURCE_DIR}/data/PostMachine.desktop DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
endif()

if (WIN32)
qt_generate_deploy_app_script(
    TARGET ${CMAKE_PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
endif ()

include(CPack)
