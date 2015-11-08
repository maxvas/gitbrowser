cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

set(PROJECT gitbrowser)

project(${PROJECT})

add_subdirectory(qjs)
add_subdirectory(qfs)
include_directories(qjs/src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(HEADERS
    git/commitinfo.h
    git/gitmanager.h
    git/shell.h
    newdocument.h
    reposettings.h
    syncdialog.h
    texteditor.h
    versionbrowserdialog.h
    repotree/treeitemdelegate.h
    repotree/qjsmodel.h
    mainwindow.h
    mainwindow_ui.h
)

set(SOURCES
    git/commitinfo.cpp
    git/gitmanager.cpp
    git/shell.cpp
    newdocument.cpp
    reposettings.cpp
    syncdialog.cpp
    texteditor.cpp
    versionbrowserdialog.cpp
    repotree/treeitemdelegate.cpp
    repotree/qjsmodel.cpp
    mainwindow.cpp
    main.cpp
)

set(UI
    newdocument.ui
    reposettings.ui
    syncdialog.ui
    texteditor.ui
    versionbrowserdialog.ui
)

set(RESOURCES
    gitbrowser.qrc
)

qt5_wrap_ui(UI_CPP ${UI})

QT5_ADD_RESOURCES (RESOURCES_CPP ${RESOURCES})

add_executable(${PROJECT} ${HEADERS} ${SOURCES} ${UI_CPP} ${RESOURCES_CPP})
qt5_use_modules(${PROJECT} Quick Core Network Widgets QuickWidgets)
target_link_libraries(${PROJECT} qjs qfs)
