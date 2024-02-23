#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	int check;
	static int middle;
	static int lowest = 0;
	if((high - low) == 2){
		middle = (low + 1);
		return middle;
	}
	if((high - low) % 2 == 0){
		check = ((high - low) / 2) + low;
	}
	else{
		check = ((high - low + 1) / 2) + low;
		if(check < lowest){
			check = lowest + 2;
		}
	}
	if(high - low == 1){
		if(numbers[high] == value){
			return high;
		}
		else{
			return low;
		}
	}
	if(low > lowest){
		lowest = low;
	}
	if(numbers[check] == value){
		middle = check;
		return middle;
	}
	else{
		if(numbers[check] < value){
			middle = search(numbers,check, high, value);
		}
		else{
			middle = search(numbers, low, check, value);
		}
	}
	if(numbers[middle] == value){
		return middle;
	}
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}