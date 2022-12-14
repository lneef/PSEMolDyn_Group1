# make doc_doxygen optional if someone does not have / like doxygen

# CMake build option for the target.
option(DISABLE_DOXYGEN "Disable creation of doxygen target" OFF)

# custom target for building the documentation.
if(NOT DISABLE_DOXYGEN)
    add_custom_target(doc_doxygen
    COMMAND doxygen ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
    VERBATIM
)
endif()
