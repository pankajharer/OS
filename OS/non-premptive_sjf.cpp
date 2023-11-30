#include<iostream>
#include<algorithm>
using namespace std;	
struct process
{
   int at;
   int bt;
   int wt;
   int tat;
   int pno;
   int ct;
};

bool comp(process a,process b)
{
	if(a.at<b.at)
	return true;
	if(a.at==b.at)
	{
		if(a.bt<=b.bt)
		return true;
	}
	return false;
}
int main()
{
	int n;
	cout<<"Enter the no of process: ";
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time for process P"<<i+1<<" : ";
		cin>>p[i].at;
		cout<<"Enter the burst time for process P"<<i+1<<" : ";
		cin>>p[i].bt;
		p[i].pno=i+1;
		cout<<endl;
	}
	
	sort(p,p+n,comp);  //sorting the process acc to arrival time
	int completed=0;
	int prev_ct=0;        
	//previous completion time same as taht of currtime
	int i=0,index=0,nbt=9999;      
	// for kepping track for next process to be executed
	int mark[n];
	while(completed!=n)
	{
		if(i==0)
		{
			p[i].ct=p[i].at+p[i].bt;
			p[i].tat=p[i].bt;
			p[i].wt=0;
		}
		else{
			p[i].ct=prev_ct+p[i].bt; 
			p[i].tat=p[i].ct-p[i].at;
			p[i].wt=p[i].tat-p[i].bt;        	
		}
		prev_ct=p[i].ct;    //3         //keeping track of precious completion time;
		mark[i]=1;                 //marking process as completed      
		for(int j=0;j<n;j++)
		{
			if(mark[j]!=1)               
			//checking if the process is not completed
			{
				if(p[j].at<prev_ct)           
				 //checking if process has arrived or not at given time
				{
					if(nbt>p[j].bt)
					{
						nbt=p[j].bt;            //next burst time;
						index=j;
					}
					
				}
			}
		}
		i=index;
		completed+=1;
		nbt=9999;
	}

	cout<<"Process\tAT\tBT\tWT\tTAT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<p[i].pno<<"     \t"<<p[i].at<<" \t"<<p[i].bt<<" \t"<<p[i].wt<<" \t"<<p[i].tat<<endl;
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

//Enter the no of process: 4
//Enter the arrival time for process P1 : 1
//Enter the burst time for process P1 : 3
//
//Enter the arrival time for process P2 : 2
//Enter the burst time for process P2 : 4
//
//Enter the arrival time for process P3 : 1
//Enter the burst time for process P3 : 2
//
//Enter the arrival time for process P4 : 4
//Enter the burst time for process P4 : 4
//
//Process AT      BT      WT      TAT
//P3      1       2       0       2
//P1      1       3       2       5
//P2      2       4       4       8
//P4      4       4       6       10
//Averge waiting time is: 3
//Averge turnaround time is: 6.25

