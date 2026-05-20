set(DATA_ENGINE_SOURCES 
    math_utils.cpp 
    storage_engine.cpp 
    query_interface.cpp
    )
add_library(DataEngineCore ${DATA_ENGINE_SOURCES})
#PUBLIC PRIVATE OR INTERFACE
target_include_directories(DataEngineCore PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(DataEngineApp main.cpp)
target_link_libraries(DataEngineApp PRIVATE DataEngineCore)