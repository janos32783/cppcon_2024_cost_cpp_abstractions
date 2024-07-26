import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
from scipy.interpolate import griddata

# Read the CSV data from a file
file_path = 'data.csv'  # Replace with the path to your CSV file
data = pd.read_csv(file_path)

# Extract the data into variables
x = data['num_funcs']
y = data['num_calls']
z = data['comp_t']

# Create a DataFrame for easy handling of duplicates
df = pd.DataFrame({'x': x, 'y': y, 'z': z})

# Aggregate z-values for the same x-y pairs by taking the mean
df_aggregated = df.groupby(['x', 'y']).mean().reset_index()

# Extract the aggregated data into variables
x = df_aggregated['x']
y = df_aggregated['y']
z = df_aggregated['z']

# Create a 2D grid of x, y values
x_unique = np.linspace(x.min(), x.max(), 100)
y_unique = np.linspace(y.min(), y.max(), 100)
x_grid, y_grid = np.meshgrid(x_unique, y_unique)

# Interpolate the z values to the 2D grid using nearest neighbor interpolation
z_grid = griddata((x, y), z, (x_grid, y_grid), method='nearest')

# Plot the data
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the 3D surface
#ax.plot_surface(x_grid, y_grid, z_grid, edgecolor='royalblue', lw=0.5, rstride=8, cstride=8, alpha=0.3)

# Plot projections of the contours for each dimension
ax.contourf(x_grid, y_grid, z_grid, zdir='z', offset=z_grid.min() - 0, cmap='coolwarm')
ax.contourf(x_grid, y_grid, z_grid, zdir='x', offset=x_grid.min() - 0, cmap='coolwarm')
ax.contourf(x_grid, y_grid, z_grid, zdir='y', offset=y_grid.max() + 0, cmap='coolwarm')

# Set limits and labels
ax.set(xlim=(x_grid.min() - 0, x_grid.max() + 0), ylim=(y_grid.min() - 0, y_grid.max() + 0), zlim=(z_grid.min() - 0, z_grid.max() + 0),
       xlabel='Number of Functions', ylabel='Number of Calls', zlabel='Computation Time')

plt.show()
