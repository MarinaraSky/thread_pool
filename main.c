#include "threads.h"
#include <semaphore.h>
#include <stdio.h>

int main(void)
{
	t_pool *myPool = init_t_pool(8);
	for(uint64_t i = 0; i < 8; i++)
	{
		add_job(myPool->queue, i+1);
		sem_post(&myPool->mySem);
	}
	sleep(1);
	destroy_t_pool(myPool);
	return 0;
}
