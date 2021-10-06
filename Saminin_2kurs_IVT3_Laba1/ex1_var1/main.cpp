// �������� ��������� ��������� ����������� ������� � n ����������, � ������������ � 
//���������(���������� �).����������� �������� ������ ������������� �
//������� processArray(), ������������ ������������ �������� � �����������
//��� ����(��������) ������ ������(��.���� �������).������ ��� �������
//�������� ����������(��������� ������� �������� � ������� main) � ��� ������� �
//��������� ������������ �������.���� - ����� ������ ������������ ���������� cstdio.

//var1
//�������� ������ �� n=15 ������������ �����, ������������������� ���������. 
//������� processArray() ������ ��������� ��� �������� � ������� ��������� ��
//��������� ����� �� ���������[a, b](a � b ������ � ����������, a < 0), ���������� �
//������� ���������� ������������� ��������� ������� � ������������ ��������
//������, ���������� ������ ������������� �������� ��������(�.�.�����������
//����������).������� �� ����� �������������� �������.

#include <cstdio>
#include <cstdlib> 
#include <stdlib.h> 
#define _CRT_SECURE_NO_WARNINGS  // ��� ����������� ������������� scanf

size_t processArray(double arr[], double newArr[], size_t n, int min, int max) {
	for (size_t i = 0; i < n; i += 2) {
		arr[i] = (rand() % (max - min + 1)) + min;
	}

	size_t numOfNegativeNums = 0;

	for (size_t i = 0; i < n; ++i) {
		if (arr[i] < 0) {
			numOfNegativeNums++;
		}
		
	}
	
	for (size_t j = 0; j < numOfNegativeNums; ++j) {
		for (size_t i = 0; i < n; ++i) {
			if (arr[i] < 0) {
				newArr[j] = arr[i];
				j++;
			}
		}
	}

	return numOfNegativeNums;
}

void printArray(double arr[], size_t n) {
	for (size_t i = 0; i < n; ++i) {
		printf("%3.2f  ", arr[i]);
	}
	printf("\n");
}

int main() {
	const size_t N = 15;
	double arr[N];
	size_t result;
	double newArr[N];

	for (size_t i = 0; i < N; i++) {
		arr[i] = 1.0;
	}

	int a, b;

	system("chcp 1251"); // ��������� � ������� �� ������� ����
	system("cls");

	printf("������� ��������(a � b) ��� ��������� �����-���������� ����� ENTER: \n");
	scanf_s("%d", &a);     
	scanf_s("%d", &b);
	printf("\n\n");

	result = processArray(arr, newArr, N, a, b);

	printf("������ � ���������� ����������� ��� ������ ��������: \n");
	printArray(arr, N);
	printf("\n\n");

	printf("���������� ������������� ��������� �������: ");
	printf("%d\n", result);
	printf("\n\n");
	
	
	printf("������, ����������� �������������� ����������: \n");
	printArray(newArr, result);
	printf("\n\n");
	
	system("pause");
	return 0;
}