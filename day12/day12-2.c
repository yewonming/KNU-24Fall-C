#include <stdio.h>

// 최소 거리를 찾는 재귀 함수
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
    return cnt; // 기본 반환 (실질적으로 도달하지 않음)
}

// 숫자 감소를 위한 솔루션 함수
int solution(int n) {
    int cnt = 0;
    return find_minimum(n, cnt);
}

int main() {
    int n;
    printf("숫자를 입력하세요: ");
    scanf_s("%d", &n); 

    int result = solution(n);
    printf("최소 거리: %d\n", result);

    return 0;
}
