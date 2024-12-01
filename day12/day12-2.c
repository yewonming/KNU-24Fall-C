#include <stdio.h>

// �ּ� �Ÿ��� ã�� ��� �Լ�
int find_minimum(int n, int cnt) {
    if (n % 2 == 0) {
        return find_minimum(n / 2, cnt);
    }
    else if (n % 2 == 1 && n != 1) {
        cnt++;
        return find_minimum(n - 1, cnt);
    }
    else if (n == 1) {
        cnt++;
        return cnt;
    }
    return cnt; // �⺻ ��ȯ (���������� �������� ����)
}

// ���� ���Ҹ� ���� �ַ�� �Լ�
int solution(int n) {
    int cnt = 0;
    return find_minimum(n, cnt);
}

int main() {
    int n;
    printf("���ڸ� �Է��ϼ���: ");
    scanf_s("%d", &n); 

    int result = solution(n);
    printf("�ּ� �Ÿ�: %d\n", result);

    return 0;
}
