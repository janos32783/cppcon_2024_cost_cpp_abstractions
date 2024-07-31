import matplotlib.pyplot as plt
import numpy as np

types = ('original', 'improved')
runtimes = {
    'ticks': np.array([2725, 2179])
}
filename = "run_t.png"

width = 0.6
fig, ax = plt.subplots()

# Plot runtime bars
for label, rt in runtimes.items():
    p = ax.bar(types, rt, width, label=label)
    ax.bar_label(p, label_type='center')

ax.set_title('Runtime Performance')
plt.xlabel("Build")
plt.ylabel("Execution Time [ticks]")

my_dpi = 300
plt.savefig(filename, dpi=my_dpi)
