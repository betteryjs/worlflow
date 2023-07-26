cmake_minimum_required(VERSION 3.20)
project(Test)



add_executable(testhttp1 testhttp1.cpp)
add_executable(tutorial-01-wget tutorial-01-wget.cc)
add_executable(tutorial-02-redis_cli tutorial-02-redis_cli.cc)
add_executable(tutorial-03-wget_to_redis tutorial-03-wget_to_redis.cc)
add_executable(tutorial-04-http_echo_server tutorial-04-http_echo_server.cc)

target_link_libraries(testhttp1 workflow )
target_link_libraries(tutorial-01-wget workflow )
target_link_libraries(tutorial-02-redis_cli workflow )
target_link_libraries(tutorial-03-wget_to_redis workflow )
target_link_libraries(tutorial-04-http_echo_server workflow )



