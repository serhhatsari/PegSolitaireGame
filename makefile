target:	pegsolitaire

main:	pegsolitaire.h main.cpp
		g++ -std=c++11 -c main.cpp	pegsolitaire.cpp

pegsolitaire:	main
		g++ -std=c++11 main.cpp	pegsolitaire.cpp -o pegsolitaire
clean:
		rm pegsolitaire *.o