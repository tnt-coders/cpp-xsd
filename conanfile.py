from conans import ConanFile, CMake, tools

class CppXsd(ConanFile):
    name = "xsd"
    description = "C++ mappings for XML Schema data types for XML schema built-in datatypes"
    homepage = "https://tnt-coders.github.io/"
    url = "https://github.com/tnt-coders/cpp-xsd"
    license = "GNU Lesser General Public License v3.0"
    author = "TNT Coders <tnt-coders@googlegroups.com>"

    topics = ("xsd")

    settings = ("os", "compiler", "build_type", "arch")

    options = {
        "shared": [True, False],
    }

    default_options = {
        "shared": False,
    }

    build_requires = (
        "boost/1.75.0",
        "catch2/3.0.0-1@tnt-coders/stable",
        "math/1.0.0@tnt-coders/stable"
    )

    exports_sources = ("CMakeLists.txt", "docs/*", "include/*", "src/*", "test/*")
    
    generators = ("cmake", "cmake_find_package", "cmake_paths")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def configure(self):
        tools.check_min_cppstd(self, "17")

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)