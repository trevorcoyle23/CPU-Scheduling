#ifndef PSLIBRARY_H
#define PSLIBRARY_H

void fcfs(char*, char*, int, int, int, int, int, int);
void sjf(char*, char*, int, int, int, int, int, int);
void psjf(char*, char*, int, int, int, int, int, int);
void rr(char*, char*, int, int, int, int, int, int, int);

int x_time(char*, char);
double cpu_util(char*, char*);
int count_str(char*);

#endif
