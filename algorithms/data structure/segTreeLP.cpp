#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e5 + 10;  // Maximum size for the array
int segtree[4 * mxn], lazy[4 * mxn], a[mxn], n;

// Build the Segment Tree
void build(int node, int start, int end) {
    if (start == end) {
        // Leaf node will have a single element
        segtree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Internal node will have the sum of both of its children
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

// Propagate the update to the children nodes
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        // Apply the pending updates to the current node
        segtree[node] += (end - start + 1) * lazy[node]; // Adding lazy update value

        // If not a leaf node, propagate the update to the children
        if (start != end) {
            lazy[2 * node] += lazy[node]; // Mark the left child for lazy propagation
            lazy[2 * node + 1] += lazy[node]; // Mark the right child for lazy propagation
        }

        // Clear the lazy value for the current node
        lazy[node] = 0;
    }
}

// Update a range [l, r] by adding value v
void update_range(int node, int start, int end, int l, int r, int v) {
    // First propagate any pending updates
    propagate(node, start, end);

    if (start > end || start > r || end < l) {
        // No overlap
        return;
    }

    if (start >= l && end <= r) {
        // Total overlap
        // Apply the update
        lazy[node] += v;
        propagate(node, start, end);  // Apply the pending updates immediately
        return;
    }

    // Partial overlap
    int mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r, v);
    update_range(2 * node + 1, mid + 1, end, l, r, v);
    // After updating both children, recalculate the value for the current node
    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

// Query the sum in the range [l, r]
int query_range(int node, int start, int end, int l, int r) {
    // First propagate any pending updates
    propagate(node, start, end);

    if (start > end || start > r || end < l) {
        // No overlap
        return 0;
    }

    if (start >= l && end <= r) {
        // Total overlap
        return segtree[node];
    }

    // Partial overlap
    int mid = (start + end) / 2;
    int left_query = query_range(2 * node, start, mid, l, r);
    int right_query = query_range(2 * node + 1, mid + 1, end, l, r);
    return left_query + right_query;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  // For fast input/output

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n - 1);  // Build the tree

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {  // Query the sum in the range [l, r]
            int l, r;
            cin >> l >> r;
            cout << query_range(1, 0, n - 1, l, r) << '\n';
        } else if (type == 2) {  // Update the range [l, r] by adding a value v
            int l, r, v;
            cin >> l >> r >> v;
            update_range(1, 0, n - 1, l, r, v);
        }
    }

    return 0;
}
