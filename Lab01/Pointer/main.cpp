#include <iostream>
using namespace std;

// Cau 1:
void inputArray(int*& a, int& n)
{
	cout << "Nhap vao so luong phan tu trong mang:";
	cin >> n;
	a = new int[n];
	cout << "Nhap cac phan tu trong mang: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << "Nhap phan tu " << i + 1 << " :";
		cin >> a[i];
	}
}


// Cau 2:
void deallocateArray(int* &a)
{
	delete[] a;
}


// Cau 3
void printArray(int *a, int n) 
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	
}


//cau 4:
int findMin(int *a, int n)
{
	int min = a[0];
	for (size_t i = 0; i < n; i++)
	{
		if(a[i] < min) min = a[i];
	}
	return min;
}


//Cau 5:
int findMaxModulus(int *a, int n)
{
	int min = abs(a[0]);
	int id = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (abs(a[i]) < min)
		{
			min = abs(a[i]);
			id = i;
		}
	}
	return id;
}


// Cau 6:
bool isAscending(int *a, int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		if(a[i] > a[i+1]) return false;
	}
	return true;
}


// cau 7:
int sumOfArray(int *a, int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

//Cau 8:
bool isPrime(int n)
{
	if (n<2) return false;
	if (n==2) return true;
	for (size_t i = 0; i < sqrt(n); i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
int countPrime(int *a, int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		if(isPrime(a[i])) sum += a[i];
	}
	return sum;
}


// Cau 9:
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void revertArray(int *a, int n)
{
	for (size_t i = 0; i < n/2; i++)
	{
		swap(a[i], a[n - 1 - i]);
	}
}


// Cau 10:
int LinearSearch(int *a, int n, int key)
{
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] == key) return i;
	}
	return -1;
}


//Cau 11:
int sentinelLinearSearch(int *a, int n, int key)
{
	int lastElement = a[n-1];
	a[n-1] = key;

	for (size_t i = 0; i++;)
	{
		if(a[i] == key)
			return i;
	}

	if (lastElement == key)
		return n - 1;
	return -1;
}


// Cau 12
int BinarySearch(int *a, int n, int key)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] < key)
			left = mid + 1;
		else if(a[mid] > key) 
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}


// Cau 13
int recursiveBinarySearch(int *a, int left, int right, int key)
{
	if(left < right)
	{
		int mid = left + (right - left) / 2;
		if(a[mid] == key)
			return mid;
		if (a[mid] > key)
			return recursiveBinarySearch(a, left, mid-1, key);
		return recursiveBinarySearch(a, mid +1 , right, key);
	}
	return -1;
}


int main()
{
	return 1;
}