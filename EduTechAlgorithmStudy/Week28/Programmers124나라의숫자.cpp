#include <iostream>
#include <string>
#include <vector>
// #include <queue>

using namespace std;

/* ��Ȯ�� �׽�Ʈ ���� ��� but ȿ���� �׽�Ʈ ���� �ð��ʰ�
string solution(int n) {    
    string answer = "";
    vector<string> numbers = {"1", "2", "4"};
    queue<string> q;
    for (int i=0; i<3; i++) { q.push(numbers[i]); }
    
    int count = 1;
    while (1) {
        if (count * 3 >= n) {
            int toPop = n-count;
            for (int i=0; i<toPop; i++) { q.pop(); }
            answer = q.front();
            break;
        }
        
        string number = q.front();
        q.pop();
        for (int i=0; i<3; i++) { q.push(number + numbers[i]); }
        count++;
    }
    
    return answer;
}
*/

string solution(int n) {    
    string answer = "";
    vector<string> remainder = {"4", "1", "2"}; // remainder[i]: 3���� ���� �������� i�� ��쿡 �� 124���� ����
    
    while (n) {
        answer = remainder[n%3] + answer;
        if (n%3) { n = n/3; }
        else { n = (n-1)/3; }
    }
    
    return answer;
}

int main() {
    vector<int> n = {1,2,3,4};

    for (int i=0; i<n.size(); i++) {
        cout << solution(n[i]) << endl;
    }

    return 0;
}