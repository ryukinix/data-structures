#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#    Copyright © 2017 Manoel Vilela
#
#    @project: Data Structures UFC - 2017.2
#     @author: Manoel Vilela
#      @email: manoel_vilela@engineer.com
#


import sys
from os import path
import pandas as pd  # python-pandas dependency
import matplotlib.pyplot as plt
from typing import List, Dict

# pip install matplotlib pandas

dpi = 300
csv_sep = ';'
# fit best scale for each algorithm
scales = {
    'heapsort': (0, 600),
    'mergesort': (0, 600),
    'quicksort': (0, 600),
    # 'insertionsort': (0, 200000),
    # 'bubblesort': (0, 100000),
}


def load_dataframes(csvs: List[str]):
    dfs = {}
    for csv in csvs:
        df = pd.read_csv(csv, index_col=0, sep=csv_sep)
        df = df.loc[:, ~df.columns.str.contains('^Unnamed')]
        dfs[path.basename(csv)] = df
    return dfs


def mean_time(df):
    "Calculate the mean of the experiments"
    return df.mean(axis=1)


def mean_graph(dfs: Dict[str, pd.DataFrame]):
    "Make a graph comparing all the sorting algorithms"
    index = list(dfs.values())[0].index
    df_general = pd.DataFrame(index=index)
    for name, df in dfs.items():
        df_general[name.strip('.csv').capitalize()] = mean_time(df)

    return df_general


def save_graph_algorithm(name: str, df: List[pd.DataFrame]):
    "Make a graph based on its experiments and the mean value"
    name = name.strip('.csv')
    fig = plt.figure()
    df.columns = ['Experimento {}'.format(i) for i in range(1, 6)]
    ax = df.plot(title=name.capitalize(), kind='bar')
    ax.set_ylabel('Tempo (ms)')
    ax.set_xlabel('Elementos no vetor')
    ax.xaxis.set_tick_params(rotation=0)
    ax.minorticks_on()
    ax.set_axisbelow(True)
    if name in scales:
        plt.ylim(scales[name])

    plt.tight_layout()
    plt.savefig(name + '.png', dpi=dpi)
    plt.close(fig)


def save_graph_algorithms(dfs: Dict[str, pd.DataFrame], prefix=''):
    "Make a graph comparing all the sorting algorithms"
    print("Generating general graph {}".format(prefix))
    df_general = mean_graph(dfs)
    fig = plt.figure()
    title = 'Algoritmos de Ordenação ' + prefix.capitalize()
    ax = df_general.plot(title=title, kind='line')
    ax.set_ylabel('Tempo (ms)')
    ax.set_xlabel('Elementos no vetor')
    ax.xaxis.set_tick_params(rotation=0)
    ax.minorticks_on()
    ax.ticklabel_format(style='plain', axis='x')
    ax.set_axisbelow(True)
    fname = 'sorting'
    if prefix:
        fname = 'sorting-' + prefix
    plt.tight_layout()
    plt.savefig(fname+'.png', dpi=dpi)
    plt.close(fig)


def save_graph_per_element(dfs: Dict[str, pd.DataFrame]):
    df_general = mean_graph(dfs)
    for loc, i in enumerate(df_general.index):
        fig = plt.figure()
        row = df_general.iloc[loc]
        ax = row.plot(title='Ordenação com {} elementos'.format(i),
                      kind='bar')
        # recompute the ax.dataLim
        ax.relim()
        # update ax.viewLim using the new dataLim
        ax.autoscale_view()
        ax.set_ylabel('Tempo (ms)')
        ax.set_xlabel('')
        ax.legend().set_visible(False)
        ax.xaxis.set_tick_params(rotation=0)
        ax.minorticks_on()
        ax.set_axisbelow(True)
        plt.tight_layout()
        plt.savefig('sorting-{}.png'.format(i), dpi=dpi)
        plt.close(fig)


def main():
    dfs = load_dataframes(sys.argv[1:])
    # save individual graphs
    for name, df in dfs.items():
        print("Generating for: {}".format(name))
        save_graph_algorithm(name, df)

    # save general graph
    linear = {'radixsort'}
    nlogn = {'heapsort', 'mergesort', 'quicksort'}
    efficient = linear | nlogn
    quadratic = {'insertionsort', 'bubblesort'}
    df_eff = dict((k, v) for k, v in dfs.items()
                  if k.strip('.csv') in efficient)
    df_ineff = dict((k, v) for k, v in dfs.items()
                    if k.strip('.csv') in quadratic)
    save_graph_algorithms(dfs)
    if df_eff:
        save_graph_algorithms(df_eff, prefix='efficient')
    if df_ineff:
        save_graph_algorithms(df_ineff, prefix='quadratic')
    save_graph_per_element(dfs)


if __name__ == '__main__':
    main()
