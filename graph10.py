import matplotlib.pyplot as plt

values = [
(1000,472 ),
(2000,928 ),
(3000,1385 ),
(4000,1895 ),
(5000,2510 )
      
]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()