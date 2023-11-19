#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//dizi elemanlarını küçükten büyüğe sıralıyor.
int siralama(const void *a , const void *b){
return (*(int*)a - *(int*)b);
}

//medyan hesaplama 
void MovingMedian(int arr[], int arrLength) {
  int i , j;

  int windowSize = arr[0];


  for(i=1 ; i <= arrLength-windowSize; i++) {
   

   int window[windowSize];

   for (j=0 ; j<=windowSize ; j++){

     window[j]=arr[i+j];
   }

   qsort(window,windowSize, sizeof(int),siralama);

   printf("%d",window[windowSize / 2]);

   if(i < arrLength- windowSize){

     printf(",");
   }
}
printf("\n");
}

int main(void) { 
   
 int arrLength , i;

 printf("Dizi eleman sayisıni giriniz:");
 scanf("%d",&arrLength);

 int *arr= (int* )malloc((arrLength+1)* sizeof(int));

 if(arr == NULL){

   printf("Geçersiz işlem");
   return 1;

 }

 printf("Dizi elemanlarını giriniz:\n");
 for(i=0 ; i < arrLength ; i++){
 scanf("%d",&arr[i]);
}

if(arrLength <= arr[0]){

  printf("Ilk eleman dizi uzulugundan kucuk olmak zorundadır.");
}
MovingMedian(arr, arrLength);

free(arr);
  return 0;
    
}