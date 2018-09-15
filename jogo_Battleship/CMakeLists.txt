cmake_minimum_required(VERSION 2.6)
#Project name
project (Projeto_de_teste_dos_testes_google)

#=== FINDING PACKAGES ===#
#Locate GTest package (library) 
#find_package(GTest REQUIRED) 
include_directories( ${GTEST_INCLUDE_DIRS})

#=== SETTING VARIABLES ===# 
# Compiling flags 
set( GCC_COMPILE_FLAGS "-Wall" ) 
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" ) 
# Include dir 
include_directories( include )

#=== Library ===
# We want to build a static library.
add_library(ProjetoTeste STATIC "src/whattotest.cpp")
# define C++14 as the standard.
target_compile_features(ProjetoTeste PUBLIC cxx_std_14)
# Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "make install" to apply
install(TARGETS ProjetoTeste ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

#=== Driver App ===
# Define where the linker should look for libraries at
#//link_directories( ${CMAKE_SOURCE_DIR}/lib ) # The library is locally installed.
# Define the sources
#//add_executable(driver_ranges "src/driver.cpp")
# Define the lib to link to.
#//target_link_libraries(driver_ranges PRIVATE IntRange )
# define C++11 as the standard.
#//target_compile_features(driver_ranges PUBLIC cxx_std_11)

#=== Test target ===
# The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES_TEST "test/*.cpp" )
# Define the sources
add_executable(run_tests ${SOURCES_TEST} )
set ( MY_GTEST_LIB "libgtest.a" "libgtest_main.a" )
# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${MY_GTEST_LIB} PRIVATE pthread PRIVATE ProjetoTeste )
# define C++14 as the standard.
target_compile_features(run_tests PUBLIC cxx_std_14)

