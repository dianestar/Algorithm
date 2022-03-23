#include <iostream>
#include <vector>
using namespace std;

int checkStr(string str, int i, int j, bool chance) {
    while (i < j) {
        if (str[i] == str[j]) {
            i++;
            j--;
            continue;
        }

        // �� ��ü�� ȸ���� �ƴ� ��� + �� ���� ������ �� �ִ� ��ȸ �ִ� ���
        if (chance) {
            // ����ȸ���� ���
            if (checkStr(str, i+1, j, false) == 0 || checkStr(str, i, j-1, false) == 0) {
                return 1;
            }
            // ȸ���� ����ȸ���� �ƴѰ��
            return 2;
        }

        // �� ��ü�� ȸ���� �ƴ� ��� + �� ���� ������ �� �ִ� ��ȸ ���� ���
        // ȸ���� ����ȸ���� �ƴ� ���
        return 2;
    }

    // ȸ���� ���
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        char ch[100001];
        scanf("%s", ch);
        string str = ch;
        int endIdx = str.size()-1;
        printf("%d\n", checkStr(str, 0, endIdx, true));
    }

    return 0;
}