import matplotlib.pyplot as plt

values = [
(500 , 0),
(1000 , 816100),
(1500 , 754800),
(2000 , 1180600),
(2500 , 1770300),
(3000 , 2074000),
(3500 , 3542700),
(4000 , 4711700),
(4500 , 5433500),
(5000 , 10442500)
]



comparison_values = [
(500 , 0),
(1000 , 342500),
(1500 , 505100),
(2000 , 1162300),
(2500 , 1955800),
(3000 , 3162800),
(3500 , 3745800),
(4000 , 4803900),
(4500 , 5266100),
(5000 , 6497600)

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