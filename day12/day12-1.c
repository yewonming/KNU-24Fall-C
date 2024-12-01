#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// MAX_TOPPING ����� ��ũ�η� ����
#define MAX_TOPPING 100005

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    if (topping_len == 1) {
        return 0;
    }

    int answer = 0;
    bool s1[MAX_TOPPING] = { false }; // ö���� ���� ���θ� ��Ÿ���� �迭
    bool s2[MAX_TOPPING] = { false }; // ������ ���� ���θ� ��Ÿ���� �迭
    int idxArr[MAX_TOPPING] = { 0 };  // �� ������ ������ �����ϴ� �迭
    int s1_count = 0, s2_count = 0;

    // �ʱ� ������ ���� ������ ���� ����
    for (size_t i = 0; i < topping_len; i++) {
        if (!s2[topping[i]]) {
            s2_count++;
        }
        idxArr[topping[i]]++;
        s2[topping[i]] = true;
    }

    // ������ �ϳ��� ö������ �̵�
    for (size_t i = 0; i < topping_len - 1; i++) {
        if (!s1[topping[i]]) {
            s1_count++;
        }
        s1[topping[i]] = true;

        idxArr[topping[i]]--;
        if (idxArr[topping[i]] == 0) {
            s2[topping[i]] = false;
            s2_count--;
        }

        // ö���� ������ ���� ���� ���� ������ �� ����
        if (s1_count == s2_count) {
            answer++;
        }
    }

    return answer;
}
int main() {
    int topping[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t topping_len = sizeof(topping) / sizeof(topping[0]);

    int result = solution(topping, topping_len);
    printf("Result: %d\n", result);

    return 0;
}
