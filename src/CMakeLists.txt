add_executable(${ProjectName}
    main.cpp
    WS2812.cpp
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