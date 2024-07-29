import pandas as pd
import matplotlib.pyplot as plt
import glob
import numpy as np

# some more colors: y, k, orange, purple, brown
# some more markers: X, *, p, H, 8

# Read CSV files
files = [
    { "plot" : True,     "filename" : "01_data_c.csv",           "group_by" : "num_funcs", "label" : "plain functions (C)" },
    { "plot" : True,     "filename" : "01_data_cpp.csv",         "group_by" : "num_funcs", "label" : "plain functions (C++)" },
    { "plot" : True,     "filename" : "01_data_inlined_c.csv",   "group_by" : "num_funcs", "label" : "static inline functions (C)" },
    { "plot" : True,     "filename" : "01_data_inlined_cpp.csv", "group_by" : "num_funcs", "label" : "static inline functions (C++)" },
    { "plot" : True,     "filename" : "01_data_classes.csv",     "group_by" : "num_funcs", "label" : "functions wrapped in classes (C++)" },
    { "plot" : False,     "filename" : "02_basic_data.csv",       "group_by" : "num_class", "label" : "encapsulation (basic)" },
    { "plot" : False,     "filename" : "02_template_data.csv",    "group_by" : "num_class", "label" : "encapsulation (template)" },
    { "plot" : False,     "filename" : "03_data.csv",             "group_by" : "num_class", "label" : "inheritance" },
    { "plot" : False,     "filename" : "04_dyn_data.csv",         "group_by" : "num_class", "label" : "dynamic polymorphism" },
    { "plot" : False,     "filename" : "04_sta_data.csv",         "group_by" : "num_class", "label" : "static polymorphism" }
]

# Prepare a dictionary to hold the data
data = []
for file in files:
    df = pd.read_csv(file["filename"])
    grouped = df.groupby(file["group_by"])
    vals = []
    for name, group in grouped:
        sorted_comp_t = group['comp_t'].sort_values()
        filtered_comp_t = sorted_comp_t[3:-3]
        mean_comp_t = filtered_comp_t.mean()
        vals.append((name, mean_comp_t))
    data.append(pd.DataFrame(vals, columns=[file["group_by"], 'mean_comp_t']))

# Plotting
plt.figure(figsize=(10, 6))

# Define colors and markers
colors = ['b', 'g', 'purple', 'brown', 'k', 'r', 'c', 'm', 'y', 'orange']
markers = ['o', '^', 'H', '8', '*', 's', 'd', 'v', 'X', 'p']

for i in range(len(data)):
    if files[i]["plot"] :
        plt.plot(
            data[i][files[i]["group_by"]], 
            data[i]['mean_comp_t'], 
            label=files[i]["label"], 
            marker=markers[i], 
            color=colors[i], 
            linestyle='-', 
            markersize=4
        )

#plt.axis([0, 200, 0, 1.8])
plt.xlabel('Number of Functions / Classes')
plt.ylabel('Compilation Time (s)')
plt.title('Compilation Time vs Number of Functions/Classes')
plt.legend()
plt.grid(True)
plt.show()