#include <iostream>
using namespace std;

int main()
{
    int marks[3][5];
    int total[3] = {
        0,
    };
    float subavg[5] = {0};

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter marks of Student " << i + 1 << " in 5 subjects: " << endl;
        for (int j = 0; j < 5; j++)
        {
            cin >> marks[i][j];
            total[i] += marks[i][j];
            subavg[j] += marks[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        subavg[i] = subavg[i] / 3;
    }

    cout << "Total marks of each student:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Marks of student" << i + 1 << ": " << total[i] << endl;
    }

    cout << "Average Marks of each subject" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject" << i + 1 << ":" << subavg[i] << endl;
    }
    return 0;
}