aux_source_directory(. DIR_TEST_SRCS)

ADD_SUBDIRECTORY(src/A)

INCLUDE_DIRECTORIES(./src/A)


ADD_EXECUTABLE(test ${DIR_TEST_SRCS})

TARGET_LINK_LIBRARIES(test A)