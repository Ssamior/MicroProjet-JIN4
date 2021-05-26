# CMake generated Testfile for 
# Source directory: D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN
# Build directory: D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(that-test-I-made "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/out/build/x64-Debug/unitTests.exe")
set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;61;add_test;D:/01 - Documents/_Telecom 2eme annee/Informatique/Développement C++/MicroprojetJIN/CMakeLists.txt;0;")
subdirs("mainLauncher")
subdirs("src")
subdirs("googletest-build")
