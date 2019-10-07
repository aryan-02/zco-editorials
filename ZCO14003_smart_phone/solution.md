# Smart Phone
Category: Sorting

Problem link: https://www.codechef.com/ZCOPRAC/problems/ZCO14003
## Solution
Sort the array. If you do that, the number of people who will buy the app at the price equal to the ``ith`` person's budget will be ``N - i``. After sorting, we can brute-force to maximize the value ``budget[i] *  (N - i)`` over all valid ``i`` using a ``for`` loop.
