// Código da SQRT decomposition: https://www.geeksforgeeks.org/number-elements-less-equal-given-number-given-subarray-set-2-including-updates/
// Abordagem naive resulta em TLE, dessa forma foi necessário utilizar outra estrutura de dados
// para fazer as alterações e queries

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10001;

// updating the bit array of a valid block
void update(int idx, int blk, int val, int bit[][MAX])
{
    for (; idx < MAX; idx += (idx & -idx))
        bit[blk][idx] += val;
}

// answering the query
int query(int l, int r, int k, int arr[], int blk_sz,
          int bit[][MAX])
{
    // traversing the first block in range
    int sum = 0;
    while (l < r && l % blk_sz != 0 && l != 0)
    {
        if (arr[l] <= k)
            sum++;
        l++;
    }

    // Traversing completely overlapped blocks in
    // range for such blocks bit array of that block
    // is queried
    while (l + blk_sz <= r)
    {
        int idx = k;
        for (; idx > 0 ; idx -= idx & -idx)
            sum += bit[l / blk_sz][idx];
        l += blk_sz;
    }

    // Traversing the last block
    while (l <= r)
    {
        if (arr[l] <= k)
            sum++;
        l++;
    }
    return sum;
}

// Preprocessing the array
void preprocess(int arr[], int blk_sz, int n, int bit[][MAX])
{
    for (int i = 0; i < n; i++)
        update(arr[i], i / blk_sz, 1, bit);
}

void preprocessUpdate(int i, int v, int blk_sz,
                      int arr[], int bit[][MAX])
{
    // updating the bit array at the original
    // and new value of array
    update(arr[i], i / blk_sz, -1, bit);
    update(v, i / blk_sz, 1, bit);
    arr[i] = v;
}

int main() {

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int blk_sz = sqrt(n);
    int bit[blk_sz + 2][MAX];
    memset(bit, 0, sizeof(bit));

    preprocess(arr, blk_sz, n, bit);

    int op;
    int a;
    int y;
    for (int i = 0; i < q; ++i)
    {
        cin >> op;
        if (op == 1) {
            cin >> a >> y;
            preprocessUpdate(a-1, y, blk_sz, arr, bit);
        }
        else {
            int L;
            int R;
            int K;
            cin >> K >> L >> R;
            int nam = query (L - 1, R - 1, K, arr, blk_sz, bit);
            cout << (R-L-nam+1) << endl;
        }
    }

    return 0;
}

