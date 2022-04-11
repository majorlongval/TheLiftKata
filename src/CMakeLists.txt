project(LiftKata_main)

add_executable(${PROJECT_NAME} main.cpp)

add_library(LiftKata_lib Lift.cpp Scheduler.cpp Call.cpp Request.cpp)


