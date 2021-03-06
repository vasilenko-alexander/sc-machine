TEMPLATE = lib
BINDIR = ../../bin
DESTDIR = $$quote($$BINDIR)/extensions

OBJECTS_DIR = obj
MOC_DIR = moc

INCLUDEPATH += ../../sc-memory/src

unix {
    LIBS += $$quote(-L$$BINDIR) -lsc_memory
    CONFIG += link_pkgconfig
    PKGCONFIG += glib-2.0
}

HEADERS += \
    search.h \
    search_agents.h \
    search_keynodes.h \
    search_utils.h \
    agents/search_output_arcs.h \
    agents/search_input_arcs.h \
    agents/search_semantic_neighborhood.h \
    agents/search_structure.h \
    agents/search_identifiers.h \
    search_defines.h \
    agents/search_pattern.h \
    agents/search_pattern/sc_system_operators.h \
    agents/search_pattern/sc_system_search.h \
    agents/search_pattern/search_pattern_functions.h

SOURCES += \
    search.c \
    search_keynodes.c \
    search_utils.c \
    agents/search_output_arcs.c \
    agents/search_input_arcs.c \
    agents/search_semantic_neighborhood.c \
    agents/search_structure.c \
    agents/search_identifiers.c \
    agents/search_pattern.c \
    agents/search_pattern/sc_system_search.cpp \
    agents/search_pattern/sc_system_operators.cpp \
    agents/search_pattern/search_pattern_functions.cpp
