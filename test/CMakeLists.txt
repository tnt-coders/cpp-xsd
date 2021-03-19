include(Catch)

add_executable(${PROJECT_NAME}_test
    # TODO: <files>
    main.cpp
    xs_base64_binary.cpp
    xs_boolean.cpp
    xs_byte.cpp
    xs_decimal.cpp
    xs_double.cpp
    xs_entities.cpp
    xs_entity.cpp
    xs_float.cpp
    xs_hex_binary.cpp
    xs_id.cpp
    xs_idref.cpp
    xs_idrefs.cpp
    xs_int.cpp
    xs_integer.cpp
    xs_language.cpp
    xs_long.cpp
    xs_name.cpp
    xs_ncname.cpp
    xs_negative_integer.cpp
    xs_nmtoken.cpp
    xs_nmtokens.cpp
    xs_non_negative_integer.cpp
    xs_non_positive_integer.cpp
    xs_normalized_string.cpp
    xs_positive_integer.cpp
    xs_short.cpp
    xs_string.cpp
    xs_token.cpp
    xs_unsigned_byte.cpp
    xs_unsigned_int.cpp
    xs_unsigned_long.cpp
    xs_unsigned_short.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    tnt::math
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)