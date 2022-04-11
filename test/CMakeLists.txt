cmake_minimum_required(VERSION 3.14.4)

project(LiftKata_test)


add_executable(LiftKata_test main_test.cpp SchedulerTest.cpp RequestTest.cpp)




target_include_directories(${PROJECT_NAME}
                           PUBLIC ../googletest/googletest/include/gtest
                           PUBLIC ../googletest/googlemock/include/gtest
                           PUBLIC ../src
                           )


target_link_directories(${PROJECT_NAME}
                        PRIVATE ../googletest/googletest/src
                        PRIVATE ../googletest/googlemock/src
                        PRIVATE  ../src
                        )

target_link_libraries(${PROJECT_NAME} gtest_main gtest LiftKata_lib
                     )