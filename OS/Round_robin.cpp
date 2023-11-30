#include<iostream>
#include<algorithm>
#include<vector>
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
	int tq;
	cout<<"Enetr the time Quantum: ";
	cin>>tq;
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
	vector<int> rq;             //ready queue
	int running;          //process that is currently running
	int ready[n]={0};     //process is not in ready queue
	
	while(completed!=n)
	{
		running=i;
		if(p[i].rt==p[i].bt)       
	//checking if the running time is equal to the burst time
		p[i].st=currtime;
		
		if(tq>p[i].rt)    //2>1
		{
			currtime+=p[i].rt;
			p[i].rt=0;
		}
		else
		{
			p[i].rt=p[i].rt-tq;
			currtime+=tq;
		}
		
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
			
				if(p[j].at<=currtime && mark[j]==0 &&j!=running &&ready[j]==0)
				{
					rq.push_back(j);
					ready[j]=1;
				}
		}
		if(mark[running]==0)
		{
			rq.push_back(running);      
//process which has completed the TQ storing it back to the ready queue
			ready[running]=1;
		}
		if(completed==n)
		break;
		else
		{
			i=*rq.begin();        
			//storing the index of first process from ready queue
			ready[i]=0;
			rq.erase(rq.begin()); //moving out first process to running queue
		}	
		
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

//Enetr the time Quantum: 2
//Enter the no of process: 4
//Enter the arrival time for process P1 : 0
//Enter the burst time for process P1 : 5
//
//Enter the arrival time for process P2 : 1
//Enter the burst time for process P2 : 4
//
//Enter the arrival time for process P3 : 2
//Enter the burst time for process P3 : 2
//
//Enter the arrival time for process P4 : 4
//Enter the burst time for process P4 : 1
//
//Remaining time for process 0 is: 3
//Remaining time for process 1 is: 2
//Remaining time for process 2 is: 0
//Remaining time for process 0 is: 1
//Remaining time for process 3 is: 0
//Remaining time for process 1 is: 0
//Remaining time for process 0 is: 0
//Process AT      BT      WT      TAT
//P1      0       5       7       12
//P2      1       4       6       10
//P3      2       2       2       4
//P4      4       1       4       5
//Averge waiting time is: 4.75
//Averge turnaround time is: 7.75
