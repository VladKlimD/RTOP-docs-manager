cmake_minimum_required(VERSION 3.5)

project(RTOP-docs-manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# Путь к папке с базой данных
set(OBJECTS_DATABASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ObjectsDataBase)
# Путь к папке с иконками
set(ICONS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/icons)

# Копирование папок в бинарную директорию
file(COPY ${OBJECTS_DATABASE_DIR} DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${ICONS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/style.hpp
        src/ObjectsDataBase.h
        src/ObjectsDataBase.cpp
        src/TechInfo.h
        src/TechInfo.cpp
        src/TechInfo.ui
        src/LogBooks.h
        src/LogBooks.cpp
        src/LogBooks.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RTOP-docs-manager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(RTOP-docs-manager SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(RTOP-docs-manager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(RTOP-docs-manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(RTOP-docs-manager PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RTOP-docs-manager)
endif()
