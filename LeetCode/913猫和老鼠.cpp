#define MOUSE_WIN 1
#define CAT_WIN 2
#define DRAW 0
#define MAXN 51

int dp[MAXN][MAXN][MAXN*2];

int getResult(int mouse, int cat, int turns, const int** graph, const int graphSize, const int* graphColSize) {
    if (turns == graphSize * 2) {
        return DRAW;
    }
    if (dp[mouse][cat][turns] < 0) {
        if (mouse == 0) {
            dp[mouse][cat][turns] = MOUSE_WIN;
        } else if (cat == mouse) {
            dp[mouse][cat][turns] = CAT_WIN;
        } else {
            getNextResult(mouse, cat, turns, graph, graphSize, graphColSize);
        }
    }
    return dp[mouse][cat][turns];
}

void getNextResult(int mouse, int cat, int turns, const int** graph, const int graphSize, const int* graphColSize) {
    int curMove = turns % 2 == 0 ? mouse : cat;
    int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
    int result = defaultResult;
    int * nextNodes = graph[curMove];
    for (int i = 0; i < graphColSize[curMove]; i++) {
        if (curMove == cat && nextNodes[i] == 0) {
            continue;
        }
        int nextMouse = curMove == mouse ? nextNodes[i] : mouse;
        int nextCat = curMove == cat ? nextNodes[i] : cat;
        int nextResult = getResult(nextMouse, nextCat, turns + 1, graph, graphSize, graphColSize);
        if (nextResult != defaultResult) {
            result = nextResult;
            if (result != DRAW) {
                break;
            }
        }
    }
    dp[mouse][cat][turns] = result;
}

int catMouseGame(int** graph, int graphSize, int* graphColSize){
    memset(dp, -1, sizeof(dp));
    return getResult(1, 2, 0, graph, graphSize, graphColSize);
}