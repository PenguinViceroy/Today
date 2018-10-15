// #include <iostream>
// #include <math.h>
// using namespace std;


// int Seek_min(int** p_planets, const int number, const int axis)
// {
// 	int min = p_planets[0][axis];
// 	for(int i = 0; i < number; i++ )
// 	{
// 		if (p_planets[i][axis] < min)
// 			min = p_planets[i][axis];
// 	}
// 	return min;
// }

// int Seek_max(int** p_planets, const int number, const int axis)
// {
// 	int max = p_planets[0][axis];
// 	for (int i = 0; i < number; i++)
// 	{
// 		if (p_planets[i][axis] > max)
// 			max = p_planets[i][axis];
// 	}
// 	return max;
// }

// int GetDistance(const int x, const int y, const int z, int** p_planets, const int number)
// {
// 	int sum = 0;
// 	for(int i = 0; i < number; i++)
// 	{
// 		sum += abs(p_planets[i][0] - x);
// 		sum += abs(p_planets[i][1] - y);
// 		sum += abs(p_planets[i][2] - z);
// 	}
// 	return sum;
// }

// bool ConfirmPos(int** p_planets,const int number, const int axis, const int position)
// {
// 	for(int i = 0; i < number; i++)
// 	{
// 		if (position == p_planets[i][axis])
// 			return true;
// 	}
// 	return false;
// }

// int main()
// {
// 	int n;
// 	while(cin >> n)
// 	{
// 		if (n > 0 && n <= 100000)
// 			break;
// 	}
// 	//����
// 	int** p_planets = new int*[n];
// 	for(int i = 0; i < n; i++)
// 	{
// 		p_planets[i] = new int[3];
// 	}
// 	//��ֵ
// 	for(int i = 0; i < n; i++)
// 	{
// 		cin >> p_planets[i][0]>> p_planets[i][1] >> p_planets[i][2];
// 	}
// 	//ȷ���ռ�
// 	const int x_min = Seek_min(p_planets, n, 0);
// 	const int y_min = Seek_min(p_planets, n, 1);
// 	const int z_min = Seek_min(p_planets, n, 2);	
// 	const int x_max = Seek_max(p_planets, n, 0);
// 	const int y_max = Seek_max(p_planets, n, 1);
// 	const int z_max = Seek_max(p_planets, n, 2);


// 	//Ϊ���ܴ��ڿռ�����������
// 	int possible_position = (x_max - x_min)*(y_max - y_min )*(z_max - z_min);
// 	int** p_possibal_position = new int*[possible_position];
// 	for(int i = 0; i < possible_position; i++)
// 	{
// 		p_possibal_position[i] = new int[4];
// 	}

// 	int count = 0;
// 	for (int i = x_min; i <=x_max; i++ )
// 	{
// 		for(int j = y_min; j <=y_max; j++ )
// 		{
// 			for(int k = z_min; k <=z_max; k++)
// 			{
// 				p_possibal_position[count][2] = k;
// 				count++;

// 				p_possibal_position[count][3] = GetDistance(i, j, k, p_planets, n);
// 			}
// 			p_possibal_position[count][1] = j;
// 		}
// 		p_possibal_position[count][0] = i;
// 	}

// 	for(int i = 0; i < possible_position-1; i++)
// 	{
// 		bool flag = false;
// 		for(int j = 0; j < possible_position-1-i; j++)
// 		{
// 			if(p_possibal_position[j][3] > p_possibal_position[j+1][3])
// 			{
// 				const int temp_x = p_possibal_position[j][0];
// 				const int temp_y = p_possibal_position[j][1];
// 				const int temp_z = p_possibal_position[j][2];
// 				const int temp_d = p_possibal_position[j][3];
// 				p_possibal_position[j][0] = p_possibal_position[j + 1][0];
// 				p_possibal_position[j][1] = p_possibal_position[j + 1][1];
// 				p_possibal_position[j][2] = p_possibal_position[j + 1][2];
// 				p_possibal_position[j][3] = p_possibal_position[j + 1][3];
// 				p_possibal_position[j + 1][0] = temp_x;
// 				p_possibal_position[j + 1][1] = temp_y;
// 				p_possibal_position[j + 1][2] = temp_z;
// 				p_possibal_position[j + 1][3] = temp_d;
				
// 				flag = true;
// 			}
// 		}
// 		if (flag == true)
// 			break;
// 	}

// 	int minimum = 0;
// 	for(int i = 0; i < possible_position; i++)
// 	{
// 		if(ConfirmPos(p_planets,n,0,p_possibal_position[i][0])|| ConfirmPos(p_planets, n, 1, p_possibal_position[i][1]) || ConfirmPos(p_planets, n, 2, p_possibal_position[i][2]) )
// 		{
// 			minimum = p_possibal_position[i][3];
// 		}
// 	}

// 	cout << minimum;


// 	/*
// 	 * ���ڵ�ض�Ҫ��һ�����������һ������������ͬ
// 	 * ͨ��ȫ������-������
// 	 * 
// 	 */


// }
