cmake_minimum_required(VERSION 3.5)

project(ex_modelview VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        ex_modelview/main.cpp
        ex_modelview/mainwindow.cpp
        ex_modelview/mainwindow.h
        ex_modelview/mainwindow.ui
        ex_modelview/examplemodel.h
        ex_modelview/examplemodel.cpp
        ex_modelview/addrowdialog.h
        ex_modelview/addrowdialog.cpp
        ex_modelview/addrowdialog.ui
        ex_modelview/customproxymodel.cpp
        ex_modelview/customproxymodel.h
        ex_modelview/customproxymodel1.cpp
        ex_modelview/customproxymodel1.h
        ex_modelview/aboutdialog.h
        ex_modelview/aboutdialog.cpp
        ex_modelview/aboutdialog.ui
        ex_modelview/renderarea.h
        ex_modelview/renderarea.cpp
        ex_modelview/customproxymodel2.cpp
        ex_modelview/customproxymodel2.h



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ex_modelview
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ex_modelview APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ex_modelview SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ex_modelview
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ex_modelview PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ex_modelview PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ex_modelview)
endif()
