#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// 判断是否是素数的函数
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
    char input[50];  // 用于存储输入的字符串
    int num;
    char extra;  // 用于捕获多余字符


    // 使用fgets读取整行输入并尝试解析
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // 尝试读取一个整数并检查后续是否有非整数字符
        if (sscanf(input, "%d %c", &num, &extra) == 1) {
            // 判断是否为素数
            if (isPrime(num)) {
                printf("是素数\n");
            }
            else {
                printf("不是素数\n");
            }
        }
        else {
            // 输入不符合整数格式
            printf("输入错误\n");
        }
    }
    else {
        // fgets读取失败
        printf("输入错误\n");
    }

    return 0;
}
