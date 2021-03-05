include(Catch)

add_executable(${PROJECT_NAME}_test
    # TODO: <files>
    main.cpp
    base64_binary.cpp
    boolean.cpp
    decimal.cpp
    double.cpp
    hex_binary.cpp
    normalized_string.cpp
    string.cpp
    token.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    tnt::math
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)