import matplotlib.pyplot as plt

# Input sizes and corresponding times in nanoseconds
input_sizes = [10, 50, 100, 200, 500]
time_weight = [10750, 68210, 276650, 880390, 5159290]  # Replace these values with your actual data
time_profit = [6940, 67530, 282020, 782469, 5568139]  # Replace these values with your actual data
time_ratio = [5760, 65230, 253610, 983030, 5468410]   # Replace these values with your actual data

# Plotting the data
plt.figure(figsize=(10, 6))
plt.plot(input_sizes, time_weight, marker='o', label='Time (Weight)')
plt.plot(input_sizes, time_profit, marker='o', label='Time (Profit)')
plt.plot(input_sizes, time_ratio, marker='o', label='Time (Ratio)')

# Adding labels and title
plt.xlabel('Input Size')
plt.ylabel('Time (ns)')
plt.title('Knapsack Algorithm Comparison')
plt.legend()

# Display the plot
plt.show()