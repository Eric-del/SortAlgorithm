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
	cout << "˫������" << endl;
	doubleBubble(arr1, 20);
	cout << "��ż����" << endl;
	oddEven(arr2, 20);
	clock_t start, end;
	int n = 20000;
	for (int i = 0; i < n; i++)
	{
		Array1[i] = Array2[i] = Array3[i] = Array4[i] = rand() % 300000;//�����ݱ���һ��
	}
	start = clock();
	//print(Array1, n);
	bubbleSort(Array1, n);
	//print(Array1, n);
	end = clock();
	cout << "2W������-ð��-������ʱ��" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
	start = clock();
	//print(Array2, n);
	quickSort(Array2, n);
	//print(Array2, n);
	end = clock();
	cout << "2W������-����-������ʱ��" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
	start = clock();
	//print(Array3, n);
	shellSort(Array3, n);
	//print(Array3, n);
	end = clock();
	cout << "2W������-ϣ��-������ʱ��" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
	start = clock();
	//print(Array4, n);
	heapSort(Array4, n);
	//print(Array4, n);
	end = clock();
	cout << "2W������-��-������ʱ��" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
	return 0;
}

/*2W������ - ð�� - ������ʱ��2.493��
2W������ - ���� - ������ʱ��0.002��
2W������ - ϣ�� - ������ʱ��0.155��
2W������ - �� - ������ʱ��0.003��*/
//2kW������ - ���� - ������ʱ��2.739��
//2kW������ - �� - ������ʱ��7.489��

//˫������
void doubleBubble(int arr[], int n)
{
	bool flag = true;//����������������Ƿ���н��� û�н�����˵���Ѿ����� �˳�ѭ��
	int count = 1;
	int i = 0, j = n - 1;
	while (true)
	{
		flag = false;
		for (int k = j; k > i; k--)//��Сֵ����ǰ��
		{
			if (arr[k] < arr[k - 1])
			{
				flag = true;
				Swap(arr[k], arr[k - 1]);
			}
		}
		i++;
		for (int k = i; k < j; k++)//���ֵ���ں���
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
		cout << "��" << count++ << "��������Ϊ��";
		print(arr, n);
	}
}

//��żת������
void oddEven(int arr[], int n)
{
	bool flag = true;
	int i = n - 1;
	int count = 1;
	while (true)
	{
		flag = false;
		for (int k = 1; k < i; k += 2)//��������
		{
			if (arr[k] > arr[k + 1])
			{
				flag = true;
				Swap(arr[k], arr[k + 1]);
			}
		}
		for (int k = 0; k < i; k += 2)//ż������
		{
			if (arr[k] > arr[k + 1])
			{
				flag = true;
				Swap(arr[k], arr[k + 1]);
			}
		}
		if (!flag)
			break;
		cout << "��" << count++ << "��������Ϊ��";
		print(arr, n);
	}
}

//������
void heapSort(int arr[], int n)
{
	int count = 1;
	for (int i = (n - 1) / 2; i >= 0; i--)//���Ƚ��������Ϊ�󶥶�
	{
		adjustHeap(arr, i, n);
	}
	for (int i = n - 1; i > 0; i--)//��λԪ�ؽ��� �ٽ���Ԫ�ص����ɴ󶥶�
	{
		Swap(arr[0], arr[i]);
		//cout << "��" << count++ << "��������Ϊ��";
		//print(arr, n);
		adjustHeap(arr, 0, i);
	}
}

//������(������������ƣ��ƶ�Ԫ���ҵ�λ�ú���и�ֵ)
void adjustHeap(int arr[], int i, int n)
{
	int child = 0;
	int temp = arr[i];
	for (; 2 * i + 1 < n; i = child)//������
	{
		child = 2 * i + 1;
		if (arr[child] < arr[child + 1] && child != n - 1)//���Һ��ӵ������ �Һ��ӵ�ֵ��������
			child++;
		if (temp < arr[child])//���µ��� �������ӽڵ��ֵ
			arr[i] = arr[child];
			//Swap(arr[i], arr[child]);
		else //û�н���ֵ��ֱ���˳�
			break;
	}
	arr[i] = temp;
}

//ð������
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

//��������
void quickSort(int arr[], int n)
{
	qSort(arr, 0, n - 1);
}

//�ݹ�Ѱ�һ�׼����������ϲ�
void qSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		qSort(arr, low, pivot - 1);
		qSort(arr, pivot + 1, high);
	}
}

//���������и��ݻ�׼���з���
int partition(int arr[], int low, int high)
{
	int pivot = low;//��׼
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

//ϣ������
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
				arr[j + jump] = arr[j];//Ԫ�غ���
			}
			arr[j + jump] = temp;//����ȷ�Ĳ���λ�ø�ֵ
		}
		jump /= 2;
	}
}

//��ӡ����
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//��������
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}