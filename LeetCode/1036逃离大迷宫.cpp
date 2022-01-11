#define MAX_LEN 1000000
typedef struct {
    long long key;
    UT_hash_handle hh;
} HashNode;

typedef struct {
    int x;
    int y;
}PosInfo;

int g_dirt[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int CheckPara(int x, int y)
{
    return x >= 0 && y >= 0 && x < MAX_LEN && y < MAX_LEN;
}

void FreeHash(HashNode* hList)
{
    HashNode *curNode, *nextNode;
    HASH_ITER(hh, hList, curNode, nextNode) {
        HASH_DEL(hList, curNode);
        free(curNode);
    }
    return;
}

int bfs(HashNode* blockHashList, int* source, int* target,int bLen, int maxVist)
{    
    HashNode* vistHashList = NULL;
    HashNode* tmpNode1 = (HashNode*)malloc(sizeof(HashNode));
    tmpNode1->key = (long long)source[0] * MAX_LEN + source[1];
    HASH_ADD_INT(vistHashList, key, tmpNode1);

    PosInfo que[bLen * bLen];
    que[0].x = source[0];
    que[0].y = source[1];
    int front = 0;
    int rear = 1;
    while (front < rear) {
        int cnt = rear - front;
        while (cnt > 0) {
            for (int i = 0; i < 4; i++) {
                int tmpX = que[front].x + g_dirt[i][0];
                int tmpY = que[front].y + g_dirt[i][1];
                if (CheckPara(tmpX, tmpY) == 0) {
                    continue;
                }

                HashNode* tmpNode;
                long long tmpKey = (long long)tmpX * MAX_LEN + tmpY;
                HASH_FIND_INT(vistHashList, &tmpKey, tmpNode);
                if (tmpNode != NULL) { // 经过的点
                    continue;
                }

                HASH_FIND_INT(blockHashList, &tmpKey, tmpNode);
                if (tmpNode != NULL) { // block点
                    continue;
                }

                if (tmpX == target[0] && tmpY == target[1]) { // 如果可以到达目的地直接返回
                    return 1;
                }

                tmpNode = (HashNode*)malloc(sizeof(HashNode));
                tmpNode->key = tmpKey;
                HASH_ADD_INT(vistHashList, key, tmpNode);
                que[rear].x = tmpX;
                que[rear++].y = tmpY;
            }

            if (rear > maxVist) { // 如果可以经过的节点数量，超过可以被封锁最大区域的节点数。则说明无法被封锁
                FreeHash(vistHashList);
                return 0;
            }

            front++;
            cnt--;
        }
    }

    FreeHash(vistHashList);
    return -1;
}

bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize)
{
    if (blockedSize <= 1) {
        return true;
    }

    HashNode* blockHashList = NULL;
    int maxVist = blockedSize * (blockedSize - 1) / 2;
    for (int i = 0; i < blockedSize; i++) {
        HashNode* tmpNode = (HashNode*)malloc(sizeof(HashNode));
        tmpNode->key = (long long)blocked[i][0] * MAX_LEN + blocked[i][1];
        HASH_ADD_INT(blockHashList, key, tmpNode);
    }
    
    /* 查看source节点是否能够走出包围圈 */
    int ret = bfs(blockHashList, source, target, blockedSize, maxVist);
    if (ret == -1) {
        FreeHash(blockHashList);
        return false;
    } else if (ret == 1) {
        FreeHash(blockHashList);
        return true;
    }

    /* 查看target节点是否能够走出包围圈 */
    ret = bfs(blockHashList, target, source, blockedSize, maxVist);
    if (ret == -1) {
        FreeHash(blockHashList);
        return false;
    }

    FreeHash(blockHashList);
    return true;
}