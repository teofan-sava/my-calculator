.PHONY: default debug start_debug release clean install uninstall

MOC = /usr/lib/qt6/libexec/moc
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
LIBDIR = $(PREFIX)/lib

CXX = g++
CXX_FLAGS = -std=c++20
QT_CFLAGS := $(shell pkg-config --cflags Qt6Widgets)
QT_LIBS   := $(shell pkg-config --libs Qt6Widgets)

SOURCES = main.cpp Calculator.cpp MOC_Calculator.cpp

default: release

MOC_Calculator.cpp: Calculator.h
	$(MOC) Calculator.h -o MOC_Calculator.cpp

debug: main.cpp Calculator.cpp MOC_Calculator.cpp
	$(CXX) $(CXX_FLAGS) $(QT_CFLAGS) -g -O0 $(SOURCES) -o my-calculator_debug $(QT_LIBS)

start_debug:
	@if [ -f ./my-calculator_debug ]; then \
  			gdb ./my-calculator_debug; \
  	else \
  	  		exit 1; \
  	fi

release: main.cpp Calculator.cpp MOC_Calculator.cpp
	$(CXX) $(CXX_FLAGS) $(QT_CFLAGS) -O2 -s $(SOURCES) -o my-calculator_release $(QT_LIBS)

clean:
	rm -f *.o *.obj
	rm -f *.tmp *.temp
	rm -f *.bit *.bin
	rm -f MOC_Calculator.cpp
	rm -f my-calculator my-calculator_debug my-calculator_release

install: release
	install -d $(BINDIR)
	install -m 0644 my-calculator_release $(BINDIR)/

	#install -d $(LIBDIR)
	#install -m 0644 $(LIBDIR)/

uninstall:
	rm -f $(BINDIR)/my-calculator_release
