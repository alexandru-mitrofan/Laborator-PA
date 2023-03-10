build:
	gcc Dijkstra.c -g -o dj -lm
	gcc BellmanFord.c -g -o bf -lm
	gcc Floyd-Warshall.c -g -o fw -lm

run-best:
	./bf

run-p1:
	./dj

run-p2:
	./fw

checker:
	python3 checkerBF.py --task 1 --algo best
	python3 checkerDJ.py --task 1 --algo p1
	python3 checkerFW.py --task 1 --algo p2

clean:
	rm dj
	rm bf
	rm fw