/*
	CS 342 OPERATING SYSTEMS
	BERK TÜRK 21302570
	MEHMET EGE ACICAN 21602186
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "memalloc.h"
#include "memalloc.c"
#include<time.h>

void * worker_thread(void *arg){
		void *y1;
		void *y2;
		void *y3;
		printf("THREAD\n");
		y1 = mem_allocate(130);
		y2 = mem_allocate(140);
		y3 = mem_allocate(150);
		mem_free(y2);
		//y4 = mem_allocate(160);
		//y5 = mem_allocate(140);
		//mem_free(y3);
		//y6 = mem_allocate(30);
		//mem_free(y1);

		
	}//END OF WORKER_THREAD

int	main(int argc,char *argv[])
{
	clock_t t;
    t = clock();
	void *chunkptr;
	void *endptr;
	char *charptr;
	int	ret;
	int	i;
	int	size;
	

	if (argc != 2)	{
		printf("usage: app <size in	KB>\n");
		exit(1);
	}

	size = atoi(argv[1]);//unit	is in KB

	if(size<32||size>32768){
		printf("Chunk size must be between 32 kbytes and 32 mbytes!\n");
		return -1;
	}

	//allocate a chunk
	chunkptr = sbrk(0); //end of data segment
	sbrk(size *	1024); //extend	data segment by	indicated amount (bytes)
	endptr = sbrk(0); //new	end	of data	segment
	printf("chunkstart=%lx,	chunkend=%lx, chunksize=%lu	bytes\n",
								(unsigned long)chunkptr,
								(unsigned long)endptr, (unsigned long)(endptr - chunkptr));
	//test the chunk	
	printf("---starting	testing	chunk\n");
	charptr	= (char	*)chunkptr;
	
	for	(i = 0;	i <	size; ++i)
		charptr[i] = 0;
		printf("---chunk test ended	- success\n");
		ret	= mem_init(chunkptr, size, 0);
	if (ret == -1) {
		printf("could not initialize \n");
		exit(1);
	}
	//below we allocate and deallocate memory dynamically
	//x1 = mem_allocate(400);
	//mem_print();
	//x2 = mem_allocate(200);
	//mem_print();
	//x3 = mem_allocate(300);
	//mem_print();
	//x4 = mem_allocate(800);
	//x5 = mem_allocate(700);
	//mem_print();
	//mem_print();

	
	//mem_free(x3);
	//mem_print();
	//x6 = mem_allocate(150);
	//mem_free(x1);
	//mem_print();
	pthread_t pids[5]; // producer tids
    //pthread_t mid;

    // create worker threadss
	for (int i = 0; i < 4; ++i){
		ret = pthread_create(&pids[i], NULL, worker_thread, NULL);
		if (ret < 0){
			perror("thread create failed\n");
			exit(1);
		}
	}
	// wait for the producer threads to terminateb
	for (int i = 0; i < 4; ++i)
		pthread_join(pids[i], NULL);

	mem_print();

	t = clock() -t;
    double time_taken = ((double) t)/CLOCKS_PER_SEC;
    printf("Time Taken : %f\n",time_taken);

	return 0;
}