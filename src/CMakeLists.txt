set(SOURCES
        "screen.cpp"
        "mandelbrot.cpp"
        "fractal.cpp"
        "buffer.cpp"
        "transformer.cpp"
        "julia.cpp"
        "event.cpp")

add_library(${LOCAL_LIBRARY} STATIC ${SOURCES})
target_link_libraries(${LOCAL_LIBRARY} ${SDL2_LIBRARIES})