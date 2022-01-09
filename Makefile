build: src/main.cpp
	g++ -o build/main.exe src/main.cpp

run:
	cd build && main.exe