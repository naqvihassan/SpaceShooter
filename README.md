# SpaceShooter

Commands for compiling and running the sfml code
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app

////////////////////////////////--VS CODE--//////////////////////////////


g++ -c main.cpp -I"F:\Semester 2\SFML-2.5.1\include"
g++ main.o -o main -L"F:\Semester 2\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
./main
