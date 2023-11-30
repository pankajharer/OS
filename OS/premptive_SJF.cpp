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
   int st;
   int rt;
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
		p[i].rt=p[i].bt;
		p[i].st=0;
	}
	sort(p,p+n,comp);  //sorting the process acc to arrival time
	
	int completed=0;
	int currtime=0;        //previous completion time
	int i=0;     // for kepping track for next process to be executed
	int mark[n]={0};
		
	while(completed!=n)
	{
		int nrt=9999,index=-1;
		if(p[i].rt==p[i].bt)
		p[i].st=currtime;
		
		p[i].rt=p[i].rt-1;
		currtime+=1;
		cout<<"Remaining time for process "<<i<<" is: "<<p[i].rt<<endl;
		
		if(p[i].rt==0)          //if remaining time is zero
		{
			mark[i]=1;              //marking process as completed
			completed+=1;            //increasing no of completed process
			p[i].ct=currtime;          //completion time=currtime;
			p[i].tat=p[i].ct-p[i].at;
			p[i].wt=p[i].tat-p[i].bt;
		}
		
		for(int j=0;j<n;j++)
		{
			
				if(p[j].at<=currtime && mark[j]==0)
				{
					if(p[j].rt<nrt)    
					{
						nrt=p[j].rt;           //for identiying the process with min remainng time;
						index=j;
					}
					if(p[j].rt==nrt)
					{
						if(p[j].at<p[index].at)    
						{
							nrt=p[j].rt;                        
							index=j;
						}
						
					}
					
				}
			
		}
		nrt=9999;
		i=index;
		index=-1;
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
//Enter the arrival time for process P1 : 0
//Enter the burst time for process P1 : 5
//
//Enter the arrival time for process P2 : 1
//Enter the burst time for process P2 : 3
//
//Enter the arrival time for process P3 : 2
//Enter the burst time for process P3 : 4
//
//Enter the arrival time for process P4 : 4
//Enter the burst time for process P4 : 1
//
//Remaining time for process 0 is: 4
//Remaining time for process 1 is: 2
//Remaining time for process 1 is: 1
//Remaining time for process 1 is: 0
//Remaining time for process 3 is: 0
//Remaining time for process 0 is: 3
//Remaining time for process 0 is: 2
//Remaining time for process 0 is: 1
//Remaining time for process 0 is: 0
//Remaining time for process 2 is: 3
//Remaining time for process 2 is: 2
//Remaining time for process 2 is: 1
//Remaining time for process 2 is: 0
//Process AT      BT      WT      TAT
//P1      0       5       4       9
//P2      1       3       0       3
//P3      2       4       7       11
//P4      4       1       0       1
//Averge waiting time is: 2.75
//Averge turnaround time is: 6
