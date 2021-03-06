#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);    
    }
    
    while (pq.top() < K) {
        if (pq.size() == 1) {
            answer = -1;
            break;
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int current = first + second * 2;
        pq.push(current);

        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> scoville = {1,2,3,9,10,12};
    int K = 7;
    
    printf("%d", solution(scoville, K));

    return 0;
}