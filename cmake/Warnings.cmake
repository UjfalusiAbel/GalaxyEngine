function(set_compiler_warnings TARGET ENABLED_AS_ERRORS)
    set(GCC_WARNINGS -Wall -Wextra)
    set(CLANG_WARNINGS ${GCC_WARNINGS})
    set(MSVC_WARNINGS /W4 /permissive-)

    if(${ENABLED_AS_ERRORS})
        set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
        set(CLANG_WARNINGS ${GCC_WARNINGS})
        set(MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
    endif()

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(WARNINGS ${GCC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(WARNINGS ${MSVC_WARNINGS})
    else()
        message(ERROR "Unsupported compiler. Please use GCC, Clang or MSVC")
    endif()

    target_compile_options(${TARGET} PRIVATE ${WARNINGS})
    message(STATUS ${WARNINGS})

endfunction()
