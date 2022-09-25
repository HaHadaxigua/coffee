.PHONY: run clean

run: clean
	mkdir build
	cd build && cmake ..
	cd build && make
	cd build && ./coffee

clean:
	rm -rf build