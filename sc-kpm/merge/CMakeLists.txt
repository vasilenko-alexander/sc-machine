file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

add_library (merge SHARED ${SOURCES} ${HEADERS})


include_directories("${SC_KPM_ROOT}/merge" ${SC_MEMORY_SRC} ${GLIB2_INCLUDE_DIRS})
add_dependencies(merge sc-memory)

install_targets("/lib/sc-memory/extensions" merge)


