GOOGLETEST_DIR = "../googletest"

GTEST_SRCDIR = "$$GOOGLETEST_DIR/googletest"
GMOCK_SRCDIR = "$$GOOGLETEST_DIR/googlemock"

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))

INCLUDEPATH *= \
    $$GTEST_SRCDIR \
    $$GTEST_SRCDIR/include \
    $$GMOCK_SRCDIR \
    $$GMOCK_SRCDIR/include

SOURCES += \
    $$GTEST_SRCDIR/src/gtest-all.cc \
    $$GMOCK_SRCDIR/src/gmock-all.cc
