tnt_project_AddLibrary(${PROJECT_NAME}
  TARGET
    ${PROJECT_NAME}
  SOURCES
    string.cpp
    xsd.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::regex)