include(Catch)

add_executable(${PROJECT_NAME}_test
    # TODO: <files>
    main.cpp
    base64_binary.cpp
    boolean.cpp
    byte.cpp
    decimal.cpp
    double.cpp
    float.cpp
    hex_binary.cpp
    int.cpp
    integer.cpp
    long.cpp
    negative_integer.cpp
    non_negative_integer.cpp
    non_positive_integer.cpp
    normalized_string.cpp
    positive_integer.cpp
    short.cpp
    string.cpp
    token.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    tnt::math
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)