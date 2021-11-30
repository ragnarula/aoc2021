foreach(DAY RANGE 1 1)
    add_executable(day${DAY} 
        main.cpp
        day${DAY}.cpp
    )
    target_link_libraries(day${DAY} aoc-lib)
endforeach()

