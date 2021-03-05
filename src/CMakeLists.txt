tnt_project_AddLibrary(${PROJECT_NAME} INTERFACE TARGET ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# TODO: Try to make this private by moving implementation of any_simple_type to cpp file
target_link_libraries(${PROJECT_NAME} INTERFACE Boost::headers Boost::regex)