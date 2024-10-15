#include <iostream>

using namespace std;

int BestLocationToBlowBalls(int balls, int height, int *ans, int *coordinates);

int main()
{
    int balls, height, ans = 0;

    // input for balls qty and children's height
    cin >> balls >> height;

    // input for balls coordinates
    int coordinates[balls];
    for (int i = 0; i < balls; i++)
    {
        cin >> coordinates[i];
    }

    cout << BestLocationToBlowBalls(balls, height, &ans, coordinates) << ' ' << ans;

    return 0;
}

int BestLocationToBlowBalls(int balls, int height, int *ans, int *coordinates)
{
    if (height == 0) return 0;
    if (height == 1)
    {
        *ans = 1;
        return coordinates[0] - height;
    }

    int sum = 0, counter = 1, coord = 999999;

    for (int i = 0; i < balls; i++)
    {
        int j = i;
        while (sum < height && j < balls - 1)
        {
            sum += coordinates[j+1] - coordinates[j];
            counter++;
            j++;
        }
        if (sum > height) counter--;

        if (*ans < counter)
        {
            if (sum == height)
            {
                coord = coordinates[j] - height;
            }
            else coord = coordinates[j-1] - height;

            *ans = counter;
        }
        sum = 0;
        counter = 1;
    }
    return coord;
}