#include<bits/stdc++.h>
using namespace std;
void delay()
{
	for(int i=0;i<1000;i++) {
		for(int j=1;j<1000;j++){}
}
}

int CustomerArrived(int chairs,int waiting)
{
	if(waiting<chairs)
	{
		cout<<"\nCustomer arrived in shop...\n";
		waiting+=1;
	}
	else
	{
		cout<<"\nNo chairs available to sit...\nCustomer left";
	}
	return waiting;
}

int main()
{
	int chairs,waiting,arrived;
	cout<<"\nEnter number of chairs: ";
	cin>>chairs;
	cout<<"\nEnter waiting: ";
	cin>>waiting;
	bool bsleep=false;
	while(1)
	{
		cout<<"\nCustomer arrived ? (1/0): ";
		cin>>arrived;
		if(arrived==1)
		{
			waiting=CustomerArrived(chairs,waiting);
		}
		if(waiting<0)
		{
			cout<<"\n\nNo customers available...\nBarber left the shop";
			break;
		}
		else if(waiting==0)
		{
			cout<<"\nNo customers waiting...\nBarber slept";
			bsleep=true;
		}
		else if(bsleep)
		{
			cout<<"\n\nWaking up barber...";
			bsleep=false;
		}
		if(!bsleep and waiting>0)
		{
			cout<<"\nCustomer is having haircut...";
			delay();
			cout<<"\nHaircut finished\n";
		}
		waiting--;
	}
	return 0;
}
/*

/tmp/bodbVS1Sz0.o
Enter number of chairs: 5
Enter waiting: 1
Customer arrived ? (1/0): 0
Customer is having haircut...
Haircut finished
Customer arrived ? (1/0): 0
No customers waiting...
Barber slept
Customer arrived ? (1/0): 1
Customer arrived in shop...

No customers waiting...
Barber slept
Customer arrived ? (1/0): 1
Customer arrived in shop...

No customers waiting...
Barber slept
Customer arrived ? (1/0): 0
No customers available...
Barber left the shop

*/
