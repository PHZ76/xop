add_executable(test_echo_server test_echo_server.cpp)
target_link_libraries(test_echo_server ${CMAKE_PROJECT_NAME}_static pthread)

add_executable(test_timer_event test_timer_event.cpp)
target_link_libraries(test_timer_event ${CMAKE_PROJECT_NAME}_static pthread)

add_executable(test_logger test_logger.cpp)
target_link_libraries(test_logger ${CMAKE_PROJECT_NAME}_static pthread)

add_executable(test_task_scheduler test_task_scheduler.cpp)
target_link_libraries(test_task_scheduler ${CMAKE_PROJECT_NAME}_static pthread)

add_executable(test_ringbuffer test_ringbuffer.cpp)
target_link_libraries(test_ringbuffer ${CMAKE_PROJECT_NAME}_static pthread)

