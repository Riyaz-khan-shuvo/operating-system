#include <bits/stdc++.h>
using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])
{
	int service_time[n];
	service_time[0] = at[0];
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n; i++)
	{
		// Add burst time of previous processes
		service_time[i] = service_time[i - 1] + bt[i - 1];

		wt[i] = service_time[i] - at[i];

		if (wt[i] < 0)
			wt[i] = 0;
	}
}

void findTurnAroundTime(int processes[], int n, int bt[],
						int wt[], int tat[])
{

	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n];

	findWaitingTime(processes, n, bt, wt, at);

	findTurnAroundTime(processes, n, bt, wt, tat);

	int total_wt = 0, total_tat = 0;
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i] + at[i];
	}

	cout << "Average waiting time = "
		 << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		 << (float)total_tat / (float)n;
}

int main()
{

	int n;
	printf("Enter the size of process : ");
	scanf("%d", &n);
	int processes[n];
	printf("Enter the process : ");

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &processes[i]);
	}

	// Burst time of all processes
	printf("Enter the Burst Time : ");
	int burst_time[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &burst_time[i]);
	}
	// Arrival time of all processes
	printf("Enter the Arrival Time : ");
	int arrival_time[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arrival_time[i]);
	}

	findavgTime(processes, n, burst_time, arrival_time);

	return 0;
}
