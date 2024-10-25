#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"

int main(int argc, char ** argv) {
	int i;
	if (argc != 8) {
		printf("wrong args|usage: ./assign2 q x1 y1 z1 x2 y2 z2\n");
		return 1;
	}

	printf("CS 3733 | Assignment 2 | written by TREVOR COYLE | uhx746\n");
	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");

	int q = atoi(argv[1]);
	int x1 = atoi(argv[2]);
	int y1 = atoi(argv[3]);
	int z1 = atoi(argv[4]);
	int x2 = atoi(argv[5]);
	int y2 = atoi(argv[6]);
	int z2 = atoi(argv[7]);

	char s1[1000] = {0}, s2[1000] = {0};

	printf("\nScheduler FCFS:\n");
	fcfs(s1, s2, x1, y1, z1, x2, y2, z2);
	printf("%s\n%s\n", s1, s2);
	printf("%d %d %.1f %.5f\n", x_time(s1, 'r'), x_time(s2, 'r'), (x_time(s1, 'r') + x_time(s2, 'r')) / 2.0, cpu_util(s1, s2));

	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));

	printf("\nScheduler SJF:\n");
	sjf(s1, s2, x1, y1, z1, x2, y2, z2);
	printf("%s\n%s\n", s1, s2);
	printf("%d %d %.1f %.5f\n", x_time(s1, 'r'), x_time(s2, 'r'), (x_time(s1, 'r') + x_time(s2, 'r')) / 2.0, cpu_util(s1, s2));

	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	
	/* DOESN'T WORK LOL :*(

	printf("\nScheduler PSJF:\n");
	psjf(s1, s2, x1, y1, z1, x2, y2, z2);
	printf("%s\n%s\n", s1, s2);
	printf("%d %d %.1f %.5f\n", x_time(s1, 'r'), x_time(s2, 'r'), (x_time(s1, 'r') + x_time(s2, 'r')) / 2.0, cpu_util(s1, s2));

	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	*/

	/* DOESN'T WORK LOL :*(

	printf("\nScheduler RR:\n");
	if (q > 0) {	
		rr(s1, s2, x1, y1, z1, x2, y2, z2, q);
		printf("%s\n%s\n", s1, s2);
		printf("%d %d %.1f %.5f\n", x_time(s1, 'r'), x_time(s2, 'r'), (x_time(s1, 'r') + x_time(s2, 'r')) / 2.0, cpu_util(s1, s2));
		
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
	} else {
		printf("Enter a positive, non-zero integer for 'q' parameter\n");
	}
	*/
	
	return 0;
}
