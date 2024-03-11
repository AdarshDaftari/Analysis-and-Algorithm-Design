import matplotlib.pyplot as plt

# Data from the C++ program (input size vs execution time in seconds)
input_sizes = [1000, 5000, 10000, 50000, 100000]
best_case_times = [6e-06, 2e-06, 1e-06, 3e-06, 2e-06]  # Replace with your actual data
worst_case_times = [1e-06, 1e-06, 1e-06, 0, 1e-06]  # Replace with your actual data

# Convert times to nanoseconds for better readability
best_case_times_ns = [time * 1e9 for time in best_case_times]
worst_case_times_ns = [time * 1e9 for time in worst_case_times]

# Plotting the graph for best case
plt.plot(input_sizes, best_case_times_ns, label='Best Case', marker='o', linestyle='-', color='b')

# Plotting the graph for worst case
plt.plot(input_sizes, worst_case_times_ns, label='Worst Case', marker='s', linestyle='-', color='r')

# Adding labels and legend
plt.title('Input Size vs Execution Time (Binary Search)')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.legend()
plt.grid(True)

# Display the graph
plt.show()