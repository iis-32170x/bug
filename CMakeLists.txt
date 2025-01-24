file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

add_library (vertexModule SHARED ${SOURCES})
target_link_libraries(vertexModule PRIVATE sc-memory)
target_include_directories(vertexModule PRIVATE ${SC_MEMORY_LIBRARIES})