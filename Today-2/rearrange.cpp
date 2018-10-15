//#include  <iostream>
//
//using namespace std;
//
//const int n_size = 10;
//
//int Func(int* A, int nSize)
//{
//	int order_of_first_zero = 0;
//	//flag用来终止已经后面全是0的无意义循环
//	bool flag = false;
//	int i;
//	int j;
//	for (i = 0; i < nSize - 1; i++)
//	{
//		for (j = 0; j < nSize -1 -i; j++)
//		{
//			if (A[j] < A[j + 1])
//			{
//				const int temp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = temp;
//				flag = true;
//			}
//		}
//		if (flag == false)
//			break;
//	}
//	for(i = 0; i < nSize; i++)
//	{
//		if(A[i] == 0)
//		{
//			order_of_first_zero = i;
//			break;
//		}
//	}
//	return order_of_first_zero;
//}
//
//int main()
//{
//	int A[n_size];
//
//	for (int  i = 0; i < n_size; i++)
//	{
//		cin >> A[i];
//	}
//
//	int first_zero = Func(A, n_size);
//	
//	for(int  i = 0; i < n_size; i++)
//	{
//		cout << A[i] << ' ';
//	}
//	cout << endl;
//	cout << first_zero;
//
//	int h;
//	cin >> h;
//}