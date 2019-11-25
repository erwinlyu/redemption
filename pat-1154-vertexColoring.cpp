#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node{int v1, v2;};
int main(){
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<node> edge(m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &edge[i].v1, &edge[i].v2);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){ // could use while(k--) instead
        bool rightColored = true;
        int color[10000] = {0};
        set<int> colorset;
        for(int j = 0; j < n; j++){
            scanf("%d", &color[j]);
            colorset.insert(color[j]);
        }
        for(int i = 0; i < m; i++){
            if(color[edge[i].v1] == color[edge[i].v2]){
                rightColored = false;
                break;
            }
        }
        if(rightColored){
            printf("%d-coloring\n", colorset.size());
        }
        else{
            printf("No\n");
        }
    }
}