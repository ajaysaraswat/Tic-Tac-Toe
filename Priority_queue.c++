#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq, pq2;
    pq.push(15);
    pq.push(6);
    pq.push(21);
    pq2.push(16);
    pq2.push(19);
    pq2.push(12);
    cout << "size  of priority queue is " << pq.size() << endl;
    pq.swap(pq2);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }  

    return 0;
}
