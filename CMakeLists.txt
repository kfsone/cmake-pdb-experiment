# CMake project for determining the rules on Windows for
# building stripped executables accompanied by their pdb
# files automatically.
#
# Expectation going in:
#  cmake -G "Visual Studio 2019" -S . -B ./build
#  cmake --build ./build --config Release
# should produce a binary without symbols and a pdb with symbols.

cmake_minimum_required (VERSION 3.17)

project (pdb-experiment LANGUAGES CXX)

set (TARGET_NAME my_program)


add_executable (
    ${TARGET_NAME}

    main.cpp
    impl.cpp
)

# This is MSVC specific, not WIN32...
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable debug symbol retention on Windows in Release builds, the compiler and
    # linker will automatically silo them into a .pdb file and not the executable.
    set (CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE}   /Zi")
    set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")

    # The linker needs to know to retain debug symbols.
    target_link_options (
        ${TARGET_NAME}
        PRIVATE $<$<CONFIG:RELEASE>:/INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF>
    )

    # Make sure that we're giving the pdb the right name and putting it in
    # the right place.
    set_target_properties (
        ${TARGET_NAME}
        PROPERTIES
            COMPILE_PDB_NAME       "${TARGET_NAME}"
            COMPILE_PDB_OUTPUT_DIR "$<TARGET_FILE_DIR:${TARGET_NAME}>"
    )
endif ()
