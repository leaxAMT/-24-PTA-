#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// �ж��Ƿ��������ĺ���
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[50];  // ���ڴ洢������ַ���
    int num;
    char extra;  // ���ڲ�������ַ�


    // ʹ��fgets��ȡ�������벢���Խ���
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // ���Զ�ȡһ���������������Ƿ��з������ַ�
        if (sscanf(input, "%d %c", &num, &extra) == 1) {
            // �ж��Ƿ�Ϊ����
            if (isPrime(num)) {
                printf("������\n");
            }
            else {
                printf("��������\n");
            }
        }
        else {
            // ���벻����������ʽ
            printf("�������\n");
        }
    }
    else {
        // fgets��ȡʧ��
        printf("�������\n");
    }

    return 0;
}
