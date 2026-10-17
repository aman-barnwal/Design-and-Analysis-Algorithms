#include <stdio.h>
int partition(int a[], int p, int q)
{
int pivot=a[p];
int i = p;
for (int j = p + 1; j <= q; j++)
{
if (a[j]<=pivot)
{
i++;
// Swap a[i] and a[j]
int temp=a[i];
a[i]=a[j];
a[j];
a[j]=temp;
}
}

int temp=a[p];
a[p]=a[i];
a[i]=temp;

return i;
}

void quicksort(int a, int p, int q) {
if(p<q)
{
int m = partition(a, p, q);
quicksort(a, p, m-1);
quicksort(a, m+1, q);
}
}

int main() {
int a;
int a[9]={40, 70, 60, 55, 5, 80, 7, 90, 9};

printf("Original array:\n");
for (int i=0; i<9; i++) {

printf("%d", a[i]);
}

quicksort(a, 0, 8);

printf("\n\nSorted array: \n");
for(int i=0; i<9; i++) {
printf("%d", a[i]);
}
return 0;
}
