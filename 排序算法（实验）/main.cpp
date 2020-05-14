#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 20000000;
int Array1[MAX];
int Array2[MAX];
int Array3[MAX];
int Array4[MAX];

void Swap(int& a, int& b);
void shellSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void doubleBubble(int arr[], int n);
void oddEven(int arr[], int n);
void print(int arr[], int n);
void heapSort(int arr[], int n);
void quickSort(int arr[], int n);
void qSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void adjustHeap(int arr[], int i, int n);

int main()
{
	srand(time(NULL));
	int arr1[20];
	int arr2[20];
	for (int i = 0; i < 20; i++)
	{
		arr1[i] = rand() % 1000;
		arr2[i] = rand() % 1000;
	}
	cout << "双向排序：" << endl;
	doubleBubble(arr1, 20);
	cout << "奇偶排序：" << endl;
	oddEven(arr2, 20);
	clock_t start, end;
	int n = 20000;
	for (int i = 0; i < n; i++)
	{
		Array1[i] = Array2[i] = Array3[i] = Array4[i] = rand() % 300000;//让数据保持一致
	}
	start = clock();
	//print(Array1, n);
	bubbleSort(Array1, n);
	//print(Array1, n);
	end = clock();
	cout << "2W数据量-冒泡-排序用时：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
	start = clock();
	//print(Array2, n);
	quickSort(Array2, n);
	//print(Array2, n);
	end = clock();
	cout << "2W数据量-快速-排序用时：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
	start = clock();
	//print(Array3, n);
	shellSort(Array3, n);
	//print(Array3, n);
	end = clock();
	cout << "2W数据量-希尔-排序用时：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
	start = clock();
	//print(Array4, n);
	heapSort(Array4, n);
	//print(Array4, n);
	end = clock();
	cout << "2W数据量-堆-排序用时：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
	return 0;
}

/*2W数据量 - 冒泡 - 排序用时：2.493秒
2W数据量 - 快速 - 排序用时：0.002秒
2W数据量 - 希尔 - 排序用时：0.155秒
2W数据量 - 堆 - 排序用时：0.003秒*/
//2kW数据量 - 快速 - 排序用时：2.739秒
//2kW数据量 - 堆 - 排序用时：7.489秒

//双向排序
void doubleBubble(int arr[], int n)
{
	bool flag = true;//用来标记数组两端是否进行交换 没有交换则说明已经有序 退出循环
	int count = 1;
	int i = 0, j = n - 1;
	while (true)
	{
		flag = false;
		for (int k = j; k > i; k--)//最小值放在前面
		{
			if (arr[k] < arr[k - 1])
			{
				flag = true;
				Swap(arr[k], arr[k - 1]);
			}
		}
		i++;
		for (int k = i; k < j; k++)//最大值放在后面
		{
			if (arr[k] > arr[k + 1])
			{
				flag = true;
				Swap(arr[k], arr[k + 1]);
			}
		}
		j--;
		if (!flag)
			break;
		cout << "第" << count++ << "趟排序结果为：";
		print(arr, n);
	}
}

//奇偶转换排序
void oddEven(int arr[], int n)
{
	bool flag = true;
	int i = n - 1;
	int count = 1;
	while (true)
	{
		flag = false;
		for (int k = 1; k < i; k += 2)//奇数排序
		{
			if (arr[k] > arr[k + 1])
			{
				flag = true;
				Swap(arr[k], arr[k + 1]);
			}
		}
		for (int k = 0; k < i; k += 2)//偶数排序
		{
			if (arr[k] > arr[k + 1])
			{
				flag = true;
				Swap(arr[k], arr[k + 1]);
			}
		}
		if (!flag)
			break;
		cout << "第" << count++ << "趟排序结果为：";
		print(arr, n);
	}
}

//堆排序
void heapSort(int arr[], int n)
{
	int count = 1;
	for (int i = (n - 1) / 2; i >= 0; i--)//首先将数组调整为大顶堆
	{
		adjustHeap(arr, i, n);
	}
	for (int i = n - 1; i > 0; i--)//首位元素交换 再将首元素调整成大顶堆
	{
		Swap(arr[0], arr[i]);
		//cout << "第" << count++ << "趟排序结果为：";
		//print(arr, n);
		adjustHeap(arr, 0, i);
	}
}

//调整堆(与插入排序类似，移动元素找到位置后进行赋值)
void adjustHeap(int arr[], int i, int n)
{
	int child = 0;
	int temp = arr[i];
	for (; 2 * i + 1 < n; i = child)//有左孩子
	{
		child = 2 * i + 1;
		if (arr[child] < arr[child + 1] && child != n - 1)//有右孩子的情况下 右孩子的值大于左孩子
			child++;
		if (temp < arr[child])//向下调整 交换父子节点的值
			arr[i] = arr[child];
			//Swap(arr[i], arr[child]);
		else //没有交换值，直接退出
			break;
	}
	arr[i] = temp;
}

//冒泡排序
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

//快速排序
void quickSort(int arr[], int n)
{
	qSort(arr, 0, n - 1);
}

//递归寻找基准并进行排序合并
void qSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		qSort(arr, low, pivot - 1);
		qSort(arr, pivot + 1, high);
	}
}

//快速排序中根据基准进行分区
int partition(int arr[], int low, int high)
{
	int pivot = low;//基准
	int temp = arr[pivot];
	while (low < high)
	{
		while (low < high && arr[high]>temp)
			high--;
		if (low < high)
		{
			arr[low] = arr[high];
			low++;
		}
		while (low < high && arr[low] < temp)
			low++;
		if (low < high)
		{
			arr[high] = arr[low];
			high--;
		}
	}
	arr[low] = temp;
	return low;
}

//希尔排序
void shellSort(int arr[], int n)
{
	int jump = n / 2;
	int temp = 0;
	int j = 0;
	while (jump >= 1)
	{
		for (int i = jump; i < n; i += jump)
		{
			temp = arr[i];
			for (j = i - jump; j >= 0 && (arr[j] > temp); j -= jump)
			{
				arr[j + jump] = arr[j];//元素后移
			}
			arr[j + jump] = temp;//在正确的插入位置赋值
		}
		jump /= 2;
	}
}

//打印数组
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//交换函数
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}