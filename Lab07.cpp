#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *do_the_thing( void *ptr );

main(int argc, char *argv[]){
	if (argc == 1)
    {
		cout << "GENERIC ERROR MESSAGE, BECAUSE YOUR ERROR DOESN'T MERIT THE EFFORT OF A SPECIFIC ONE." << endl;
    }
  else
    {
		int i = 0;
    	int n = argc;
		int *index = NULL;
		pthread_t* ptr = NULL;  
		int* arr = NULL;
		arr = new int[n];
		
		
        for(i = 0; i < n; i++)
        {
                arr[i] = i;
        }
		
		ptr = malloc(sizeof(pthread_t)*n);
			for(i = 0; i < n; i++)
			{
				pthread_create(&ptr[i], NULL, do_the_thing, (void*)&arr[i]);
			}
			for(i = 0; i < n; i++){
				pthread_join(ptr[j], NULL);
			}
	}
	return 0;
}

void *do_the_thing( void *ind )
{
	int tmp;
	int *num;
	num = *((int*)ind);
	if(num % 2){
		tmp = arr[num];
		arr[num] = arr[num] * arr[num] * arr[num];
		cout <<  tmp << " has been replaced with " << arr[num] << endl;
	}
	else{
		tmp = arr[num];
		arr[num] *= -1;
		cout <<  tmp << " has been replaced with " << arr[num] << endl;
	}
}
