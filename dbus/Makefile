
CC=gcc
CFLAGS=-Wall -Wextra

pkg_packages := glib-2.0 gio-2.0

PKG_CFLAGS  := $(shell pkg-config --cflags $(pkg_packages))
PKG_LDFLAGS := $(shell pkg-config --libs $(pkg_packages))
ADD_CFLAGS := -g -Wall -Wextra

CFLAGS  := $(PKG_CFLAGS) $(ADD_CFLAGS) $(CFLAGS)
LDFLAGS := $(PKG_LDFLAGS) $(LDFLAGS)

targets = read_prop

.PHONY: all clean
all: $(targets)

read_prop: read_prop.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	$(RM) $(targets)
