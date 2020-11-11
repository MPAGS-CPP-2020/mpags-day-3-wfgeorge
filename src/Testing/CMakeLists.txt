# - Build sub-script for the MPAGSCipher library unit tests

# - Simple HelloWorld tests
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# - Create Interface library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# - First Catch test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

# - transformChar test
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)