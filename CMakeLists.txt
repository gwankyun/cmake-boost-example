# cmake最低版本
cmake_minimum_required(VERSION 3.18)

# 項目名
set(project cmake-boost-example)
project(${project})

# 包含模塊
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)
include(WriteCompilerDetectionHeader)
include(CheckIncludeFileCXX)

cmake_print_variables(CMAKE_SYSTEM_NAME)
cmake_print_variables(CMAKE_CXX_COMPILER_ID)
cmake_print_variables(CMAKE_CXX_COMPILER_VERSION)

option(Boost_DEBUG "" OFF) # Boost調試
option(Boost_USE_STATIC_LIBS "" ON) # 使用靜態庫
option(Boost_USE_STATIC_RUNTIME "" OFF) # 運行時靜態庫
option(USE_CXX_STD_17 "" ON) # 使用C++17

if(WIN32)
  macro(get_WIN32_WINNT version)
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
      set(${version} "0x${ver}")
    endif()
  endmacro()

  get_WIN32_WINNT(ver)
  #add_definitions(-D_WIN32_WINNT=${ver})
  set(_WIN32_WINNT ${ver})
endif()

write_compiler_detection_header(
  FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/compiler_detection.h"
  PREFIX FEATURE
  COMPILERS AppleClang Clang GNU MSVC SunPro Intel
  ALLOW_UNKNOWN_COMPILER_VERSIONS
  FEATURES
    cxx_aggregate_default_initializers
    cxx_alias_templates
    cxx_alignas
    cxx_alignof
    cxx_attributes
    cxx_attribute_deprecated
    cxx_auto_type
    cxx_binary_literals
    cxx_constexpr
    cxx_contextual_conversions
    cxx_decltype_incomplete_return_types
    cxx_decltype
    cxx_decltype_auto
    cxx_default_function_template_args
    cxx_defaulted_functions
    cxx_defaulted_move_initializers
    cxx_delegating_constructors
    cxx_deleted_functions
    cxx_digit_separators
    cxx_enum_forward_declarations
    cxx_explicit_conversions
    cxx_extended_friend_declarations
    cxx_extern_templates
    cxx_final
    cxx_func_identifier
    cxx_generalized_initializers
    cxx_generic_lambdas
    cxx_inheriting_constructors
    cxx_inline_namespaces
    cxx_lambdas
    cxx_lambda_init_captures
    cxx_local_type_template_args
    cxx_long_long_type
    cxx_noexcept
    cxx_nonstatic_member_init
    cxx_nullptr
    cxx_override
    cxx_range_for
    cxx_raw_string_literals
    cxx_reference_qualified_functions
    cxx_relaxed_constexpr
    cxx_return_type_deduction
    cxx_right_angle_brackets
    cxx_rvalue_references
    cxx_sizeof_member
    cxx_static_assert
    cxx_strong_enums
    cxx_thread_local
    cxx_trailing_return_types
    cxx_unicode_literals
    cxx_uniform_initialization
    cxx_unrestricted_unions
    cxx_user_literals
    cxx_variable_templates
    cxx_variadic_macros
    cxx_variadic_templates
    cxx_template_template_parameters
)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# BoostConfig.cmake所在路徑
if(NOT Boost_DIR)
  set(Boost_DIR "C:/local/boost_1_74_0/lib64-msvc-14.2/cmake/Boost-1.74.0")
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

find_package(Boost 1.74.0 REQUIRED COMPONENTS date_time filesystem log program_options serialization)

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

set(platform_definitions
  "$<$<PLATFORM_ID:Windows>:_WIN32_WINNT=${_WIN32_WINNT}>")

add_compile_definitions(${platform_definitions})

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
target_link_libraries(${test} Boost::serialization)
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
set_target_properties(${data} PROPERTIES FOLDER ${asio})
target_sources(${data} PRIVATE
  src/asio/data.cpp
  src/asio/data.h)
target_link_libraries(${data} Boost::serialization)
target_compile_options(${data} PRIVATE ${compiler_options})
target_compile_features(${data} PRIVATE ${cxx_std})

set(asio_libraries Boost::log Boost::program_options ${data})

set(server server)
add_executable(${server})
set_target_properties(${server} PROPERTIES FOLDER ${asio})
target_sources(${server} PRIVATE
  src/asio/server.cpp
  src/asio/server.h
  ${asio_sources})
target_include_directories(${server} PRIVATE ${asio_include_directories})
target_link_libraries(${server} PUBLIC ${asio_libraries})
target_compile_options(${server} PRIVATE ${compiler_options})
target_compile_features(${server} PRIVATE ${cxx_std})

set(client client)
add_executable(${client})
set_target_properties(${client} PROPERTIES FOLDER ${asio})
target_sources(${client} PRIVATE
  src/asio/client.cpp
  src/asio/client.h
  ${asio_sources})
target_include_directories(${client} PRIVATE ${asio_include_directories})
target_link_libraries(${client} ${asio_libraries})
target_compile_options(${client} PRIVATE ${compiler_options})
target_compile_features(${client} PRIVATE ${cxx_std})

## 協程
set(server_stackless_coroutine server_stackless_coroutine)
add_executable(${server_stackless_coroutine})
set_target_properties(${server_stackless_coroutine} PROPERTIES FOLDER ${asio})
target_sources(${server_stackless_coroutine} PRIVATE
  src/asio/server_stackless_coroutine.cpp
  ${asio_sources})
target_include_directories(${server_stackless_coroutine} PRIVATE ${asio_include_directories})
target_link_libraries(${server_stackless_coroutine} ${asio_libraries})
target_compile_options(${server_stackless_coroutine} PRIVATE ${compiler_options})
target_compile_features(${server_stackless_coroutine} PRIVATE ${cxx_std})

set(client_stackless_coroutine client_stackless_coroutine)
add_executable(${client_stackless_coroutine})
set_target_properties(${client_stackless_coroutine} PROPERTIES FOLDER ${asio})
target_sources(${client_stackless_coroutine} PRIVATE
  src/asio/client_stackless_coroutine.cpp
  ${asio_sources})
target_include_directories(${client_stackless_coroutine} PRIVATE ${asio_include_directories})
target_link_libraries(${client_stackless_coroutine} ${asio_libraries})
target_compile_options(${client_stackless_coroutine} PRIVATE ${compiler_options})
target_compile_features(${client_stackless_coroutine} PRIVATE ${cxx_std})

set(preprocessor preprocessor)
add_executable(${preprocessor})
target_sources(${preprocessor} PRIVATE
  src/preprocessor.cpp)
target_compile_options(${preprocessor} PUBLIC ${compiler_options})
target_include_directories(${preprocessor}
  PRIVATE
    include ${Boost_INCLUDE_DIRS})
