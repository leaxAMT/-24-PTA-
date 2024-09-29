#include <stdio.h>

// ���帴���ṹ��
typedef struct {
    int real;  // ʵ��
    int imag;  // �鲿
} Complex;

// ��ӡ�����ĺ���������Ҫ���ʽ�����
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

// �����ӷ�
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// ��������
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// �����˷�
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// ��������
Complex divide(Complex a, Complex b) {
    Complex result;
    int denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

// �����ȽϺ������ȱȽ�ʵ�����ٱȽ��鲿
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

    // �����ĸ��������ֱ�����������������������Ƿ���ȷ
    if (scanf("%d %d %d %d", &a.real, &a.imag, &b.real, &b.imag) != 4) {
        printf("�����ʽ����\n");
        return 1; // ����һ��������
    }

    // �������ǵĺ͡��������
    sum = add(a, b);
    diff = subtract(a, b);
    prod = multiply(a, b);
    quot = divide(a, b);

    // ��ӡ��������
    printComplex(a);
    printComplex(b);

    // ��ӡ�ӡ������ˡ����Ľ��
    printComplex(sum);
    printComplex(diff);
    printComplex(prod);
    printComplex(quot);

    // �ҳ��ӡ������ˡ����е����ֵ
    Complex max = sum;
    if (compare(diff, max) > 0) max = diff;
    if (compare(prod, max) > 0) max = prod;
    if (compare(quot, max) > 0) max = quot;

    // ��ӡ���ֵ
    printComplex(max);

    return 0;
}
