#include <stdio.h>

int main() {

	int num1 = 100, num2 = 100;
	int* pnum;//�����͸� ���� (�ڿ��� �ּ� ���� �ʿ�)

	pnum = &num1;//�ּҸ� ���� ���Խ��������
	(*pnum) += 30; //�� (*pnum) �̷��� ��ȣ�� ��������? -> ������ �������� �� �� '*'�����ڿ� ȥ�� �ǹǷ� ()�� ���� �������� ����

	pnum = &num2;
	(*pnum) -= 30;

	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);

	return 0;
}