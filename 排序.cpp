#include<stdlib.h>
#include<stdio.h>
/*

排序算法：
	插入排序
		直接插入排序
		希尔排序
	选择排序
		选择排序
		堆排序
	交换排序
		冒泡排序
		快速排序
	归并排序
		归并排序


插入排序：
	打扑克

*/


//直接插排   ￥
//时间复杂度---O(n^2)   最坏O(n^2)  平均O(n^2)  最好O(n)
//空间O(1)
//稳定性---稳定


void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j;
		int k = array[i];
		//为array[i]找位置
		for (j = i-1; j >= 0; j--)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   是逆序  3 2 1  
			{
				break;
				
			}
			else
			{
				array[j + 1] = array[j];
			}
		}
		array[j + 1] = k;

	}
}

//直接插排测试
int main()
{
	int array[] = { 9,4,3,8,5,7 };
	InsertSort(array, 6);
	for (int i = 0; i <= 5; i++)
	{
		printf("%2d", array[i]);
	}
	system("pause");
	return 0;
}




//希尔排序（缩小增量排序）  大间隔 》小 》1 》停止
//时间复杂度---O(n^1.3-n^2)  空间复杂度O(1)
//稳定性：不稳定
//最好的gap(间隔)  是  gap / 3 + 1;

int gap = size;
gap = gap / 3 + 1;

void InsertSortWithGap(int array[], int size,int gap)
{
	for (int i = gap; i < size; i++)
	{
		int j;
		int k = array[i];

		//为array[i]找位置
		for (j = i - gap; j >= 0; j-=gap)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   是逆序  3 2 1  
			{
				break;

			}
			else
			{
				array[j + gap] = array[j];
			}
		}
		array[j + gap] = k;

	}
}



//直接选择排序
//每次选最小的数
//时间复杂度O(n^2)
//稳定：不稳定
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;  //最小下标
		for (int j = i+1; j < size-i; j++)
		{
			if (array[j] < array[min])
				min = j;
		}


		//交换最小的数到合适的位置上去
		Swap(array + min, array + i);
	}
}

void Swap(int* a, int* b)  //交换函数
{
	int t = *a;
	*a = *b;
	*b = t;
}

//进化版
//一次找到最大最小的
//时间复杂度O(n^2)
void SelectSortOP(int array[], int size)
{
	int minSpace = 0;  //用来放找的的最小数的下标
	int maxSpace = size - 1; //用来方找到最大数的小标
	while (minSpace < maxSpace)
	{
		int min = minSpace;//假设最小的数在小标minSpace
		int max = maxSpace;//假设最大的数在小标minSpace
		for (int i = minSpace+1; i <= maxSpace; i++)
		{
			if (array[i] < array[min])
				i = min;
			if (array[i]>array[max])
				max = i;
		}

		Swap(array + min, array + minSpace);
		if (minSpace == max)
		{
			max = min;
		}
		Swap(array + max, array + maxSpace);

		minSpace++;
		maxSpace--;
	}

}

//冒泡排序 
//时间复杂度---最好O(n),最坏，平均O(n^2) 稳定
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}
	}
}


//建大堆
void Creatheap(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}

//堆排序
//不稳定
//时间复杂度 n*logn
//空间 O(1)
void HeapSort(int array[],int size)
{
	//建大堆
	Creatheap;
	
	for (int  i = 0; i < size-1; i++)
	{
		Swap(&array[0], array + size - 1 - i);
		//向下调整，把堆结构调整正确状态
		AdjustDown(array, size-1- i,0);
	}

}


void AdjustDown(int array[], int size, int root)
{
	while (1)
	{

		//判断root是否是叶子节点
		//因为堆是完全二叉树 ，没有左孩子一定没有有孩子
		//堆是顺序存储，找到左孩子的下标，如果左孩子下标越界，则没有左孩子
		int left = 2 * root + 1;
		if (left >= size)  //不要漏掉等于
		{
			//是叶子结点
			return;
		}

		//找到左右孩子中最小的一个
		//这里一定有左孩子，判断是否有右孩子
		int right = 2 * root + 2;
		int min = left;
		if (right < size  //有右孩子
			&&array[right] < array[left])  //右孩子值小于左孩子
			//&& array[right] > array[left])  //大堆
		{
			min = right;
		}

		//比较array[min]  array[root]
		if (array[min] <= array[root])
			//if (array[min] >= array[root])  //大堆
		{
			return;
		}

		//交换
		int t = array[root];
		array[min] = array[root];
		array[min] = t;

		//继续向下调整，以min作为结点

		AdjustDown(array, size, min);
	}
}


/*

快速排序---时间复杂度   O(n*(log n  ~~n))
1.选择一个基准值
		具体方法：
			1.选择区间最右边的array[right]
			2.三数取中
			mid=(left+right)/2
			array[left]、array[mid]、array[right]
			选择大小事中间的一个数作为基准值
			选择基准值之后，还是把基准值交换到最右侧/左侧 再Pariton
			3.随机方法
2.遍历整个区间，做一些数据交换，达到效果
	比基准值小的数放到基准值左侧
	比基准值大的数放到基准值右侧

3.分治算法
	把一个问题变成两个同样的小问题
	[left right]
	-->
	[left div - 1]    [ div+1   right ]

4.分治算法用递归(或者非递归)
	终止条件
		两个条件：分出来的小区间没有数  分出的区间size==0
				  分出来的小区间有序（什么情况有序？就是区间的size=1）

 */


// Partion 
//时间复杂度 最好、平均O(n*log(n))  最坏  O(n^2)
//空间复杂度 最好、平均O(log(n))  最坏  O(n)
//不稳定

//三种方式：hover法   挖坑法    前后下标


//hover法 
int Parition_1(int array[], int left, int right)//left  right  是数组的下标
{
	int begin = left;
	int end = right;
	//基准值是array[right]

	while (begin < end)
	{	//优先走左边
		while (begin < end&&array[begin] <= array[right])
		{
			begin++;
		}
		
		//卡住了
		//走右边

		while (begin < end&&array[end] >= array[right])
		{
			end++;
		}
		//右边也卡住了

		//交换当前的值
		Swap(array + begin, array + end);
	}

	//区间被分成小，大，基准
	Swap(array + begin, array + right);

	//返回当前基准值
	return array[right];
}

//挖坑法  时间复杂度 O(1)
int Parition_2(int array[], int left, int right)//left  right  是数组的下标
{
	int begin = left;
	int end = right;
	int pivot = array[right];  //基准值

	while (begin < end)
	{	//优先走左边
		while (begin < end&&array[begin] <= pivot)
		{
			begin++;
		}
		//卡住了,填坑
		array[end] = array[begin];

		//走右边
		while (begin < end&&array[end] >= pivot)
		{
			end++;
		}
		//右边也卡住了
		array[begin] = array[end];

	}

	//区间被分成小，大，基准
	Swap(array + begin, array+right);

	//返回当前基准值
	return array[right];

}

//前后下标
int Parition_3(int array[], int left, int right)//left  right  是数组的下标
{
	int i = left;
	int d = left;

	while (i!=right)
	{	//i先走
		while (array[i]>=array[right])
		{
			i++;
		}
		
		//交换array[i],array[d]
		Swap(array + d, array+i);
		i++;
		d++;
	}

	Swap(array + d, array + i);

	//返回当前基准值
	return array[right];

	/*

	//for循环的

	for (int i = left; i < right; i++)
	{
		if (array[i] < array[right])
		{
			Swap(array + d, array + i);
			d++;
		}
	}
	Swap(array + d, array + i);

	//返回当前基准值
	return array[right];
	*/
}



//空间复杂度  log n --- n
//递归调用的深度 （二叉树的高度）
void __QuickSort(int array[], int left,int right)  
{ //基本以右边为基准
	//终止条件 size==1 ||  size ==0
	//left==right  剩余一个数
	//left>right  区间内没有数
	if (left == right)
	{
		return;
	}

	if (left == right)
	{
		return;
	}

	/*
	选三个数取中
	int pivot_index = PickMid(array, left, right);
	Swap(array + pivot_index, array + right);
	*/

	//  基准值所在下标 
	int div; //  比基准值小的数放到基准值左侧     比基准值大的数放到基准值右侧
	div = Parition_1( array, left, right);  //遍历array[left,right]，把小的放左，大的放右边

	//类似二叉树的前序遍历
	__QuickSort(array, left, div - 1);  //分治算法
	__QuickSort(array, div + 1, right);
}

//三数取中方法，返回合适的下标
int PickMid(int array[], int left, int right)
{
	int mid = (left + right) / 2;
	if (array[left] > array[right] && array[left] > array[mid])
	{
		if (array[mid] > array[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
	else if(array[mid] > array[right])
	{
		if (array[left] > array[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
		if (array[mid] > array[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
}



void QuickSort(int array[], int size)
{
	__QuickSort(array, 0, size - 1);
	
}

#include<stack>
//快排非递归写法：体现在大的步骤，需要用栈实现
void __QuickSortNor(int array[], int left, int right)
{
	std::stack<int> s;
	s.push(right);
	s.push(left);
	
	int _left;
	int _right;

	while (!s.empty())
	{
		_left = s.top;
		s.pop;
		_right = s.top;
		s.pop;

		if (_left >= _right)
		{
			continue;
		}

	}
	int d = Parition_2(array, _left, _right);

	//d + 1  right
	s.push(right);
	s.push(d + 1);

	//_left  d-1
	s.push(d - 1);
	s.push(_left);
}

/*

归并排序（合并排序）
时间复杂度  最好|平均|最坏  O(n*log(n))
空间复杂度 O(n)
稳定
外部排序（可以对硬盘上的数据进行归并）

递归：
假设两个数组有序，分治算法进行排序，合并
区间事左闭右开 array[left,mid) array[mid,right)
非递归：
先 1 vs 1---> 2 vs 2 --> 4 vs 4....

*/
void __MergeSort(int array[], int left, int right,int* extra)
{
	if (right == left + 1)
	{
		//剩余一个数，有序
		return;
	}
	if (left >= right)
	{
		//区间没有数
		return;
	}

	int mid = left + (right - left) / 2;
	//区间分成左右两个小区间
	//[left,min)
	//[mind,right)
	//先把两个小区间进行排序，分治算法，递归解决
	__MergeSort(array, left, mid,extra);
	__MergeSort(array, mid, right,extra);

	//左右小区间已经有序
	//合并有序数组
	Merge(array, left, mid, right,extra);
}


//合并有序数组
//array[left,mid)
//array[mid,right)
//时间复杂度 O(n)  
//空间复杂度 O(n)
void Merge(int array[], int left,int mid, int right,int* extra)
{
	//需要一个额外的空间去实现
	int size = right-left;
	//int* extra = (int*)malloc(sizeof(int)* size);

	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid&&right_index < right)
	{
		if (array[left_index] <= array[right_index])
		{
			extra[extra_index] = array[left_index];
			left_index++;
		}
		else
		{
			extra[extra_index] = array[right_index];
			right_index++;
		}
		extra_index++;
	}

	while (left_index < mid)
	{
		extra[extra_index++]=array[left_index];
	}

	while (right_index < mid)
	{
		extra[extra_index++] = array[right_index];
	}

	for (int i = 0; i < size; i++)
	{
		array[left + i] = extra_index[i];
	}
	//free(extra);

}

//供用一份空间 提高效率
void MergeSort(int array[],int size)
{
	int* extra = (int*)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}


void MergeSort(int array[], int size)
{
	int* extra = (int*)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size,extra);
	free(extra);
}



//合并排序 非递归写法
void MergeSortNor(int array[], int size)
{
	int* extra = (int*)malloc(sizeof(int)* size);
	for (int i = 1; i < size;i*=2)
	{
		for (int j = 0; j < size; j +=2i)
		{
			int left = j;
			int mid = left + i;
			if (mid >= size)
				continue;
			int right = mid + i;
			if (right >= size)
				right=size;
			Merge(array, left, right, extra);
		}
	}
	free(extra);
}