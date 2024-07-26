import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import LightSource
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

# Create the hillshading effect
ls = LightSource(azdeg=315, altdeg=45)
rgb = ls.shade(z_grid, plt.cm.viridis)

# Plotting the data
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the surface with hillshading
surf = ax.plot_surface(x_grid, y_grid, z_grid, facecolors=rgb, rstride=1, cstride=1, antialiased=True)

# Labels and title
ax.set_xlabel('Number of Functions')
ax.set_ylabel('Number of Calls')
ax.set_zlabel('Computation Time')
ax.set_title('3D Hillshading Plot')

# Show the plot
plt.show()
