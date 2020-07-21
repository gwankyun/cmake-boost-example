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
  set(runtime
    "$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:/MTd;>"
    "$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:/MT;>")
else()
  set(runtime
    "$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:/MDd;>"
    "$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:/MD;>")
endif()

cmake_print_variables(Boost_USE_STATIC_LIBS)
cmake_print_variables(Boost_USE_STATIC_RUNTIME)

find_package(Boost 1.73.0 REQUIRED COMPONENTS date_time filesystem log program_options)

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
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;>")

# 可執行文件
set(main main)
add_executable(${main})

# 源文件
target_sources(${main} PRIVATE src/main.cpp)

set(msvc_options
    "$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${runtime};/Od;/Ob0>;"
    "$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${runtime};/O2;/Ob2>;"
)

# 編譯器選項
target_compile_options(${main} PUBLIC ${msvc_options})

# 庫目錄
target_link_directories(${main} PRIVATE ${Boost_LIBRARY_DIRS})

# 引用庫
target_link_libraries(${main} Boost::filesystem Boost::log)

# 引用目錄
target_include_directories(${main}
  PRIVATE
    include ${Boost_INCLUDE_DIRS}
)

# Boost.Test
add_executable(test)
target_sources(test PRIVATE src/test/test1.cpp src/test/test2.cpp)
target_include_directories(test
  PRIVATE
    include ${Boost_INCLUDE_DIRS}
)

# Boost.Asio
set(asio_source
    src/asio/buffer.hpp
    src/asio/log.hpp
    src/asio/option.h
)

set(server server)
add_executable(${server})
set_target_properties(${server} PROPERTIES FOLDER asio)
target_sources(${server} PRIVATE
    src/asio/server.cpp
    src/asio/server.h
    ${asio_source}
)
target_include_directories(${server}
  PRIVATE
    include ${Boost_INCLUDE_DIRS}
)
target_link_libraries(${server} Boost::log Boost::program_options)
target_compile_options(${server} PUBLIC ${msvc_options})
target_compile_features(${server} PUBLIC cxx_std_17)

set(client client)
add_executable(${client})
set_target_properties(${client} PROPERTIES FOLDER asio)
target_sources(${client} PRIVATE
    src/asio/client.cpp
    src/asio/client.h
    ${asio_source}
)
target_include_directories(${client}
  PRIVATE
    include ${Boost_INCLUDE_DIRS}
)
target_link_libraries(${client} Boost::log Boost::program_options)
target_compile_options(${client} PUBLIC ${msvc_options})
target_compile_features(${client} PUBLIC cxx_std_17)
