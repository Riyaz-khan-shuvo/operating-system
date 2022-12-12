#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
					 int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;
	// calculating waiting time
	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);

	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
	}

	cout << "Average waiting time = "
		 << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		 << (float)total_tat / (float)n;
}

int main()
{
	int n;
	printf("Enter the size of processes : ");
	scanf("%d", &n);
	int processes[n];

	printf("Enter the processes : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &processes[i]);
	}
	// Burst time of all processes
	int burst_time[n];
	printf("Enter the bust time : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &burst_time[i]);
	}
	findavgTime(processes, n, burst_time);
	return 0;
}
