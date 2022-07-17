all:
	g++ main.cpp -o tp3
	./tp3 < in1.txt in1.txt
	./tp3 < in2.txt in2.txt
	./tp3 < in3.txt in3.txt
	./tp3 < in4.txt in4.txt



clean:
	rm tp3.o 