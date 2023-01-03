#include <iostream>
using namespace std;
int main()
{
 int n;
 float prft=0;
 float W;
 float p=0;
 cout << "Enter the value of n : ";
 cin >> n;
 float profit[n];
 float weight[n];
 float p_w[n];
 float x[n];
 cout << "\nEnter the weight a bag can hold : ";
 cin >> W;
 int wt=W;
 for(int i=0;i<n;i++)
 {
 x[i]=0;
 }
 cout << "Enter profits : ";
 for(int i=0;i<n;i++)
 {
 cin >> profit[i];
 }
 cout << "Enter weights : ";
 for(int i=0;i<n;i++)
 {
 cin >> weight[i];
 }
 for(int i=0;i<n;i++)
 {
 p_w[i]=profit[i]/weight[i];
 }
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
 if(p_w[j]<p_w[j+1])
 {
 float temp=p_w[j];
 p_w[j]=p_w[j+1];
 p_w[j+1]=temp;
 float temp2=weight[j];
 weight[j]=weight[j+1];
 weight[j+1]=temp2;
 float temp3=profit[j];
 profit[j]=profit[j+1];
 profit[j+1]=temp3;
 }
 }
 }
 for(int i=0;i<n;i++)
 {
 if((wt-weight[i])>=0)
 {
 wt=wt-weight[i];
 p=p+weight[i];
 x[i]=x[i]+1;
 }
 else
 {
 x[i]=(W-p)/weight[i];
 wt=wt-weight[i]*x[i];
 p=p+weight[i]*x[i];
 }
 }
 cout << endl ;
 cout << "Profit : " ;
 for(int i=0;i<n;i++)
 {
 cout << profit[i] << "\t";
 }
 cout << endl << "Weight : ";
 for(int i=0;i<n;i++)
 {
 cout << weight[i] << "\t";
 }
 cout << endl << "Count : ";
 for(int i=0;i<n;i++)
 {
 cout << x[i] << "\t";
 }
 for(int i=0;i<n;i++)
 {
 prft =prft +(profit[i]*x[i]);
 }
 cout << endl ;
 cout << "Profit : " << prft << endl ;
 return 0;
}
