tnt_project_AddLibrary(${PROJECT_NAME}
  TARGET
    ${PROJECT_NAME}
  SOURCES
    xml.cpp
    xml_string.cpp
    xml_regex.cpp
    xs_any_simple_type.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Boost::headers
    LibXml2::LibXml2
)