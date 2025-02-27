cmake_minimum_required(VERSION 3.30)

project(PostMachine VERSION 0.3.6 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "post-machine")
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CMAKE_SYSTEM_NAME}-v${CPACK_PACKAGE_VERSION}")
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/package")

include(CPack)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools)
qt_standard_project_setup()

file(GLOB PROJECT_SOURCES
     src/*.hpp
     src/*.cpp
     src/*.ui
)

include_directories(src)

if (WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/data/info.rc")
endif ()

qt_add_executable(PostMachine
                ${PROJECT_SOURCES}
                ${APP_ICON_RESOURCE_WINDOWS}
                data/recources.qrc)

set(TRANSLATIONS_FILES ${CMAKE_SOURCE_DIR}/locales/postmachine.uk_UA.ts
                       ${CMAKE_SOURCE_DIR}/locales/postmachine.en_US.ts
)

qt_add_translations(PostMachine TS_FILES ${TRANSLATIONS_FILES} QM_FILES_OUTPUT_VARIABLE qm_files)
install(FILES ${qm_files} DESTINATION "translations")

add_dependencies(PostMachine PostMachine_lupdate)
add_dependencies(PostMachine PostMachine_lrelease)

target_link_libraries(PostMachine PRIVATE Qt6::Core Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS PostMachine
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET PostMachine
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
