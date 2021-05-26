# CMake generated Testfile for 
# Source directory: D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN
# Build directory: D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(that-test-I-made "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/build/Debug/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;61;add_test;D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(that-test-I-made "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/build/Release/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;61;add_test;D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(that-test-I-made "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/build/MinSizeRel/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;61;add_test;D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(that-test-I-made "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/build/RelWithDebInfo/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;61;add_test;D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;0;")
else()
  add_test(that-test-I-made NOT_AVAILABLE)
endif()
subdirs("mainLauncher")
subdirs("src")
subdirs("googletest-build")
