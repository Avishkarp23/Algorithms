#include<iostream>
using namespace std;

int main(){
	
	int n,m;
	cout<<"Enter the no. of objects :- ";
	cin>>n;
	cout<<"Enter the max weight that sack can store :- ";
	cin>>m;
	int p[n],w[2][n];
	for(int i=0; i<n; i++){
    	cout<<"Enter the profit of obj "<<(i+1)<<"th";
		cin>>p[i];
		cout<<"Enter the weight of obj "<<(i+1)<<"th";
		cin>>w[0][i];
		w[1][i]=i+1;
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(w[0][j]>w[0][j+1]){
				int temp=w[0][j];
				w[0][j]=w[0][j+1];
				w[0][j+1]=temp;
				
				int temp1=w[1][j];
				w[1][j]=w[1][j+1];
				w[1][j+1]=temp1;
				
				int temp2=p[j];
				p[j]=p[j+1];
				p[j+1]=temp2;
			}
		}
	}
	
	int v[n+1][m+1];
	
    for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++)  {
		
			if(i==0 || j==0)   {
				v[i][j]=0;
			}
		
           else if(j<w[0][i-1])  {
           	v[i][j]=v[i-1][j];
		   }
		   
		   else{
		   	int x=j-w[0][i-1];
			v[i][j]=max(v[i-1][j],v[i-1][x]+p[i-1]);
		   }
			cout<<v[i][j]<<" ";
		}
			cout<<endl;
		}

	
	int max=v[n][m];
	int xi[n];
	int flag=0;
	for(int i=0;i<n;i++){
        xi[i]=0;
    }
	cout<<"\nMaximum Profit is :- ";
	
	cout<<max<<endl;
	
	int j=m;
	
	for(int i=n; i>=0; i--){
		if(j < 0 || max<=0){
			break;
		}
		
		if(v[i-1][j]!=max){
			
			int index=w[1][i-1]-1;
			xi[index]=1;
			
			max=max-p[i-1];
			j=j-w[0][i-1];
		}
	}
	cout<<"\nSelection of elements are :- ";
	for(int i=0; i<n; i++){
		cout<<xi[i]<<"\t";
	}
	return 0;
}