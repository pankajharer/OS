#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int frame_size;
int pages[N];
void lru_page_replacement()
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
 
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
 
        if(s.find(pages[i])!=s.end())
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
        else
        {
            if (s.size() < frame_size)
            {
                s.insert(pages[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (auto it : s)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
 
        }
        indexes[pages[i]] = i;
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
    lru_page_replacement();
    return 0;
}

