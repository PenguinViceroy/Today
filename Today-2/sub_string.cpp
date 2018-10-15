//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//	char *str = new char[100];
//	char *sub_str = new char[100];
//	cin >> str >> sub_str;
//
//	int occur_time = 0;
//	int flag = false;
//	for(int i = 0; i < (int)strlen(str); i++)
//	{
//		for(int j = 0; j < (int)strlen(sub_str); j++,i++)
//		{
//			if (flag == true)
//			{
//				i--;
//				flag = false;
//			}
//			if(sub_str[j] == str[i])
//			{
//				if(j == (int)strlen(sub_str)-1)
//				{
//					occur_time++;
//					flag = true;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//
//	}
//	cout << occur_time;
//}