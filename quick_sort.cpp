#include <iostream>
using namespace std;

int partition(int arr[],int l,int h){
	int i=l;
	int j=h;
	int pivot=arr[l];
	
	while(i<j){
		do{
			i++;
		}while(arr[i]<=pivot);
		
			j--;
		}while(arr[j]>pivot);
		if(i<j){
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	
	int temp2;
	temp2=arr[j];
	arr[j]=arr[l];
	arr[l]=temp2;
	
	return j;
	
}

void quicksort(int arr[],int l,int h){
	if(l<h){
		int j=partition(arr,l,h);
		quicksort(arr,l,j);
		quicksort(arr,j+1,h);
	}
}

int main(){
	int n;
	cout<<"Enter the number of elements :"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in the array:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<" \n      Array:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	quicksort(arr,0,n);
		cout<<" \nSorted Array:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
