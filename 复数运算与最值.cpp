#include <stdio.h>

// 定义复数结构体
typedef struct {
    int real;  // 实部
    int imag;  // 虚部
} Complex;

// 打印复数的函数，按照要求格式化输出
void printComplex(Complex c) {
    if (c.real == 0 && c.imag == 0) {
        printf("{0}\n");
    }
    else if (c.real == 0) {
        printf("{%di}\n", c.imag);
    }
    else if (c.imag == 0) {
        printf("{%d}\n", c.real);
    }
    else {
        printf("{%d%+di}\n", c.real, c.imag);
    }
}

// 复数加法
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// 复数减法
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// 复数乘法
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// 复数除法
Complex divide(Complex a, Complex b) {
    Complex result;
    int denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

// 复数比较函数：先比较实部，再比较虚部
int compare(Complex a, Complex b) {
    if (a.real > b.real) {
        return 1;
    }
    else if (a.real < b.real) {
        return -1;
    }
    else if (a.imag > b.imag) {
        return 1;
    }
    else if (a.imag < b.imag) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    Complex a, b;
    Complex sum, diff, prod, quot;

    // 读入四个整数，分别构造两个复数，并检查输入是否正确
    if (scanf("%d %d %d %d", &a.real, &a.imag, &b.real, &b.imag) != 4) {
        printf("输入格式错误\n");
        return 1; // 返回一个错误码
    }

    // 计算它们的和、差、积、商
    sum = add(a, b);
    diff = subtract(a, b);
    prod = multiply(a, b);
    quot = divide(a, b);

    // 打印两个复数
    printComplex(a);
    printComplex(b);

    // 打印加、减、乘、除的结果
    printComplex(sum);
    printComplex(diff);
    printComplex(prod);
    printComplex(quot);

    // 找出加、减、乘、除中的最大值
    Complex max = sum;
    if (compare(diff, max) > 0) max = diff;
    if (compare(prod, max) > 0) max = prod;
    if (compare(quot, max) > 0) max = quot;

    // 打印最大值
    printComplex(max);

    return 0;
}
