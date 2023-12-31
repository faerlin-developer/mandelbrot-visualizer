
prepare:
	rm -rf build
	mkdir build
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	cd build && make

run:
	cd build && ./mandelbrot-visualizer

clean:
	rm -rf build