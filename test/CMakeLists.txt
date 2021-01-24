include(Catch)

add_executable(${PROJECT_NAME}_test
    # TODO: <files>
    main.cpp
    double.cpp
    normalized_string.cpp
    string.cpp
    token.cpp
 "decimal.cpp")

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    tnt::math
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)