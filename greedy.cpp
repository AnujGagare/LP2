#include <bits/stdc++.h>
using namespace std;

struct Job{

    int jobid;
    int deadline;
    int processing_tine;
    int profit;
};

bool compare(Job &job1,Job &job2){
    return (job1.deadline < job2.deadline);
}

pair<int,vector<Job>> jobScheduling(vector<Job>jobs){
    int n = jobs.size();
    int tot_profit = 0;
    int current = 0;

    sort(jobs.begin(),jobs.end(),compare);
    
    vector<Job>ans;

    for(auto job : jobs){
        if(current+job.processing_tine <= job.deadline){
            ans.push_back(job);
            current+=job.processing_tine;
            tot_profit+=job.profit;
        }
    }

    return {tot_profit,ans};

}

vector<int>selectionSort(vector<int>arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        int curr = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[curr]){
                curr = j;
            }
        }
        swap(arr[i],arr[curr]);
    }

    return arr;
}

void dijkstra(vector<vector<pair<int,int>>>& adj,vector<int>& ans,int stnode){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; //min-heap
    pq.push({0,stnode});  //pq is of the format {dist, node}
    ans[stnode] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto it : adj[node]){
            int node2 = it.first;
            int dis2 = it.second;

            if(dis+dis2 < ans[node2]){
                ans[node2] = dis+dis2;
                pq.push({dis+dis2,node2});
            }
        }

    }
    
    
}



int main(){
    //SELECTION SORT
    vector<int>arr ={8,5,4,6,2,1,7,3};

    vector<int>sortedArr = selectionSort(arr);

    for(int i=0;i<sortedArr.size();i++){
        cout<<sortedArr[i]<<" ";
    }
    cout<<endl;

    //JOB SCHEDULING
    //creating a vector to store elements of type Job
    vector<Job>jobs = {{11,5,4,20},{12,7,4,16},{13,9,5,16},{14,12,3,21},{15,14,10,29}};

    pair<int,vector<Job>>ans = jobScheduling(jobs);

    cout<<"Total profit : "<<ans.first<<endl;
    vector<Job>sch_jobs = ans.second;

    cout<<"Scheduled Jobs : "<<endl;

    //Using Job& job avoids copying and allows you to modify the actual elements in the vector if needed.
    for(Job& job : sch_jobs){
        cout<<"Job Id : "<<job.jobid<<"   Processing time: "<<job.processing_tine<<"   "<<"profit : "<<job.profit<<"   Deadline : "<<job.deadline<<endl;
    }

    //adj is of the format {neighbour, dist}
    vector<vector<pair<int,int>>>adj = {{{1,2},{2,3}},{{0,2},{2,4},{3,5}},{{0,3},{1,4},{4,5}},{{1,5},{4,6}},{{2,5},{3,6}}};
    vector<int>ans2(5,INT_MAX);
    dijkstra(adj,ans2,0); //works with any starting node
    for(int i=0;i<5;i++){
        cout<<"Shortest distance to node "<<i<<" : "<<ans2[i]<<endl;
    }


}