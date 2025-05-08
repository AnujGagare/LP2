#include<bits/stdc++.h>
using namespace std;

const int n = 3;
struct puzzlestate{
    int puzzle[n][n];
    int zrow;
    int zcol;
    int g;
    int h;

    bool operator<(const puzzlestate &other)const{
        return((g+h)>(other.g+other.h));
    }
};

int calculateManhattanDistance(const puzzlestate &curr){
    int distance = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val = curr.puzzle[i][j];

            if(val!=0){
                int targetrow = (val-1)/n;
                int targetcol = (val-1)%n;

                distance += abs(i-targetrow)+abs(j-targetcol);
            }
        }
    }
     return distance;
}

bool isequal(const puzzlestate &curr, const puzzlestate &goal){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(curr.puzzle[i][j]!=goal.puzzle[i][j]){
                return false;
            }
        }
    }
     return true;
}

bool isvalid(int nxr,int nxc){
    if(nxr>=0 && nxr<n && nxc>=0 && nxc<n){
        return true;
    }
    return false;
}


vector<puzzlestate> generatenextstates(const puzzlestate &curr){
    vector<puzzlestate>ans;
    const int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    for(int i=0;i<4;i++){
        int nextzrow = curr.zrow + moves[i][0];
        int nextzcol = curr.zcol + moves[i][1];

        if(isvalid(nextzrow,nextzcol)){
            puzzlestate nextstate = curr;
            swap(nextstate.puzzle[curr.zrow][curr.zcol],nextstate.puzzle[nextzrow][nextzcol]);
            nextstate.zrow = nextzrow;
            nextstate.zcol = nextzcol;
            nextstate.g = curr.g+1;
            nextstate.h = calculateManhattanDistance(nextstate);

            ans.push_back(nextstate);
        }

    }
    return ans;
}

void astar(const puzzlestate &initialstate,const puzzlestate &goalstate){
    priority_queue<puzzlestate>pq;
    unordered_set<string>vis;
    pq.push(initialstate);

    while(!pq.empty()){
        puzzlestate curr = pq.top();
        pq.pop();

        cout<<"Current State : "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<curr.puzzle[i][j]<<" ";
            }
            cout<<endl;
        }

        if(isequal(curr,goalstate)){
            cout<<"Goal state reached"<<endl;
            break;
        }

        vector<puzzlestate> nextstates = generatenextstates(curr);

        for(auto it : nextstates){
            string hash = "";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    hash += to_string(it.puzzle[i][j]);
                }
            }

            if(vis.find(hash)==vis.end()){
                pq.push(it);
                vis.insert(hash);
            }
        }

    }
}

puzzlestate getpuz(){
    puzzlestate puz;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the val in puzzle at ("<<i<<","<<j<<")"<<endl;
            cin>>puz.puzzle[i][j];

            if(puz.puzzle[i][j]==0){
                puz.zrow = i;
                puz.zcol = j;
            }
        }
    }
    puz.g = 0;
    puz.h = calculateManhattanDistance(puz);
    
    return puz;
}

int main(){

    cout<<"Enter the Initial State"<<endl;
    puzzlestate initialstate = getpuz();

    cout<<"Enter the goal state:"<<endl;
    puzzlestate goalstate = getpuz();

    astar(initialstate,goalstate);
}

/*
Enter the initial state of the puzzle (0 represents the empty tile):
Enter value at position (0, 0): 0
Enter value at position (0, 1): 1
Enter value at position (0, 2): 2
Enter value at position (1, 0): 4
Enter value at position (1, 1): 6
Enter value at position (1, 2): 3
Enter value at position (2, 0): 7
Enter value at position (2, 1): 5
Enter value at position (2, 2): 8
Enter the final state of the puzzle (0 represents the empty tile):
Enter value at position (0, 0): 1
Enter value at position (0, 1): 2
Enter value at position (0, 2): 3
Enter value at position (1, 0): 4
Enter value at position (1, 1): 5
Enter value at position (1, 2): 6
Enter value at position (2, 0): 7
Enter value at position (2, 1): 8
Enter value at position (2, 2): 0
Initial State:
0 1 2
4 6 3
7 5 8
-----
Current State:
0 1 2
4 6 3
7 5 8
-----
Number of moves: 0
Heuristic cost: 6
-------------------
Current State:
1 0 2
4 6 3
7 5 8
-----
Number of moves: 1
Heuristic cost: 5
-------------------
Current State:
1 2 0
4 6 3
7 5 8
-----
Number of moves: 2
Heuristic cost: 4
-------------------
Current State:
1 2 3
4 6 0
7 5 8
-----
Number of moves: 3
Heuristic cost: 3
-------------------
Current State:
1 2 3
4 0 6
7 5 8
-----
Number of moves: 4
Heuristic cost: 2
-------------------
Current State:
1 2 3
4 5 6
7 0 8
-----
Number of moves: 5
Heuristic cost: 1
-------------------
Current State:
1 2 3
4 5 6
7 8 0
-----
Number of moves: 6
Heuristic cost: 0
-------------------
Goal State Reached!
Number of moves: 6
Heuristic cost: 0
*/