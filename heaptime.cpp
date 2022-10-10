#include <stdio.h>
#include<time.h>
#include<stdlib.h>
  void swap(int *a, int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
 	void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  	if (left < n && arr[left] > arr[largest])
      largest = left;
  	if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  void buildmaxheap(int arr[],int n)
  {
  	for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  	
  }
  void heapSort(int arr[], int n) {
     buildmaxheap(arr,n);
     for (int i = n - 1; i >= 0; i--) 
	 {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}    
  int main()
 {
  	int n,i;
  	  clock_t begin, end;
  	printf("enter the size of an array\n");
  	scanf("%d",&n);
  	//for best case
  	int arr[n];
  	for(i=0;i<n;i++)
  	arr[i]=i+1;
  	begin = clock();
    heapSort(arr,n);
    end=clock();
    double time1 = ((double)end-begin) / CLOCKS_PER_SEC;
   	printf("After sorting the array using heap sorting the time taken:\n In best case:%f\n",time1);
  	//for avg case
    FILE *ptr;
    srand(time(NULL));
    ptr = fopen("yui.txt","r");
    arr[n]={0};
    for (i=0; i<n; i++)
        fscanf(ptr, "%d", &arr[i]);
    begin = clock();
    heapSort(arr,n);
    end=clock();
    double time2 = ((double)end-begin) / CLOCKS_PER_SEC;
   	printf("After sorting the array using heap sorting the time taken\n In average case:%f\n",time2);
   	fclose(ptr);
   	 	//for best case
  	arr[n]={0};
  	for(i=0;i<n;i++)
  	arr[i]=n-i;
  	begin = clock();
    heapSort(arr,n);
    end=clock();
    double time3 = ((double)end-begin) / CLOCKS_PER_SEC;
   	printf("After sorting the array using heap sorting the time taken:\n In worst case:%f",time3);
   	
  }
