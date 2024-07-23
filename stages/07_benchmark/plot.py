import matplotlib.pyplot as plt 
import pandas as pd
import numpy as np
import sys

N = sys.argv[1]

my_dpi=200

data = pd.read_csv("data_" + N + ".csv")

fig, axs = plt.subplots(2, 2)

fig.suptitle('evaluation')
fig.set_size_inches(20, 15)

axs[0, 0].plot(data['num_calls'].values, data['c_size_o'].values, label="C", color='g', linestyle='solid', marker=',')
axs[0, 0].plot(data['num_calls'].values, data['cpp_size_o'].values, label="C++", color='r', linestyle='solid', marker='x')
axs[0, 0].plot(data['num_calls'].values, data['cpp_encapsulation_size_o'].values, label="C++ (encapsulation)", color='b', linestyle='solid', marker='v')
axs[0, 0].plot(data['num_calls'].values, data['cpp_static_poly_size_o'].values, label="C++ (static polymorphism)", color='y', linestyle='solid', marker='.')
axs[0, 0].plot(data['num_calls'].values, data['cpp_dynamic_poly_size_o'].values, label="C++ (dynamic polymorphism)", color='m', linestyle='solid', marker='s')
axs[0, 0].set(xlabel='number of function calls', ylabel='size overhead (bytes)')
axs[0, 0].legend(loc="upper left")

axs[0, 1].plot(data['num_calls'].values, data['c_comp_t'].values, label="C", color='g', linestyle='solid', marker=',')
axs[0, 1].plot(data['num_calls'].values, data['cpp_comp_t'].values, label="C++", color='r', linestyle='solid', marker='x')
axs[0, 1].plot(data['num_calls'].values, data['cpp_encapsulation_comp_t'].values, label="C++ (encapsulation)", color='b', linestyle='solid', marker='v')
axs[0, 1].plot(data['num_calls'].values, data['cpp_static_poly_comp_t'].values, label="C++ (static polymorphism)", color='y', linestyle='solid', marker='.')
axs[0, 1].plot(data['num_calls'].values, data['cpp_dynamic_poly_comp_t'].values, label="C++ (dynamic polymorphism)", color='m', linestyle='solid', marker='s')
axs[0, 1].set(xlabel='number of function calls', ylabel='compilation time (s)')
axs[0, 1].legend(loc="upper left")

axs[1, 0].plot(data['num_calls'].values, data['c_link_t'].values, label="C", color='g', linestyle='solid', marker=',')
axs[1, 0].plot(data['num_calls'].values, data['cpp_link_t'].values, label="C++", color='r', linestyle='solid', marker='x')
axs[1, 0].plot(data['num_calls'].values, data['cpp_encapsulation_link_t'].values, label="C++ (encapsulation)", color='b', linestyle='solid', marker='v')
axs[1, 0].plot(data['num_calls'].values, data['cpp_static_poly_link_t'].values, label="C++ (static polymorphism)", color='y', linestyle='solid', marker='.')
axs[1, 0].plot(data['num_calls'].values, data['cpp_dynamic_poly_link_t'].values, label="C++ (dynamic polymorphism)", color='m', linestyle='solid', marker='s')
axs[1, 0].set(xlabel='number of function calls', ylabel='link time (s)')
axs[1, 0].legend(loc="upper left")

axs[1, 1].plot(data['num_calls'].values, data['c_exec_t'].values, label="C", color='g', linestyle='solid', marker=',')
axs[1, 1].plot(data['num_calls'].values, data['cpp_exec_t'].values, label="C++", color='r', linestyle='solid', marker='x')
axs[1, 1].plot(data['num_calls'].values, data['cpp_encapsulation_exec_t'].values, label="C++ (encapsulation)", color='b', linestyle='solid', marker='v')
axs[1, 1].plot(data['num_calls'].values, data['cpp_static_poly_exec_t'].values, label="C++ (static polymorphism)", color='y', linestyle='solid', marker='.')
axs[1, 1].plot(data['num_calls'].values, data['cpp_dynamic_poly_exec_t'].values, label="C++ (dynamic polymorphism)", color='m', linestyle='solid', marker='s')
axs[1, 1].set(xlabel='number of function calls', ylabel='execution time (ns)')
axs[1, 1].legend(loc="upper left")

plt.savefig('plt_cpp_v_cpp' + N + '.png', dpi=my_dpi)

