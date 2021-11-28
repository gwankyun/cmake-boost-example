add_executable(${asio})
target_sources(${asio} PRIVATE
  src/asio/asio.cpp
)
set_target_properties(${asio} PROPERTIES FOLDER ${asio})
target_include_directories(${asio} PRIVATE ${asio_include_directories})
target_link_libraries(${asio} Boost::log)

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

set(client_spawn client_spawn)
add_executable(${client_spawn})
target_sources(${client_spawn} PRIVATE
  src/asio/client_spawn.cpp
  src/asio/common.h
  ${asio_sources})
set_target_properties(${client_spawn} PROPERTIES FOLDER ${asio})
target_link_libraries(${client_spawn} PUBLIC ${asio_libraries} Boost::context Boost::coroutine)
target_include_directories(${client_spawn} PRIVATE ${asio_include_directories})
target_compile_options(${client_spawn} PRIVATE ${compiler_options})
target_compile_features(${client_spawn} PRIVATE ${cxx_std})

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