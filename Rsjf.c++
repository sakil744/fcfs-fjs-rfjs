#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int pr[n], at[n], bt[n], rt[n], wt[n], tat[n];
    double totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        pr[i] = i + 1;
    }

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " Arrival Time: ";
        cin >> at[i];
        cout << "P" << i + 1 << " Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i];  // Remaining time is initially the burst time
    }

    int complete = 0, currentTime = 0;
    while (complete != n) {
        int shortest = -1, minm = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0 && rt[i] < minm) {
                minm = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            int finishTime = currentTime + 1;
            wt[shortest] = finishTime - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
            tat[shortest] = finishTime - at[shortest];
        }

        currentTime++;
    }

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n";
    for (int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
        cout << "P" << pr[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turn Around Time: " << totalTAT / n << endl;
    cout << "Gantt Chart IS: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|0|";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "|" << tat[i];
        if (i < n - 1) {
            cout << "|";
        }
    }
    cout << "|" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
