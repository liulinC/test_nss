NSS_VERSION ?= 2
HCP_VERSION ?= 1.0.0
VERSION := $(NSS_VERSION).$(HCP_VERSION)
OBJ = libnss_hcp.so
OBJ_FULL_NAME := $(OBJ).$(VERSION)
SO_NAME := $(OBJ).$(NSS_VERSION)
LIB_PATH ?= /usr/lib64/
NSS_WINBIND := nss_winbind # Need libnss_winbind.so to link

# Refer to https://www.gnu.org/software/libc/manual/html_node/Adding-another-Service-to-NSS.html#Adding-another-Service-to-NSS

.PHONY: build clean install
build:
	gcc -shared  -fpic hcp_nss.c -o $(OBJ_FULL_NAME) -Wl,-soname,$(SO_NAME) -l$(NSS_WINBIND) -L$(LIB_PATH)

clean:
	rm -rf $(OBJ_FULL_NAME)

install:
	install -m 755 $(OBJ_FULL_NAME) $(LIB_PATH)
	rm -f $(LIB_PATH)$(SO_NAME) && ln -s $(LIB_PATH)$(OBJ_FULL_NAME) $(LIB_PATH)$(SO_NAME)
