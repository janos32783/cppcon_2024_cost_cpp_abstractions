import matplotlib.pyplot as plt
import numpy as np


types = ('C', 'no RTTI', 'RTTI', 'no RTTI with virt.')
binaries = {
    'text': np.array([716, 776, 2208, 872]),
    'bss': np.array([1568, 1568, 1580, 1568]),
}
filename = "bin_size.png"

width = 0.4
fig, ax = plt.subplots()
bottom = np.zeros(len(types))

for bin, bin_count in binaries.items():
    p = ax.bar(types, bin_count, width, label=bin, bottom=bottom)
    bottom += bin_count

    ax.bar_label(p, label_type='center')

ax.set_title('binary size')
ax.legend(bbox_to_anchor=(1, 1.15))
plt.xlabel("build")
plt.ylabel("size [bytes]")

my_dpi=200
plt.savefig(filename, dpi=my_dpi)