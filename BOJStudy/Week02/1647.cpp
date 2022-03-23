#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road { // edge
    int houseA; // node1
    int houseB; // node2
    int cost; // edge�� ����ġ
};
vector<int> parents(100001);

bool cmp(const Road &a, const Road &b) {
    return a.cost < b.cost;
}

int getParent(int house) {
    if (parents[house] == house) {
        return house;
    }
    return parents[house] = getParent(parents[house]); // path compression
}

void unionHouses(int houseA, int houseB) {
    int a = getParent(houseA);
    int b = getParent(houseB);
    if (a < b) { parents[b] = a; }
    else { parents[a] = b; }
}

int main() {
    // ���� ���� N, ���� ���� M
    int N, M;
    scanf("%d %d", &N, &M);

    // A�� ���� B�� ���� �����ϴ� ���� ������ C
    int A, B, C;
    vector<Road> roads;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        roads.push_back({A, B, C});
    }

    // Kruskal's Algorithm Ȱ��
    // Road(edge)�� ����ġ�� �������� �������� ����
    sort(roads.begin(), roads.end(), cmp);

    // House(node)�� parents ���� �ʱ�ȭ
    // ó������ ���� �ڱ� �ڽ��� parents
    for (int i=1; i<=N; i++) {
        parents[i] = i;
    }

    vector<int> selectedRoads;
    for (int i=0; i<M; i++) {
        // parent�� �ٸ��ٴ� ���� ���� �� House ���̿� ��ΰ� ���ٴ� �� (����Ŭ X)
        if (getParent(roads[i].houseA) != getParent(roads[i].houseB)) {
            // parent�� ���� ����� �ϳ��� �׷����� ��ġ��
            unionHouses(roads[i].houseA, roads[i].houseB);
            // Road�� ����ġ ����
            selectedRoads.push_back(roads[i].cost);
        }
    }

    // ���� ����
    // ���õ� Road�� ����ġ �� ���� ū ����ġ�� ���� Road�� �����ϰ� ����ġ �� ���ϱ�
    int count = selectedRoads.size() - 1;
    int answer = 0;
    for (int i=0; i<count; i++) {
        answer += selectedRoads[i];
    }

    // ���ְ� ���� �� �������� ���� �ּڰ��� ���
    printf("%d", answer);

    return 0;
}