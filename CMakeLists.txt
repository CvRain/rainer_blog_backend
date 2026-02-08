cmake_minimum_required(VERSION 3.16)

project(rainer_blog_dashboard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(third_party/NandinaUI)

include_directories(third_party)

qt_add_executable(apprainer_blog_dashboard
    src/main.cpp
)

qt_add_qml_module(apprainer_blog_dashboard
    URI rainer_blog_dashboard
    VERSION 1.0
    QML_FILES
    qml/Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apprainer_blog_dashboard PROPERTIES
    #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apprainer_blog_dashboard
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(apprainer_blog_dashboard
    PRIVATE third_party third_party/NandinaUI
)

target_link_libraries(apprainer_blog_dashboard
    PRIVATE Qt6::Quick Qt6::Core Nandinaplugin
)

include(GNUInstallDirs)
install(TARGETS apprainer_blog_dashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
