# CMake generated Testfile for 
# Source directory: C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation
# Build directory: C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(that-test-I-made "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/build/Debug/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;77;add_test;C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(that-test-I-made "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/build/Release/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;77;add_test;C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(that-test-I-made "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/build/MinSizeRel/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;77;add_test;C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(that-test-I-made "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/build/RelWithDebInfo/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;77;add_test;C:/Users/Lucas/Documents/Cours/C++/TP3/outil_visualisation/CMakeLists.txt;0;")
else()
  add_test(that-test-I-made NOT_AVAILABLE)
endif()
subdirs("_deps/sfml-build")
subdirs("_deps/pugixml-build")
subdirs("mainLauncher")
subdirs("src")
subdirs("googletest-build")
