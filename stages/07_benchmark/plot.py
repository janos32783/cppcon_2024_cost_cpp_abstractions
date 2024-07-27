import pandas as pd
import matplotlib.pyplot as plt
import glob
import numpy as np

# some more colors: y, k, orange, purple, brown
# some more markers: X, *, p, H, 8

# Read CSV files
files = {
    "01_data_c.csv": ("num_funcs", 'o'),
    "01_data_cpp.csv": ("num_funcs", '^'),
    "01_data_classes.csv": ("num_funcs", '*'),
    "02_basic_data.csv": ("num_class", 's'),
    "02_template_data.csv": ("num_class", 'd'),
    "03_data.csv": ("num_class", 'v'),
    "04_dyn_data.csv": ("num_class", 'X'),
    "04_sta_data.csv": ("num_class", 'p')
}

# Prepare a dictionary to hold the data
data = {file: pd.read_csv(file) for file in files}

# Function to process data
def process_data(df, group_col):
    # Group by the specified column
    grouped = df.groupby(group_col)
    
    vals = []
    #for name, group in grouped:
    #    # Sort the compilation times
    #    sorted_comp_t = group['comp_t'].sort_values()
    #    # Discard the highest and lowest
    #    filtered_comp_t = sorted_comp_t[1:-1]
    #    # Calculate the mean of the remaining three
    #    mean_comp_t = filtered_comp_t.mean()
    #    vals.append((name, mean_comp_t))
    #for name, group in grouped:
    #    # Get the minimum compilation time
    #    min_comp_t = group['comp_t'].min()
    #    vals.append((name, min_comp_t))
    for name, group in grouped:
        # Calculate the median compilation time
        median_comp_t = group['comp_t'].median()
        vals.append((name, median_comp_t))
    
    return pd.DataFrame(vals, columns=[group_col, 'mean_comp_t'])

# Process all data
processed_data = {file: process_data(data[file], group_col) for file, (group_col, _) in files.items()}

# Plotting
plt.figure(figsize=(10, 6))

# Define colors and markers
colors = ['b', 'g', 'k', 'r', 'c', 'm', 'y', 'orange']
markers = ['o', '^', '*', 's', 'd', 'v', 'X', 'p']

for i, (file, (group_col, marker)) in enumerate(files.items()):
    plt.plot(
        processed_data[file][group_col], 
        processed_data[file]['mean_comp_t'], 
        label=file, 
        marker=marker, 
        color=colors[i], 
        linestyle='-', 
        markersize=8
    )

plt.xlabel('Number of Functions / Classes')
plt.ylabel('Mean Compilation Time (s)')
plt.title('Mean Compilation Time vs Number of Functions/Classes')
plt.legend()
plt.grid(True)
plt.show()