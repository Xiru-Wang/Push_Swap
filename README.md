# Push_Swap
![pushswap](https://github.com/Xiru-Wang/Push_Swap/assets/79924696/1c4971da-68d5-4ebc-955c-6ffda88afa38)

<img width="150" alt="sort 100 numbers" src="https://github.com/Xiru-Wang/Push_Swap/assets/79924696/79d248c4-7cba-4b84-a21b-43d803e23715">
Result to sort 100 numbers on average.
<img width="203" alt="sort 500 numbers" src="https://github.com/Xiru-Wang/Push_Swap/assets/79924696/c71f71b5-c52e-4f7a-96db-b4caea5fda06">
Result to sort 500 numbers on average.

# Solution
My solution combines those two approaches.
![9](https://github.com/Xiru-Wang/Push_Swap/assets/79924696/2eef0518-cea6-4541-96c4-2dadb12dc856)
![10](https://github.com/Xiru-Wang/Push_Swap/assets/79924696/5d4eecf0-7cad-4ed8-97ef-29a9da1e4695)

1. Calculate average value dynamicly, if the first node is a is below average, push to b, otherwise, rotate to bottom. Repeat till 5 nodes left in stack a.
2. Using linked list, each node in b will have the "target" in a, "target" is the node contains smallest but bigger number than the node in stack b. Thus, when we push b to a, the smaller value will be on top of the bigger one.

Reference:
Explains the logic of pushing below averages, and finding the "best friend":
https://github.com/duarte3333/Push_Swap
Explains double linkedlist and find the "cheapest nodes":
https://github.com/suspectedoceano/push_swap/tree/main
