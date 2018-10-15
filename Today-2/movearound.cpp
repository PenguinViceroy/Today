//#include  <iostream>
//
//using namespace std;
//
//const int ksize_a = 10;
//const int kmove_size = 3;
//
//int* move(int * array, int n, int m)
//{
//	int* array_b = new int[n];
//
//	for(int i = 0; i < n-m; i++)
//	{
//		array_b[i + m] = array[i];
//	}
//	for(int i = n-m; i < n; i++)
//	{
//		array_b[i+m - n] = array[i];
//	}
//
//	return array_b;
//}
//
//int main()
//{
//	int a[ksize_a] = {0};
//	for(int i = 0; i < ksize_a; i++)
//	{
//		cin >> a[i];
//	}
//
//	//creat a array the same as 'a' as the result
//	int* b = move(a, ksize_a, kmove_size);
//
//	for(int i = 0; i < ksize_a; i++)
//	{
//		cout << b[i] << " ";
//	}
//	delete b;
//	b = NULL;
//
//	int h;
//	cin >> h;
//
//}