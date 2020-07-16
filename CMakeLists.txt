# cmake最低版本
cmake_minimum_required(VERSION 3.18)

# 項目名
set(project cmake-boost-example)
project(${project})

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包含模塊
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 引入Boost
# set(Boost_DEBUG ON)

# 使用靜態庫
if(DEFINED Boost_USE_STATIC_LIBS)
else()
  set(Boost_USE_STATIC_LIBS ON)
endif()

# 運行時靜態庫
if(DEFINED Boost_USE_STATIC_RUNTIME)
else()
  set(Boost_USE_STATIC_RUNTIME ON)
endif()

# BoostConfig.cmake所在路徑
if(NOT Boost_DIR)
  set(Boost_DIR "C:/local/boost_1_73_0/lib64-msvc-14.2/cmake/Boost-1.73.0")
endif()
cmake_print_variables(Boost_DIR)

if(Boost_USE_STATIC_RUNTIME)
  set(Boost_USE_STATIC_LIBS ON)
  set(runtime_Release "/MT")
  set(runtime_Debug "/MTd")
else()
  set(runtime_Release "/MD")
  set(runtime_Debug "/MDd")
endif()

cmake_print_variables(Boost_USE_STATIC_LIBS)
cmake_print_variables(Boost_USE_STATIC_RUNTIME)

find_package(Boost 1.73.0 REQUIRED COMPONENTS filesystem log)

if(Boost_FOUND)
  cmake_print_variables(Boost_INCLUDE_DIRS)
  cmake_print_variables(Boost_LIBRARY_DIRS)
  cmake_print_variables(Boost_LIBRARIES)
  cmake_print_variables(Boost_LIB_VERSION)
else()
  message(FATAL_ERROR "Boost not found")
endif()

# 編譯器選項
add_compile_options(
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP>")

# 可執行文件
add_executable(${project} "")

# 源文件
target_sources(${project} PRIVATE src/main.cpp)

# 編譯器選項
target_compile_options(${project} PUBLIC
  "$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${runtime_Debug};/Od;/Ob0>"
  "$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${runtime_Release};/O2;/Ob2>"
)

# 庫目錄
target_link_directories(${project} PRIVATE ${Boost_LIBRARY_DIRS})

# 引用庫
target_link_libraries(${project} Boost::filesystem Boost::log)

# 引用目錄
target_include_directories(${project}
  PRIVATE
    include ${Boost_INCLUDE_DIRS}
)
