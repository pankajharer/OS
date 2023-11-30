#include<iostream>
#include<algorithm>
using namespace std;
struct process
{
   int at;
   int bt;
   int wt;
   int tat;
   int st;
   int ct;
};
bool comp(process a,process b)
{
	if(a.at<=b.at)
	return true;
	return false;
}
int main()
{
	int n=4;

	process p[n];
	int at[n]={0,1,5,6};
	int bt[n]={2,2,3,4};
	for(int i=0;i<n;i++)
	{	p[i].at=at[i];
		p[i].bt=bt[i];
	}	
	sort(p,p+n,comp);  
	
int currtime=0;
int i=0;
while(i!=n)
{
	if(currtime<p[i].at)   
	currtime+=1;
	else
	{
		p[i].st=currtime;   
		currtime+=p[i].bt;
		p[i].ct=currtime;    
		p[i].tat=p[i].ct-p[i].at;    
		p[i].wt=p[i].tat-p[i].bt;     
		i++;	
	}
}
	
	cout<<"Process\tAT\tBT\tWT\tTAT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i<<"     \t"<<p[i].at<<" \t"<<p[i].bt<<" \t"<<p[i].wt<<" \t"<<p[i].tat<<endl;
	}
	
	float avgwt,avgtat;
	for(int i=0;i<n;i++)
	{
		avgwt+=p[i].wt;
		avgtat+=p[i].tat;
	}
	
	cout<<"Averge waiting time is: "<<avgwt/n<<endl;
	cout<<"Averge turnaround time is: "<<avgtat/n<<endl;
	
}

