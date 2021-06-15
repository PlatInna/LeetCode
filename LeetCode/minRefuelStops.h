/*
A car travels from a starting position to a destination which is target miles east of the starting position.
Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles 
east of the starting position, and has station[i][1] liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter 
of gas per 1 mile that it drives.
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot 
reach the destination, return -1.
Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches 
the destination with 0 fuel left, it is still considered to have arrived.

from leetcode:

Approach 1: Dynamic Programming
Intuition
Let's determine dp[i], the farthest location we can get to using i refueling stops. This is motivated by the fact that we want the smallest i 
for which dp[i] >= target.
Algorithm
Let's update dp as we consider each station in order. With no stations, clearly we can get a maximum distance of startFuel with 0 refueling stops.
Now let's look at the update step. When adding a station station[i] = (location, capacity), any time we could reach this station with t refueling 
stops, we can now reach capacity further with t+1 refueling stops.
For example, if we could reach a distance of 15 with 1 refueling stop, and now we added a station at location 10 with 30 liters of fuel, then 
we could potentially reach a distance of 45 with 2 refueling stops.
Complexity Analysis
Time Complexity: O(N^2), where N is the length of stations.
Space Complexity: O(N), the space used by dp.

def minRefuelStops(self, target, startFuel, stations):
        dp = [startFuel] + [0] * len(stations)
        for i, (location, capacity) in enumerate(stations):
            for t in xrange(i, -1, -1):
                if dp[t] >= location:
                    dp[t+1] = max(dp[t+1], dp[t] + capacity)

        for i, d in enumerate(dp):
            if d >= target: return i
        return -1

Approach 2: Heap
Intuition
When driving past a gas station, let's remember the amount of fuel it contained. We don't need to decide yet whether to fuel up here or not - 
for example, there could be a bigger gas station up ahead that we would rather refuel at. When we run out of fuel before reaching the next station, 
we'll retroactively fuel up: greedily choosing the largest gas stations first. This is guaranteed to succeed because we drive the largest distance 
possible before each refueling stop, and therefore have the largest choice of gas stations to (retroactively) stop at.
Algorithm
pq ("priority queue") will be a max-heap of the capacity of each gas station we've driven by. We'll also keep track of tank, our current fuel.
When we reach a station but have negative fuel (ie. we needed to have refueled at some point in the past), we will add the capacities of the 
largest gas stations we've driven by until the fuel is non-negative.If at any point this process fails (that is, no more gas stations), then the 
task is impossible.
Complexity Analysis
Time Complexity: O(NlogN), where N is the length of stations.
Space Complexity: O(N), the space used by pq.

def minRefuelStops(self, target, tank, stations):
        pq = []  # A maxheap is simulated using negative values
        stations.append((target, float('inf')))

        ans = prev = 0
        for location, capacity in stations:
            tank -= location - prev
            while pq and tank < 0:  # must refuel in past
                tank += -heapq.heappop(pq)
                ans += 1
            if tank < 0: return -1
            heapq.heappush(pq, -capacity)
            prev = location

        return ans
*/



#pragma once

#include <vector>

std::vector<std::vector<int>> v;
int res = minRefuelStops(20, 7, v);

int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
    v = { {5, 2}, {9, 7}, {10, 1}, {11, 25}, {13, 1}, {16, 2} };
    return 0;
}
