
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergesort(int* Arr, int l, int r)
{
	if (l == r) return;
	int mid = (l + r) / 2;
	mergesort(Arr, l, mid);
	mergesort(Arr, mid + 1, r);
	int i = l;
	int j = mid + 1;
	int* tmp = (int*)malloc((r - l + 1) * sizeof(int));
	for (int step = 0; step < r - l + 1; step++)
	{
		if ((j > r) || ((i <= mid) && (Arr[i] < Arr[j])))
		{
			tmp[step] = Arr[i];
			i++;
		}
		else
		{
			tmp[step] = Arr[j];
			j++;
		}
	}
	for (int s = 0; s < r - l + 1; s++)
		Arr[s + l] = tmp[s];
	free(tmp);
}



void filewrite(int *Arr, int n, int m)
{
	FILE* f;
	char s[10];
	sprintf(s, "%s%d%s", "a", m, ".dat");
	f = fopen(s, "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d %d\n", i, Arr[i]);
	}
	fclose(f);
}


int main()
{
	int n, m;
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	int* Arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand();
	}
	mergesort(Arr, 0, n - 1);
	for (int j = 1; j <= m; j++)
	{
		filewrite(Arr, n, j);
	}

	free(Arr);
}
