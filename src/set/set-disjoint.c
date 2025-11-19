#include "set-disjoint.h"
#include "../utils/check_alloc.h"
#include <stdlib.h>

struct DisjointSet {
    int *parent;
    int *rank;
    int n;
};

DisjointSet *set_disjoint_create(int n) {
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    check_alloc(ds);
    ds->n = n;
    ds->parent = (int *)malloc(sizeof(int) * n);
    check_alloc(ds->parent);
    ds->rank = (int *)malloc(sizeof(int) * n);
    check_alloc(ds->rank);
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

void set_disjoint_free(DisjointSet *ds) {
    free(ds->parent);
    free(ds->rank);
    free(ds);
}

// Find with path compression
int set_disjoint_find(DisjointSet *ds, int i) {
    if (ds->parent[i] != i) {
        ds->parent[i] = set_disjoint_find(ds, ds->parent[i]);
    }
    return ds->parent[i];
}

// Union by rank
void set_disjoint_union(DisjointSet *ds, int i, int j) {
    int root_i = set_disjoint_find(ds, i);
    int root_j = set_disjoint_find(ds, j);

    if (root_i != root_j) {
        if (ds->rank[root_i] < ds->rank[root_j]) {
            ds->parent[root_i] = root_j;
        } else if (ds->rank[root_i] > ds->rank[root_j]) {
            ds->parent[root_j] = root_i;
        } else {
            ds->parent[root_j] = root_i;
            ds->rank[root_i]++;
        }
    }
}
