class Solution
{
public:
        // Scheduling Algorithm: At a point of time, schedule the task with most number of instances remaining and which is not in the last n tasks scheduled.
    // In this problem, we need to find the minimum time required to execute. So, no need to schedule the jobs.
    // Minimum Time Required: len(tasks) + minimum no. of idle slots
    int leastInterval(vector<char>& tasks, int n)
    {
        if(n == 0) return tasks.size();

        int maxInstancesOfATask = INT_MIN;
        int numberOfTasksWithMaxInstances = 0;

        // Find the Tasks with Maximum Number of Instances.
        vector<int> taskCount(26, 0);
        for(int i = 0; i < tasks.size(); ++i)
        {
            ++taskCount[(int)tasks[i] - 65];

            if(taskCount[(int)tasks[i] - 65] > maxInstancesOfATask)
            {
                maxInstancesOfATask = taskCount[(int)tasks[i] - 65];
                numberOfTasksWithMaxInstances = 1;
            }
            else if(taskCount[(int)tasks[i] - 65] == maxInstancesOfATask)
                ++numberOfTasksWithMaxInstances;
        }

        // If we arrange these tasks with maximum instances with minimum separation of n between them:
        // Consider A-3, B-3, C-2, D-1 and n = 3:
        // (A  ? ? ?  A  ? ? ?  A) => (A B  ? ?  A B  ? ?  A B) => A B C D A B C ? A B
        // 1 Idle slot
        int emptyPartCount = maxInstancesOfATask - 1;
        int emptyPartLength = n - (numberOfTasksWithMaxInstances - 1);
        int emptySlots =  emptyPartCount * emptyPartLength;
        int availableTasks = tasks.size() - maxInstancesOfATask * numberOfTasksWithMaxInstances;
        int idleSlots = std::max(0, emptySlots - availableTasks);
        
        return tasks.size() + idleSlots;
    }
};