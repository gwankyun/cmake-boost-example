# cmake最低版本
cmake_minimum_required(VERSION 3.22)

# 項目名
set(project cmake-boost-example)
project(${project})

# 包含模塊
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)

cmake_print_variables(CMAKE_SYSTEM_NAME) # 操作系統
cmake_print_variables(CMAKE_SYSTEM_VERSION) # 操作系統版本
cmake_print_variables(CMAKE_CXX_COMPILER_ID) # 編譯器
cmake_print_variables(CMAKE_CXX_COMPILER_VERSION) # 編譯器版本

option(Boost_DEBUG "" OFF) # Boost調試
option(Boost_USE_STATIC_LIBS "" ON) # 使用靜態庫
option(Boost_USE_STATIC_RUNTIME "" OFF) # 運行時靜態庫
option(USE_CXX_STD_17 "" ON) # 使用C++17
option(Boost_NO_WARN_NEW_VERSIONS "" ON) # 啟用新Boost不報警告

function(get_win32_winnt version)
  if(WIN32)
    if(CMAKE_SYSTEM_VERSION)
      set(ver ${CMAKE_SYSTEM_VERSION})
      string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
      string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
      # Check for Windows 10, b/c we'll need to convert to hex 'A'.
      if("${verMajor}" MATCHES "10")
        set(verMajor "A")
        string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
      endif()
      # Remove all remaining '.' characters.
      string(REPLACE "." "" ver ${ver})
      # Prepend each digit with a zero.
      string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
      set(${version} "0x${ver}" PARENT_SCOPE)
    endif()
  endif()
endfunction()

set(win32_winnt "")
get_win32_winnt(win32_winnt)

# 編譯器宏
add_compile_definitions("$<$<PLATFORM_ID:Windows>:_WIN32_WINNT=${win32_winnt}>")

# 設置編譯選項
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP>;/Zc:__cplusplus;")

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

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

find_package(Boost REQUIRED COMPONENTS date_time filesystem log program_options serialization)

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

set(compiler_options
  "$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${runtime};/Od;/Ob0>;"
  "$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${runtime};/O2;/Ob2>;")


# 編譯器選項
target_compile_options(${main} PUBLIC ${compiler_options})

# 庫目錄
target_link_directories(${main} PRIVATE ${Boost_LIBRARY_DIRS})

# 引用庫
target_link_libraries(${main} Boost::filesystem Boost::log)

# 引用目錄
target_include_directories(${main}
  PRIVATE
    include ${Boost_INCLUDE_DIRS})

# Boost.Test
set(test test)
add_executable(${test})
target_sources(${test} PRIVATE
  src/test/test1.cpp
  src/test/test2.cpp
  src/asio/test.cpp)
target_compile_options(${test} PUBLIC ${compiler_options})
target_link_libraries(${test} Boost::serialization Boost::log)
target_include_directories(${test}
  PRIVATE
    include ${Boost_INCLUDE_DIRS})

# Boost.Asio
set(asio asio)

if(USE_CXX_STD_17)
  set(cxx_std cxx_std_17)
else()
  set(cxx_std cxx_std_11)
endif()

set(asio_sources
  src/asio/buffer.hpp
  src/asio/log.hpp
  src/asio/option.hpp
  src/asio/socket.hpp
)

set(asio_include_directories include ${Boost_INCLUDE_DIRS})

set(data data)
add_library(${data})
target_sources(${data} PRIVATE
  src/asio/data.cpp
  src/asio/data.h)
set_target_properties(${data} PROPERTIES FOLDER ${asio})
target_link_libraries(${data} Boost::serialization)
target_compile_options(${data} PRIVATE ${compiler_options})
target_compile_features(${data} PRIVATE ${cxx_std})

set(asio_libraries Boost::log Boost::program_options ${data})

set(server server)
add_executable(${server})
target_sources(${server} PRIVATE
  src/asio/server.cpp
  src/asio/server.h
  ${asio_sources})

set(client client)
add_executable(${client})
target_sources(${client} PRIVATE
  src/asio/client.cpp
  src/asio/client.h
  ${asio_sources})

## 協程
set(server_stackless_coroutine server_stackless_coroutine)
add_executable(${server_stackless_coroutine})
target_sources(${server_stackless_coroutine} PRIVATE
  src/asio/server_stackless_coroutine.cpp
  ${asio_sources})

set(client_stackless_coroutine client_stackless_coroutine)
add_executable(${client_stackless_coroutine})
target_sources(${client_stackless_coroutine} PRIVATE
  src/asio/client_stackless_coroutine.cpp
  ${asio_sources})

foreach(i IN LISTS ${server} ${client} ${server_stackless_coroutine} ${client_stackless_coroutine})
  set_target_properties(${i} PROPERTIES FOLDER ${asio})
  target_include_directories(${i} PRIVATE ${asio_include_directories})
  target_link_libraries(${i} PUBLIC ${asio_libraries})
  target_compile_options(${i} PRIVATE ${compiler_options})
  target_compile_features(${i} PRIVATE ${cxx_std})
endforeach()

set(preprocessor preprocessor)
add_executable(${preprocessor})
target_sources(${preprocessor} PRIVATE
  src/preprocessor.cpp)
target_compile_options(${preprocessor} PUBLIC ${compiler_options})
target_link_libraries(${preprocessor} Boost::headers)
