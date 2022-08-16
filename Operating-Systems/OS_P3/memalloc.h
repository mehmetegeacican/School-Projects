/*
	CS 342 OPERATING SYSTEMS
	BERK TÜRK 21302570
	MEHMET EGE ACICAN 21602186
*/
#ifndef MEMALLOC_H
#define MEMALLOC_H
#define FIRST_FIT 0
#define BEST_FIT 1
#define WORST_FIT 2

int mem_init(void *, int, int);
void *mem_allocate(int);
void mem_free(void *);
void mem_print (void);
#endif