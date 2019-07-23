/*
	아래의 코드는 2차원 배열 mat[row][col]을 동적 할당받아서 초기화 하는 예이다.
*/
#include <iostream>
int main()
{
	int col, row;
	std::cin >> row >> col;

	// 1. 2차원 배열을 동적할당 하세요 (for문 사용)
	int** mat;
	mat = new int *[row];
	for (int i = 0; i < row; i++) {
		mat[i] = new int[col];
	}

	// 2차원 배열을 초기화하고 출력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = i * col + j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// 2. 동적할당 받은 2차원 배열을 해제하세요 (for문 사용)
	for (int i = 0; i < row; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}