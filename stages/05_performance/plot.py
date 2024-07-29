import matplotlib.pyplot as plt
import numpy as np

types = ('original', 'improved')
binaries = {
    'text': np.array([9688, 7660]),
    'data': np.array([60, 56]),
    'bss': np.array([1916, 1856]),
}
filename = "bin_size.png"

width = 0.4
fig, ax = plt.subplots()
bottom = np.zeros(len(types))

# Dictionary to store the total heights of the bars
total_heights = np.zeros(len(types))

for bin, bin_count in binaries.items():
    p = ax.bar(types, bin_count, width, label=bin, bottom=bottom)
    bottom += bin_count
    total_heights += bin_count

    ax.bar_label(p, label_type='center')

# Adding the sum of the segments at the top of each bar
for i, total_height in enumerate(total_heights):
    ax.text(i, total_height, f'{int(total_height)}', ha='center', va='bottom')

ax.set_title('binary size')
ax.legend(bbox_to_anchor=(0.6, 0.6))
plt.xlabel("build")
plt.ylabel("size [bytes]")

my_dpi = 300
plt.savefig(filename, dpi=my_dpi)
