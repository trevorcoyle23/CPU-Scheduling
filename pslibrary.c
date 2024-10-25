#define READY 0
#define RUNNING 1
#define WAITING 2
#define DONE 3

static char stateChars[] = {'r','R','w','\0'};

void fcfs(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
	int i;
	int state1 = READY, state2 = READY;
	int cpuLeft1 = x1, cpuLeft2 = x2;
	int ioLeft1 = y1, ioLeft2 = y2;

	for (i = 0;(state1 != DONE || state2 != DONE); i++) {
		if (state1 == RUNNING && cpuLeft1 == 0) {
			if (ioLeft1 == 0) state1 = DONE;
			else state1 = WAITING;
		}
		if (state2 == RUNNING && cpuLeft2 == 0) {
			if (ioLeft2 == 0) state2 = DONE;
			else state2 = WAITING;
		}

		if (state1 == WAITING && ioLeft1 == 0) {
			state1 = READY;
			cpuLeft1 = z1;
		}
		if (state2 == WAITING && ioLeft2 == 0) {
			state2 = READY;
			cpuLeft2 = z2;
		}

		if (state1 == READY && state2 == READY) state1 = RUNNING;
		else if (state1 == READY && state2 != RUNNING) state1 = RUNNING;
		else if (state2 == READY && state1 != RUNNING) state2 = RUNNING;

		if (state1 != DONE) s1[i] = stateChars[state1];
		if (state2 != DONE) s2[i] = stateChars[state2];

		if (state1 == RUNNING) cpuLeft1--;
		if (state1 == WAITING) ioLeft1--;
		if (state2 == RUNNING) cpuLeft2--;
		if (state2 == WAITING) ioLeft2--;
	}
}

void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
	int i;
	int state1 = READY, state2 = READY;
	int cpuLeft1 = x1, cpuLeft2 = x2;
	int ioLeft1 = y1, ioLeft2 = y2;

	for (i = 0; (state1 != DONE || state2 != DONE); i++) {
		
		if (state1 == RUNNING && cpuLeft1 == 0) {
			if (ioLeft1 == 0) state1 = DONE;
			else state1 = WAITING;
		}

		if (state2 == RUNNING && cpuLeft2 == 0) {
			if (ioLeft2 == 0) state2 = DONE;
			else state2 = WAITING;
		}

		if (state1 == WAITING && ioLeft1 == 0) {
			state1 = READY;
			cpuLeft1 = z1;
		}

		if (state2 == WAITING && ioLeft2 == 0) {
			state2 = READY;
			cpuLeft2 = z2;
		}
		
		if (state1 == READY && state2 == READY) {
			if (cpuLeft1 <= cpuLeft2) state1 = RUNNING;
			else state2 = RUNNING;
		} else if (state1 == READY && state2 != RUNNING) state1 = RUNNING;
                else if (state2 == READY && state1 != RUNNING) state2 = RUNNING;

		if (state1 != DONE) s1[i] = stateChars[state1];
		if (state2 != DONE) s2[i] = stateChars[state2];

		if (state1 == RUNNING) cpuLeft1--;
		if (state1 == WAITING) ioLeft1--;
		if (state2 == RUNNING) cpuLeft2--;
		if (state2 == WAITING) ioLeft2--;
	}
}

void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
	int i = 0;
	int state1 = READY, state2 = READY;
	int cpuLeft1 = x1, cpuLeft2 = x2;
	int ioLeft1 = y1, ioLeft2 = y2;
	int cpu2Left1 = z1, cpu2Left2 = z2;

	while ((state1 != DONE || state2 != DONE)) {
		if (state1 == RUNNING && cpuLeft1 == 0) {
			if (ioLeft1 == 0 && cpu2Left1 == 0) state1 = DONE;
			else if (ioLeft1 > 0) state1 = WAITING;
			else state1 = READY;	
		}

		if (state2 == RUNNING && cpuLeft2 == 0) {
			if (ioLeft2 == 0 && cpu2Left2 == 0) state2 = DONE;
			else if (ioLeft2 > 0) state2 = WAITING;
			else state2 = READY;
		}

		if (state1 == WAITING && ioLeft1 == 0) {
			state1 = READY;
			cpuLeft1 = cpu2Left1;
		}

		if (state2 == WAITING && ioLeft2 == 0) {
			state2 = READY;
			cpuLeft2 = cpu2Left2;
		}

		if (state1 == READY && state2 == READY) {
			if (cpuLeft1 <= cpuLeft2 && cpuLeft1 > 0) state1 = RUNNING;
			else if (cpuLeft2 > 0) state2 = RUNNING;
		} else if (state1 == READY && state2 != RUNNING && cpuLeft1 > 0) state1 = RUNNING;
		else if (state2 == READY && state1 != RUNNING && cpuLeft2 > 0) state2 = RUNNING;

		if (state1 == RUNNING && state2 == READY && cpuLeft2 <= cpuLeft1 && cpuLeft2 > 0) {
			state1 = READY;
			state2 = RUNNING;
		} else if (state2 == RUNNING && state1 == READY && cpuLeft1 <= cpuLeft2 && cpuLeft1 > 0) {
			state2 = READY;
			state1 = RUNNING;
		}
		
		if (state1 != DONE) s1[i] = stateChars[state1];
		if (state2 != DONE) s2[i] = stateChars[state2];

		i++;
		

		if (state1 == RUNNING && cpuLeft1 > 0) cpuLeft1--;
		if (state1 == WAITING && ioLeft1 > 0) ioLeft1--;
		if (state2 == RUNNING && cpuLeft2 > 0) cpuLeft2--;
		if (state2 == WAITING && ioLeft2 > 0) ioLeft2--;
	}
}

void rr(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2, int q) {
	int i = 0;
	int state1 = READY, state2 = READY;
	int cpuLeft1 = x1, cpuLeft2 = x2;
	int ioLeft1 = y1, ioLeft2 = y2;
	int cpu2Left1 = z1, cpu2Left2 = z2;
	int quantum = q;

	int max = 1000;
	int timeSlice1 = 0, timeSlice2 = 0;

	while ((state1 != DONE || state2 != DONE) && i < max) {
		if (state1 == RUNNING) {
			if (cpuLeft1 > 0) {
				timeSlice1 = (cpuLeft1 > quantum) ? quantum : cpuLeft1;
				cpuLeft1 -= timeSlice1;
				int t;
				for (t = 0; t < timeSlice1; t++) {
					if (i < max - 1) s1[i++] = stateChars[RUNNING];
				}
				if (cpuLeft1 == 0) {
					if (ioLeft1 > 0) state1 = WAITING;
					else if (cpu2Left1 > 0) state1 = READY;
					else state1 = DONE;
				}
			}
		}
	
		if (state2 == RUNNING) {
			if (cpuLeft1 > 0) {
				timeSlice2 = (cpuLeft2 > quantum) ? quantum : cpuLeft2;
				cpuLeft2 -= timeSlice2;
				int t;
				for (t = 0; t < timeSlice2; t++) {
					if (i < max - 1) s2[i++] = stateChars[RUNNING];
				}
				if (cpuLeft2 == 0) {
					if (ioLeft2 > 0) state2 = WAITING;
					else if (cpu2Left2 > 0) state2 = READY;
					else state2 = DONE;
				}
			}
		}

		if (state1 == WAITING && ioLeft1 > 0) {
			ioLeft1--;
			if (ioLeft1 == 0 && cpu2Left1 > 0) state1 = READY;
		}
		if (state2 == WAITING && ioLeft2 > 0) {
			ioLeft2--;
			if (ioLeft2 == 0 && cpu2Left2 > 0) state2 = READY;
		}

		if (state1 == READY && cpuLeft1 > 0) state1 = RUNNING;
		if (state2 == READY && cpuLeft2 > 0) state2 = RUNNING;
		
		if (state1 == DONE && state2 == DONE) break;
	}

	s1[i] = '\0';
	s2[i] = '\0';
}

int count_str(char *s) {
	int i = 0;
	while (s[i] != 0x00) i++;
	return i;
}

int x_time(char *s, char x) {
	int count = 0;
	int i = 0;
	while (s[i] != 0x00) {
		if (s[i] == x) count++;
		i++;
	}
	return count;
}

double cpu_util(char *s1, char *s2) {
	int slen1 = count_str(s1), slen2 = count_str(s2);
	int max;
	if (slen1 >= slen2) max = slen1;
	else max = slen2;
	int total_r = x_time(s1, 'R') + x_time(s2, 'R');
	return (double)total_r / (double)max;
}
