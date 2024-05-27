#include <stdio.h>
#include <stdlib.h>

// Define the Job structure
typedef struct {
    char id[3]; // Job ID
    int deadline; // Job deadline
    int profit; // Job profit
} Job;

// Function to compare two jobs based on profit (used for sorting)
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

// Function to find the maximum deadline in the jobs array
int findMaxDeadline(Job jobs[], int n) 
{
	int i;
    int max = jobs[0].deadline;
    for (i = 1; i < n; i++) 
	{
        if (jobs[i].deadline > max) 
		{
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to perform job sequencing to maximize profit
void jobSequencing(Job jobs[], int n) 
{
    // Sort jobs based on profit in descending order
    qsort(jobs, n, sizeof(Job), compare);
	int i, j;
    int dmax = findMaxDeadline(jobs, n);
    int timeslot[dmax + 1]; // Array to keep track of free time slots
    for (i = 0; i <= dmax; i++) {
        timeslot[i] = -1; // Initialize all slots as free
    }

    int totalProfit = 0;
    printf("Required jobs: ");
    
    // Iterate through all given jobs
    for (i = 0; i < n; i++) 
	{
        // Find a free time slot for this job (from its deadline to 1)
        for (j = jobs[i].deadline; j > 0; j--) 
		{
            if (timeslot[j] == -1) 
			{
                timeslot[j] = i; // Assign job to this time slot
                totalProfit += jobs[i].profit;
                printf("%s ", jobs[i].id);
                break;
            }
        }
    }

    printf("\nMaximum profit: %d\n", totalProfit);
}

int main() 
{
    Job jobs[] = {{"j1", 2, 100}, {"j2", 1, 19}, {"j3", 2, 27}, {"j4", 1, 25}, {"j5", 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
	int i;
    printf("Job\tDeadline\tProfit\n");
    for (i = 0; i < n; i++) 
	{
        printf("%s\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    int dmax = findMaxDeadline(jobs, n);
    printf("\nDmax: %d\n", dmax);

    jobSequencing(jobs, n);

    return 0;
}
