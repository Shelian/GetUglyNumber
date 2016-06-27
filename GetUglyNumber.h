#ifndef __GETUGLYNUMBER_H__
#define __GETUGLYNUMBER_H__

//方法一: --->算法简单，但是速度太慢
bool IsUglyNum(int num)
{
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;

	return (num == 1) ? true : false;
}


int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;

	int count = 0;
	int num = 0;
	while (count < index)
	{
		++num;

		if (IsUglyNum(num))
			count++;
	}

	return num;
}

int Min(int num1, int num2, int num3);
//方法二： --->用空间换时间
int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
		return 0;

	int* pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int nextUglyNumber = 1;

	int* UglyNumber2 = pUglyNumber;
	int* UglyNumber3 = pUglyNumber;
	int* UglyNumber5 = pUglyNumber;

	while (nextUglyNumber < index)
	{
		int min = Min(*UglyNumber2 * 2, *UglyNumber3 * 3, *UglyNumber5 * 5);
		pUglyNumber[nextUglyNumber] = min;

		while (*UglyNumber2 * 2 <= pUglyNumber[nextUglyNumber])
			++UglyNumber2;
		while (*UglyNumber3 * 3 <= pUglyNumber[nextUglyNumber])
			++UglyNumber3;
		while (*UglyNumber5 * 5 <= pUglyNumber[nextUglyNumber])
			++UglyNumber5;

		++nextUglyNumber;
	}

	int ugly = pUglyNumber[nextUglyNumber - 1];
	delete[] pUglyNumber;

	return ugly;
}

int Min(int num1,int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;

	return (min < num3) ? min : num3;
}



void TestUgly()
{
	//cout << GetUglyNumber(1500) << endl;
	cout << GetUglyNumber_Solution2(1500) << endl;

}


#endif //__GETUGLYNUMBER_H__