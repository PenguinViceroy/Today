#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
��Ʋ�����һ��ʵ���ڴ��������ʵ�ֶ��ڴ�ķ��䡢�ͷź�������Ӧ�Ľӿ�Ϊnew��del��def��ʹ���﷨Ϊ��

new size������size�ֽڴ�С���ڴ�飬���ظ��ڴ��ľ��handle��������ڴ���ţ�����ĵ�һ���ڴ����Ϊ1���Դ����ƣ���sizeΪ��������

del handle���ͷž��handleָ����ڴ�顣

def�������ڴ���Ƭ���������ѷ����ڴ�鰴��ַ�ӵ͵��ߵ�˳��Ǩ�ƣ�ʹ�����ڴ���Ƭ�ڸ߶˵�ַ��ƴ����һ��
 */

/*
 * ���Ǿ������ڴ�ռ䣬����Զδѧ����η����Զ����С�Ŀռ䡪����Ϊ����Ȼ��̬�ռ�ɷ��䣬�������Ǵ��н������͵�
 * ���Եײ���뷨�����ݷţ��ȿ������������������Ҳ����Ŀ��Ҫ��ġ�
 */

/*
 * ��ģ��һ�����ڴ�ռ䣬Ȼ����һ������ƹ�������󲻶Ϸָ��С���ڴ�ռ䣬����С�����
 *		������������������߼��У�����Ҫģ�⣬��ô������Ĵ����ռ䣻�ڶ�����ǰ�߻�������ֻ��Ҫ�ڴ�ĸ���ؼ����ھ���ļ��ϴ���
 *	���������Ҫ��Ҫ���ϳ��£����ڼ��Ϻ��棩��ͬʱ����ɾ������ȥ���κ�λ��--ͬʱ�ָ����ÿռ䣩���������ȡ��������ɾ������ ��������Ǩ��
 *		���������������ϣ�����Ϊ����Ҫlist���ϲ�����ɾ���
 *	����һ��list���ϣ��Ҷ�����һ�����ڴ�ռ䣨һ���������֮��Ĳ����ͷ����ڶ���һ�������ָ��ռ�ķָ��ô��Ҫ�����߼��ڴ�---��size start end��
 *	
 *	ȡ�û��Ǵ�ǰ����ȡ����ô���أ���Ϊ����Ҳ�ǲ�����һ������ƹ�ԭʼ�ռ䣬���Ӻ��滹����
 *	
 *	
 *	6 10

	new 5

	new 3

	del 1
	
	new 6

	def

	new 6				���
						1
						2
						NULL
						3
						��ζ���ڴ�ķ�����ԭ�����ľͻ�������  �����ô��
	����ͬ���Ƿָ�ʱʹ��list����һ���� ������Ҫ��ԭʼ���ÿռ�Ҳ��list���ϣ�
 */

class mHandle
{
private:
	int start_;
	int end_;
	int size_;
	int handle_number_;

public:
	mHandle() {}
	mHandle(int start, int end, int size,int handle_number):start_(start),end_(end),size_(size),handle_number_(handle_number){}
	mHandle(const mHandle& mh)
	{
		start_ = mh.start();
		end_ = mh.end();
		size_ = mh.size();
		handle_number_ = mh.HandleNumber();
	}
public:
	int start()const { return start_; }
	int end()const { return end_; }
	int size()const { return size_; }
	int HandleNumber()const { return handle_number_; }
public:
	void SetStart(int start) { start_ = start; }
	void SetEnd(int end) { end_ = end; }
public:
	bool operator< (const mHandle& h)		//�ر�����list�в�����Ҫ
	{
		return start_ < h.start();
	}

};	

int T;
int MaxMem;
int handlenumber = 0;
mHandle m_handle;
list<mHandle> used_memory;		//��������ʹ�ÿռ�

bool NewMemory(int size);
bool DeleteMemory(int handle_number);
void def();

int main()
{

	cin >> T >> MaxMem;
	m_handle = mHandle(0, MaxMem, MaxMem, 0);

	for(int i = 0; i < T ;i++)
	{
		string command;
		cin >> command;

		if(command == "new")
		{
			int size;
			cin >> size;
			if (NewMemory(size) == 0)
				cout << "NULL\n";
			else
				cout << handlenumber << endl;
		}
		else if(command == "del")
		{
			int number;
			cin >> number;
			if (DeleteMemory(number) == 0)
				cout << "ILLEGAL_OPERATION\n";
		}
		else if(command == "def")
		{
			def();
		}
	}

}

bool NewMemory(int size)
{
	if(m_handle.end() - m_handle.start() >= size)	//�ռ��������
	{
		const int start = m_handle.start();
		const int end = m_handle.start() + size ;
		handlenumber++;
		const mHandle t_m(start, end, size, handlenumber );
		used_memory.push_back(t_m);

		m_handle.SetStart(m_handle.start() + size);

		return true;
	}
	return false;
}

bool DeleteMemory(int handle_number)
{
	for(list<mHandle>::iterator it = used_memory.begin(); it != used_memory.end(); ++it )
	{
		if(it->HandleNumber() == handle_number)
		{
			int released_size = it->size();
			m_handle.SetStart(m_handle.start() - released_size);
			used_memory.erase(it);
			return true;
		}
	}
	return false;
}

void def()
{
	used_memory.sort();	//������
	//�ٸĵ�ַ
	int start_place = 0;	//��¼��ʼλ��
	for(list<mHandle>::iterator it = used_memory.begin(); it != used_memory.end(); ++it)
	{
		int r_start = it->start();
		int r_end = it->end();

		r_end = r_end - r_start + start_place;	//�ı����λ
		r_start = start_place;		//�ı���ʼλ
		start_place = r_end;		//�ı���ʼλ��¼��
	}
}