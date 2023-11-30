#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int frame_size;
int pages[N];
void optimal_page_replacement()
{
    vector<int> fr;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        for (k = 0; k < fr.size(); k++)
            if (fr[k] == pages[i])
                break;
        if (k==fr.size())
        {
            if (fr.size() < frame_size)
                fr.push_back(pages[i]);
            else
            {
                int index=i+1;
                int res = -1, farthest = index;
                for (int l = 0; l < fr.size(); l++)
                {
                    int j;
                    for (j = index; j < n; j++)
                    {
                        if (fr[l] == pages[j])
                        {
                            if (j > farthest)
                            {
                                farthest = j;
                                res = l;
                            }
                            break;
                        }
                    }
                    if (j == n)
                    {
                        res=l;
                        break;
                    }
                }
                fr[res] = pages[i];
            }
            page_faults++;
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
        }
        else
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults;
}

int main()
{
    cout<<"Number of Frames: ";
    cin>>frame_size;
 
    cout<<"Page Reference Stream Length: ";
    cin>>n;
 
    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>pages[i];
    optimal_page_replacement();
    return 0;
}

/*
/tmp/wBgKfKm90j.o
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
Reference to page 1 did not cause a page fault
Reference to page 0 caused a page fault
Reference to page 5 did not cause a page fault
Reference to page 4 caused a page fault
Reference to page 6 caused a page fault
Reference to page 2 caused a page fault
Reference to page 3 caused a page fault
Reference to page 0 did not cause a page fault
Reference to page 1 did not cause a page fault

Total Page Faults: 13
*/
