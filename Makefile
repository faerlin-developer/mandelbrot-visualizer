
prepare:
	rm -rf build
	mkdir build
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
