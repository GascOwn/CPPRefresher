# CMakeList.txt : CMake project for CPPBjorneBook, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CPPBjorneBook "CPPBjorneBook.cpp" "CPPBjorneBook.h" "Vector.h" "Vector.cpp" "Node.h" "Node.cpp" "Container.h" "Container.cpp" "Shape.h" "Student.h" "Student.cpp"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPPBjorneBook PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
