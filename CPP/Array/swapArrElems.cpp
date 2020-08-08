#include<iostream>
#include<vector>
using namespace std;
  
void swap(int* x, int* y) 
{ 
    int *z = x; 
    x = y; 
    y = z; 
} 
  
int main() 
{
	int arr[6] = {1,2,3,4,5,6};
	int i;
	for(i=0;i<=5;i+=2)
	{   
		swap(&arr[i], &arr[i+1]); 
	}

	cout<<"******After swapping*****"<<endl;
	for(i=0;i<=5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 
