#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
设计并开发一个实验内存管理器，实现对内存的分配、释放和整理。对应的接口为new、del和def，使用语法为：

new size：分配size字节大小的内存块，返回该内存块的句柄handle（句柄即内存块编号，分配的第一个内存块编号为1，以此类推），size为正整数。

del handle：释放句柄handle指向的内存块。

def：整理内存碎片，将所有已分配内存块按地址从低到高的顺序迁移，使空闲内存碎片在高端地址端拼接在一起。
 */

/*
 * 总是纠结于内存空间，但又远未学过如何分配自定义大小的空间——因为，虽然动态空间可分配，但是这是带有解释类型的
 * 所以底层的想法还是暂放，先考虑如何做到管理——这也是题目所要求的。
 */

/*
 * 先模拟一整块内存空间，然后有一个句柄掌管它，随后不断分割出小的内存空间，诞生小句柄。
 *		——————在这个逻辑中，我需要模拟，那么不必真的创建空间；第二，在前者基础上我只需要内存的概念，关键在于句柄的集合创建
 *	句柄集合需要需要不断出新（加在集合后面），同时还得删除（除去在任何位置--同时恢复可用空间）——随机读取操作、增删操作， 还得整体迁移
 *		——————以上，我认为，需要list集合不断增删配合
 *	对于一个list集合，我定义了一整块内存空间（一个句柄），之后的操作就发生在对这一个句柄所指向空间的分割，那么需要建立逻辑内存---（size start end）
 *	
 *	取得话是从前往后取，那么还呢，因为我们也是采用了一个句柄掌管原始空间，还从后面还，那
 *	
 *	
 *	6 10

	new 5

	new 3

	del 1
	
	new 6

	def

	new 6				输出
						1
						2
						NULL
						3
						意味着内存的返还是原来在哪就还到哪里  看来得大改
	就如同我们分割时使用list集合一样， 我们需要对原始可用空间也用list集合，
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
	bool operator< (const mHandle& h)		//必备——list中操作需要
	{
		return start_ < h.start();
	}

};	

int T;
int MaxMem;
int handlenumber = 0;
mHandle m_handle;
list<mHandle> used_memory;		//创建——使用空间

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
	if(m_handle.end() - m_handle.start() >= size)	//空间大于所需
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
	used_memory.sort();	//先排序
	//再改地址
	int start_place = 0;	//记录起始位置
	for(list<mHandle>::iterator it = used_memory.begin(); it != used_memory.end(); ++it)
	{
		int r_start = it->start();
		int r_end = it->end();

		r_end = r_end - r_start + start_place;	//改变结束位
		r_start = start_place;		//改变起始位
		start_place = r_end;		//改变起始位记录器
	}
}