#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int row, col, i, j; //�� ������ ���� ������
	int x, y, direction; //���� ĳ���Ϳ� ���� ������ ���� ������
	int left_x, left_y; //ĳ������ ���� ������ ������ ���� ������
	int count = 0; // �������� �˻� Ƚ��
	int result = 0; //�湮�� ĭ�� �� ����

	scanf("%d %d", &row, &col); //���� ���� ũ�� �Է�

	int** map; //������ �����Ҵ� ����
	map = malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
		map[i] = malloc(sizeof(int) * col);

	scanf("%d %d %d", &x, &y, &direction);// ĳ���� ���� �Է�
	for (i = 0; i < row; i++) //�� ���� �Է�
	{
		for (j = 0; j < col; j++)
			scanf(" %d", &map[i][j]);
	}
	
	map[x][y] = -1; //�������� -1, �ٴٴ� 1, ������ ���� ���� 0
	result = result + 1;

	while (1)//�ùķ��̼� ����
	{
		switch (direction) { //left_x, left_y�� ĳ������ ���� ��ǥ ����
		case 0: // ��
			left_x = x - 1; left_y = y;
			break;
		case 1: //��
			left_x = x; left_y = y + 1;
			break;
		case 2: //��
			left_x = x + 1; left_y = y;
			break;
		case 3://��
			left_x = x; left_y = y - 1;
			break;
		}
		if (map[left_x][left_y] == 0) //�ٴٰ� �ƴϰų� ���� ������ ���� ĭ�̶��
		{
			if (direction == 0) direction = 3; // ���� ��ȯ
			else direction = direction - 1;
			x = left_x; y = left_y; //�̵�
			map[left_x][left_y] = -1; //���� ������ ����
			count = 0;
			result = result + 1;
		}
		else if (map[left_x][left_y] != 0) //�ٴ��̰ų� ���� ���̶��
		{
			if (count == 4) //�������� ��� �˻��ߴٸ�
			{
				switch (direction) { //�� ĭ �ڷΰ���
				case 0: // ��
					x = x + 1; y = y;
					break;
				case 1: //��
					x = x; y = y - 1;
					break;
				case 2: //��
					x = x - 1; y = y;
					break;
				case 3://��
					x = x; y = y + 1;
					break;
				}
				if (map[x][y] == 1) break; //�ٴٶ�� ���� (�ڰ� �ٴٷ� �����ִ� ���)
				else if (map[x][y] == -1 ){ // �ٴٰ� �ƴ϶� ���� ���̶��
					result = result + 1;
					count = 0;
				}
			}
			else
			{
				count++;
				if (direction == 0) direction = 3; // ���� ��ȯ
				else direction = direction - 1;
			}
		}
	}
	printf("%d", result); //��� ���
	for (i = 0; i < row; i++) //���� �Ҵ� ����
		free(map[i]);
	free(map);
	return 0;
}