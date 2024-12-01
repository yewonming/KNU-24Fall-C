#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// MAX_TOPPING 상수를 매크로로 정의
#define MAX_TOPPING 100005

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    if (topping_len == 1) {
        return 0;
    }

    int answer = 0;
    bool s1[MAX_TOPPING] = { false }; // 철수의 토핑 여부를 나타내는 배열
    bool s2[MAX_TOPPING] = { false }; // 동생의 토핑 여부를 나타내는 배열
    int idxArr[MAX_TOPPING] = { 0 };  // 각 토핑의 개수를 저장하는 배열
    int s1_count = 0, s2_count = 0;

    // 초기 동생의 토핑 종류와 개수 설정
    for (size_t i = 0; i < topping_len; i++) {
        if (!s2[topping[i]]) {
            s2_count++;
        }
        idxArr[topping[i]]++;
        s2[topping[i]] = true;
    }

    // 토핑을 하나씩 철수에게 이동
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

        // 철수와 동생의 토핑 종류 수가 같으면 답 증가
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
