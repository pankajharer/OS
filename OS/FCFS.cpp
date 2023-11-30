#include <iostream>
using namespace std;

int FCFS()
{
	int Pcount;
	
	cout<<"Enter How many Processes You want to Enter:";
	cin>>Pcount;
	
	int PBT[Pcount];
	
	for(int i=0;i<Pcount;i++)
	{
		cout<<"\nEnter Burst Time of Process P"<<i<<":";
		cin>>PBT[i];
	}
	
	int WT[Pcount]={0};
	int wt=0;
	
	for(int i=1;i<Pcount;i++)
	{
		wt= wt + PBT[i-1];
		WT[i]=wt;
	}
	
	int TAT[Pcount];
	
	for(int i=0;i<Pcount;i++)
	{
	   TAT[i]=PBT[i]+WT[i];	
	}
	
	cout<<"\n   |    Process   |    BT      |     WT      |      TAT     |";

	for(int i=0;i<Pcount;i++)
	{
	cout<<"\n   |     P"<<i<<"       |    "<<PBT[i]<<"       |     "<<WT[i]<<"      |      "<<TAT[i]<<"     |";

	}
	
	return 0;
}

int main()
{
	
	FCFS();	
	return 0;
	
}
