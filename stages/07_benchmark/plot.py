import pandas as pd
import matplotlib.pyplot as plt

groups = [
    { "id" : "a", "filename" : "functions_0", "y" : 2.5 },
    { "id" : "b", "filename" : "functions_1", "y" : 2.5 },
    { "id" : "c", "filename" : "functions_2", "y" : 2.5 },
    { "id" : "d", "filename" : "functions_3", "y" : 2.5 },
    { "id" : "e", "filename" : "encapsulation_0", "y" : 0.3 },
    { "id" : "f", "filename" : "encapsulation_1", "y" : 0.3 },
    { "id" : "g", "filename" : "encapsulation_2", "y" : 0.3 },
    { "id" : "h", "filename" : "polymorphism_0", "y" : 0.8 },
    { "id" : "i", "filename" : "polymorphism_1", "y" : 0.8 }
]

styles = [
    { "color" : "b"      , "marker" : "o" },
    { "color" : "g"      , "marker" : "^" },
    { "color" : "purple" , "marker" : "H" },
    { "color" : "brown"  , "marker" : "8" },
    { "color" : "k"      , "marker" : "*" },
    { "color" : "r"      , "marker" : "s" },
    { "color" : "c"      , "marker" : "d" },
    { "color" : "m"      , "marker" : "v" },
    { "color" : "y"      , "marker" : "X" },
    { "color" : "orange" , "marker" : "p" },
]

dpi=300

files = [
    { "groups" : "abcd", "filename" : "results/pc/01_data_c.csv", "group_by" : "num_funcs", "label" : "plain functions (C)", "style_id" : 0 },
    { "groups" : "bcd", "filename" : "results/pc/01_data_cpp.csv", "group_by" : "num_funcs", "label" : "plain functions (C++)", "style_id" : 1 },
    { "groups" : "", "filename" : "results/pc/01_data_inlined_c.csv", "group_by" : "num_funcs", "label" : "static inline functions (C)", "style_id" : 2 },
    { "groups" : "", "filename" : "results/pc/01_data_inlined_cpp.csv", "group_by" : "num_funcs", "label" : "static inline functions (C++)", "style_id" : 3 },
    { "groups" : "cd", "filename" : "results/pc/01_data_classes.csv", "group_by" : "num_funcs", "label" : "functions wrapped in classes (C++)", "style_id" : 4 },
    { "groups" : "efg", "filename" : "results/pc/02_basic_data.csv", "group_by" : "num_class", "label" : "encapsulation (basic)", "style_id" : 5 },
    { "groups" : "fg", "filename" : "results/pc/02_template_data.csv", "group_by" : "num_class", "label" : "encapsulation (template)", "style_id" : 6 },
    { "groups" : "g", "filename" : "results/pc/03_data.csv", "group_by" : "num_class", "label" : "inheritance", "style_id" : 7 },
    { "groups" : "hi", "filename" : "results/pc/04_dyn_data.csv", "group_by" : "num_class", "label" : "dynamic polymorphism", "style_id" : 8 },
    { "groups" : "i", "filename" : "results/pc/04_sta_data.csv", "group_by" : "num_class", "label" : "static polymorphism", "style_id" : 9 },
    { "groups" : "d", "filename" : "results/laptop/01_data_c.csv", "group_by" : "num_funcs", "label" : "plain functions (C) (laptop)", "style_id" : 5 },
    { "groups" : "d", "filename" : "results/laptop/01_data_cpp.csv", "group_by" : "num_funcs", "label" : "plain functions (C++) (laptop)", "style_id" : 6 },
    { "groups" : "", "filename" : "results/laptop/01_data_inlined_c.csv", "group_by" : "num_funcs", "label" : "static inline functions (C) (laptop)", "style_id" : 7 },
    { "groups" : "", "filename" : "results/laptop/01_data_inlined_cpp.csv", "group_by" : "num_funcs", "label" : "static inline functions (C++) (laptop)", "style_id" : 8 },
    { "groups" : "", "filename" : "results/laptop/01_data_classes.csv", "group_by" : "num_funcs", "label" : "functions wrapped in classes (C++) (laptop)", "style_id" : 9 },
    { "groups" : "", "filename" : "results/laptop/02_basic_data.csv", "group_by" : "num_class", "label" : "encapsulation (basic) (laptop)", "style_id" : 0 },
    { "groups" : "", "filename" : "results/laptop/02_template_data.csv", "group_by" : "num_class", "label" : "encapsulation (template) (laptop)", "style_id" : 1 },
    { "groups" : "", "filename" : "results/laptop/03_data.csv", "group_by" : "num_class", "label" : "inheritance (laptop)", "style_id" : 2 },
    { "groups" : "", "filename" : "results/laptop/04_dyn_data.csv", "group_by" : "num_class", "label" : "dynamic polymorphism (laptop)", "style_id" : 3 },
    { "groups" : "", "filename" : "results/laptop/04_sta_data.csv", "group_by" : "num_class", "label" : "static polymorphism (laptop)", "style_id" : 4 }
]

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

for g in groups:
    plt.figure(figsize=(10, 6))
    plot_id = 0
    for i in range(len(data)):
        if g["id"] in files[i]["groups"] :
            plt.plot(
                data[i][files[i]["group_by"]],
                data[i]['mean_comp_t'],
                label=files[i]["label"],
                marker=styles[files[i]["style_id"]]["marker"],
                color=styles[files[i]["style_id"]]["color"],
                linestyle='-',
                markersize=4
            )
            plot_id += 1
    plt.axis([0, 200, 0, g["y"]])
    plt.xlabel('Number of Functions / Classes')
    plt.ylabel('Compilation Time (s)')
    plt.title('Compilation Time vs Number of Functions/Classes')
    plt.legend()
    plt.grid(True)
    #plt.show()
    plt.savefig(g["filename"] + ".png", dpi=dpi)