#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of Processes: ";
    cin >> n;
    int BT[n];
    int WT[n];
    int TAT[n];
    double avrWT = 0;
    double avrTAT = 0;

    cout << "Enter Burst Time: ";
    for (int i = 0; i < n; i++) {
        cin >> BT[i];
    }

    WT[0] = 0;
    for (int i = 1; i < n; i++) {
        WT[i] = WT[i - 1] + BT[i - 1];
    }

    for (int i = 0; i < n; i++) {
        TAT[i] = WT[i] + BT[i];
    }

    for (int i = 0; i < n; i++) {
        avrWT += WT[i];
        avrTAT += TAT[i];
    }

    avrWT /= n;
    avrTAT /= n;

    cout << "Process\tBurst Time\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t  " << BT[i] << "\t\t " << TAT[i] << "\t" << WT[i] << endl;
    }

    cout << "Average Waiting Time: " << avrWT << endl;
    cout << "Average Turn Around Time: " << avrTAT << endl;

    cout << "Gantt Chart IS: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|0|";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "|" << TAT[i];
        if (i < n - 1) {
            cout << "|";
        }
    }
    cout << "|" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
