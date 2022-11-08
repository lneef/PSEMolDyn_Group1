include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850
  )

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ParticleContainer_Test
  ParticleContainer_Test.cc
)


add_library(Particle ../src/ParticleContainer.cpp ../src/Particle.cpp)

target_include_directories(ParticleContainer_Test
    PRIVATE
   ../ src/
)
target_link_libraries(ParticleContainer_Test
    GTest::gtest_main
    Particle
)

include(GoogleTest)

gtest_discover_tests(ParticleContainer_Test)
