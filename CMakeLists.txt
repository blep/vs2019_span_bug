cmake_minimum_required(VERSION 3.12)

project( Vs2019_Span_Bug )

# Output all libraries and executables in the same directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all libraries.")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all executables.")
mark_as_advanced( LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH ) 

enable_testing()

if (NOT DEFINED MAX_STANDARD_VERSION)
    set(MAX_STANDARD_VERSION 17) # 98, 11, 14, 17
endif()

if ( MSVC )
    # Force parallel compilation
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP4")
    # Warning level 4 and as error
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /W4")
    # nicer error diagnostic
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /diagnostics:caret")
endif( MSVC )

# Not that the bug only occur in Release mode
add_executable(vs2019_span_bug main.cpp)
