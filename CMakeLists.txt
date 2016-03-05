cmake_minimum_required(VERSION 3.3)
project(c_boy)

if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp arch/cpu.cpp arch/cpu.h arch/mmu.cpp
        arch/mmu.h arch/ops.cpp arch/ops.h arch/gpu.cpp
        arch/gpu.h arch/emu.cpp arch/emu.h windows/settings.cpp
        windows/settings.h imgui/imgui.cpp imgui/imgui.h imgui/imconfig.h
        imgui/imgui-events-SFML.h imgui/imgui-rendering-SFML.h
        imgui/imgui_internal.h imgui/stb_rect_pack.h imgui/stb_textedit.h
        imgui/stb_truetype.h imgui/imgui_draw.cpp imgui/imgui_demo.cpp
        jsoncpp/jsoncpp.cpp cppformat/format.cc cppformat/format.h
        arch/joy.cpp arch/joy.h arch/mbc/mbc.cpp arch/mbc/mbc.h
        arch/mbc/mbc2.cpp arch/mbc/mbc2.h arch/mbc/nombc.cpp
        arch/mbc/nombc.h arch/mbc/mbc1.cpp arch/mbc/mbc1.h windows/filedialog.cpp windows/filedialog.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if (MINGW)
    set(SFML_ROOT "./SFML")
endif()

find_package(SFML 2 REQUIRED graphics window network audio system)
find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
else()
    message(SEND_ERROR "SFML not found. Please set SFML_ROOT.")
endif()

if (MINGW)
    target_link_libraries(${PROJECT_NAME} winmm imm32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/SFML/bin/${CMAKE_BUILD_TYPE}"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()