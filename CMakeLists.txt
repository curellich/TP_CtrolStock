
##---------------------------------------------------
## Please set your wxWidgets configuration here
##---------------------------------------------------

# Here you can define what libraries of wxWidgets you need for your
# application. You can figure out what libraries you need here;
# https://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html
# We need the Find package for wxWidgets to work
# NOTE: if you're using aui, include aui in this required components list.
# Declare the minimum required CMake version
cmake_minimum_required(VERSION 2.8.12)

# Name the project
project(Tp_CtrolStock)

# Request the required wxWidgets libs
find_package(wxWidgets 3.1 COMPONENTS all REQUIRED)

##---------------------------------------------------
## Actual config file starts here
##---------------------------------------------------

# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )

# Add source files
set(SOURCE_FILES
        Deposito.cpp
        Deposito.h
        Application.cpp
        Application.h
        Producto.cpp
        Producto.h
        Utileria.cpp
        Utileria.h
        WinAlta.cpp
        WinAlta.h
        WinModificar.h
        WinModificar.cpp
        WinPrincipal.cpp
        WinPrincipal.h
        WinCompra.cpp
        WinCompra.h
        WinVenta.cpp
        WinVenta.h
        WinListar.cpp
        WinListar.h
        wxfb_project.cpp
        wxfb_project.h
        Operacion.cpp
        Operacion.h
        Listado.cpp
        Listado.h
        )

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
if(WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} sample.rc )
endif(WIN32)

# the above paths and defines will be used in this build
add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE_FILES})

# Add to forty to the wxWidgets libraries. These are
# set for  by the find script. Other needed libraries can be added here
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})

