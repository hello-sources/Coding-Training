#define MAX_N 10000
struct Data {
    int x, y;
} data[MAX_N + 5];

bool isPathCrossing(char * path){
    data[0].x = 0, data[0].y = 0;
    int x = 0, y = 0, len = strlen(path);
    for (int i = 0; path[i]; i++) {
        switch (path[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
        data[i + 1].x = x;
        data[i + 1].y = y;
        for (int j = 0; j <= i; j++) {
            if (x == data[j].x && y == data[j].y) return true;
        }
    }
    return false;
}