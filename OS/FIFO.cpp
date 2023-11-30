#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int frame_size;
int pages[N];
int mark[N];
void fifo_page_replacement(void)
{
    queue<int> Q;
    int page_faults=0;
    for(int i=0; i<n; i++)
    {
        if(mark[pages[i]]==true)
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
        else
        {
            Q.push(pages[i]);
            mark[pages[i]]=true;
            if(Q.size()>frame_size)
            {
                int p= Q.front();
                mark[p]=false;
                Q.pop();
            }
            page_faults++;
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults;
    return;
}
int main()
{
    cout<<"Number of Frames: ";
    cin>>frame_size; 
    cout<<"Page Reference Stream Length: ";
    cin>>n;
    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
    {
	
        cin>>pages[i];
    }
    fifo_page_replacement();
    return 0;
}
/*

Number of Frames: 3
Page Reference Stream Length: 20
Page Reference Stream:
7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
Reference to page 7 caused a page fault
Reference to page 2 caused a page fault
Reference to page 3 caused a page fault
Reference to page 1 caused a page fault
Reference to page 2 did not cause a page fault
Reference to page 5 caused a page fault
Reference to page 3 did not cause a page fault
Reference to page 4 caused a page fault
Reference to page 6 caused a page fault
Reference to page 7 caused a page fault
Reference to page 7 did not cause a page fault
Reference to page 1 caused a page fault
Reference to page 0 caused a page fault
Reference to page 5 caused a page fault
Reference to page 4 caused a page fault
Reference to page 6 caused a page fault
Reference to page 2 caused a page fault
Reference to page 3 caused a page fault
Reference to page 0 caused a page fault
Reference to page 1 caused a page fault

Total Page Faults: 17

*/
