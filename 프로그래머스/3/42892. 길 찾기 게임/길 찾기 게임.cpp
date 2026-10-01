#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num;
    int x;
    int y;
    int left = -1;
    int right = -1;
};

vector<Node> nodes;
vector<vector<int>> answer(2);

void insertNode(int root, int cur) {
    if(nodes[cur].x < nodes[root].x) {
        if(nodes[root].left == -1)
            nodes[root].left = cur;
        else
            insertNode(nodes[root].left, cur);
    }
    else {
        if(nodes[root].right == -1)
            nodes[root].right = cur;
        else
            insertNode(nodes[root].right, cur);
    }
}

void preorder(int cur) {
    if(cur == -1) return;

    answer[0].push_back(nodes[cur].num);
    preorder(nodes[cur].left);
    preorder(nodes[cur].right);
}

void postorder(int cur) {
    if(cur == -1) return;

    postorder(nodes[cur].left);
    postorder(nodes[cur].right);
    answer[1].push_back(nodes[cur].num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    nodes.clear();
    answer = vector<vector<int>>(2);

    for(int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back({
            i + 1,
            nodeinfo[i][0],
            nodeinfo[i][1]
        });
    }

    sort(nodes.begin(), nodes.end(), [](Node a, Node b) {
        if(a.y == b.y)
            return a.x < b.x;
        return a.y > b.y;
    });

    int root = 0;

    for(int i = 1; i < nodes.size(); i++)
        insertNode(root, i);

    preorder(root);
    postorder(root);

    return answer;
}