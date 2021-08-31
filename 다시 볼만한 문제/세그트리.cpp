#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{
    int minx, maxx;
    Node(){}
    Node(int _minx, int _maxx): minx(_minx), maxx(_maxx){}
};

Node tree[2 << 18];
int B;

void set_tree(){
    for(int i = B - 1; 0 < i; i--) {
        tree[i].minx = min(tree[i * 2].minx, tree[i * 2 + 1].minx);
        tree[i].maxx = max(tree[i * 2].maxx, tree[i * 2 + 1].maxx);
    }
}

Node get_node(int ql, int qr, int l = 1, int r = B, int idx = 1){
    if(ql <= l && r <= qr) return tree[idx];

    int half = (l + r) / 2;
    Node ret1(1000000001, -1), ret2(1000000001, -1);
    if(ql <= half) ret1 = get_node(ql, qr, l, half, idx * 2);
    if(half < qr) ret2 = get_node(ql, qr, half + 1, r, idx * 2 + 1);

    return Node(min(ret1.minx, ret2.minx), max(ret1.maxx, ret2.maxx));
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(B = 1; B < N; B <<= 1);

    for(int i = 0; i < N; i++) {
        scanf("%d", &tree[B + i].minx);
        tree[B + i].maxx = tree[B + i].minx;
    }

    set_tree();

    int a, b; while(M--){
        scanf("%d %d", &a, &b);
        Node ans = get_node(a, b);
        printf("%d %d\n", ans.minx, ans.maxx);
    }
    
    return 0;
}