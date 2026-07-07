class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {

    unordered_map<char,int> freq;

    for(char task : tasks) {

        freq[task]++;
    }

    priority_queue<int> pq;

    for(auto &p : freq){

        pq.push(p.second);
    } 

    int time = 0;

    while(!pq.empty()) {

        vector<int> temp;

        int cycle = n + 1;
        int workDone = 0;

        while(cycle > 0 && !pq.empty()) {

            int count = pq.top();
            pq.pop();

            count--;
            workDone++;

            if(count > 0){
                temp.push_back(count);
            }

            cycle--;
        }

        for(int x : temp) {

            pq.push(x);
        }

        if(pq.empty()) {

            time += workDone;
        }
        else {

            time += n + 1;
        }
    }

    return time;
    }
};