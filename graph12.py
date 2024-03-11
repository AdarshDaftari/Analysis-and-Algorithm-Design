import matplotlib.pyplot as plt

values = [
( 1000, 5811 ),
( 2000, 8220 ),
( 3000, 12349 ),
( 4000, 32460 ),
( 5000, 29640 ),
( 6000, 35400 ),
( 7000, 42500 ),
( 8000, 46580 ),
( 9000, 40790 ),
( 10000, 60110 )
]



comparison_values = [
( 1000, 5811 ),
( 2000, 8220 ),
( 3000, 12349 ),
( 4000, 32460 ),
( 5000, 29640 ),
( 6000, 35400 ),
( 7000, 42500 ),
( 8000, 46580 ),
( 9000, 40790 ),
( 10000, 60110 )

]

x_values, y_values = zip(*values)

x_comparison, y_comparison = zip(*comparison_values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.plot(x_comparison, y_comparison, marker='s', linestyle='--', color='r', label='Comparison Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()