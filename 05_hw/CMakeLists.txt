cmake_minimum_required(VERSION 3.10)
project(stack)

# Включаем clang-tidy, если он найден
find_program(CLANG_TIDY clang-tidy)
if(CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY};-checks=-*,clang-analyzer-*")
    message(STATUS "clang-tidy found: ${CLANG_TIDY}")
else()
    message(STATUS "clang-tidy not found, skipping.")
endif()

# Включаем санитайзеры для Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,memory")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,memory")
    message(STATUS "Sanitizers enabled")
endif()

# Добавляем библиотеку stack
add_library(stack stack.c)

# Добавляем исполнимые файлы
add_executable(Test test.c benchmark.c)
target_link_libraries(Test stack)

add_executable(main main.c)
target_link_libraries(main stack)

# Добавляем возможность установки бинарников
install(TARGETS main Test stack
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
