add_executable(DataEngineTests 
    query_layer_test.cpp
    query_interface_test.cpp
    storage_engine_test.cpp
    )

target_link_libraries(DataEngineTests PRIVATE DataEngineCore GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(DataEngineTests)