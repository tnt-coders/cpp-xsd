tnt_project_AddLibrary(${PROJECT_NAME}
  TARGET
    ${PROJECT_NAME}
  SOURCES
    any_simple_type.cpp
    decimal.cpp
    double.cpp
    normalized_string.cpp
    string.cpp
    token.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::headers)