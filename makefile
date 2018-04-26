wave.png: gra.py onda.txt
	python gra.py
onda.txt:
	./ondas > onda.txt
ondas: ejercicio23.cpp
c++ ejercicio23.cpp -o ondas
