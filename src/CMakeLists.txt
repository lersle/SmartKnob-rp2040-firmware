add_executable(${ProjectName}
    WS2812.cpp
    configuration.cpp
    display_task.cpp
    interface_task.cpp
    main.cpp
    motor_task.cpp
    mt6701_sensor.cpp
    tlv_sensor.cpp
    util.cpp
    serial/crc32.cpp
    serial/serial_protocol_plaintext.cpp
    serial/serial_protocol_protobuf.cpp
    serial/uart_stream.cpp
    proto_gen/smartknob.pb.c
)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4
    hardware_pio
)

pico_add_extra_outputs(${ProjectName})