.PHONY: build
build:
	gcc -shared  -fpic hcp_nss.c -o nss_hcp.so.2 -lnss_winbind -L/usr/lib
clean:
	rm -rf *.so
install:
	cp libnss_hcp.so.2 /usr/lib64/
	rm -f /usr/lib64/libnss_hcp.so && ln -s /usr/lib64/libnss_hcp.so.2 /usr/lib64/libnss_hcp.so
