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
   int prio;
};

bool comp(process a,process b)
{
	if(a.at<b.at)
	return true;
	if(a.at==b.at)
	{
		if(a.prio>=b.prio)                      
		//just change the sign > to < in case of   1 2 3 4  highest=1;
		return true;
	}
	return false;
}
int main()
{
	int n=4;
	cout<<"Enter the no of process: ";
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the Priority for process P"<<i+1<<" : ";
		cin>>p[i].prio;
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
		int prt=0,index=-1;  //prt is priority
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
					if(p[j].prio>prt)               
//10 20 30 40    highest=40;      //1 2 3 4  highest=1; 
//just change the > sign to <  assign value of prt=9999;
					{
						prt=p[j].prio;            
	//for selecting the process with the highest priority
						index=j;
					}
					
				}
			
		}
		prt=0;
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
//Enter the Priority for process P1 : 10
//Enter the arrival time for process P1 : 0
//Enter the burst time for process P1 : 5
//
//Enter the Priority for process P2 : 20
//Enter the arrival time for process P2 : 1
//Enter the burst time for process P2 : 4
//
//Enter the Priority for process P3 : 30
//Enter the arrival time for process P3 : 2
//Enter the burst time for process P3 : 2
//
//Enter the Priority for process P4 : 40
//Enter the arrival time for process P4 : 4
//Enter the burst time for process P4 : 1
//
//Remaining time for process 0 is: 4
//Remaining time for process 1 is: 3
//Remaining time for process 2 is: 1
//Remaining time for process 2 is: 0
//Remaining time for process 3 is: 0
//Remaining time for process 1 is: 2
//Remaining time for process 1 is: 1
//Remaining time for process 1 is: 0
//Remaining time for process 0 is: 3
//Remaining time for process 0 is: 2
//Remaining time for process 0 is: 1
//Remaining time for process 0 is: 0
//Process AT      BT      WT      TAT
//P1      0       5       7       12
//P2      1       4       3       7
//P3      2       2       0       2
//P4      4       1       0       1
//Averge waiting time is: 2.5
//Averge turnaround time is: 5.5
