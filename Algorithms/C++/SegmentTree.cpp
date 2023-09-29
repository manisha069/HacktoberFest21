// Segment Tree Update and Sum Range Queries

#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void build(int node, int l, int r, vector<int> &v) {
    if (l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid, v);
    build(2*node+1, mid+1 , r, v);
    tree[node] = tree[2*node] + tree[2*node + 1];

}

void update(int node, int l, int r, int i, int val, vector<int> &v) {
    if (!(i >= l && i <= r)) return;
    if (l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2, l, mid, i, val, v);
    update(node*2+1, mid+1, r, i, val, v);
    tree[node] = tree[node*2] + tree[node*2 + 1];
} 

int query(int node, int l, int r, int a, int b) {
    if (a > r || b < l)return 0;

    if (l >= a && r <= b) return tree[node];

    int mid = (l+r)/2;
    return query(node*2, l, mid, a, b) + query(node*2 + 1, mid + 1, r, a, b);
}
