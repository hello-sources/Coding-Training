#define MAX_N 33
#define MAX_M 10005

int cnt = 0;

typedef struct {
    int timestamp;
    char msg[MAX_N];
} Logger;

Logger* loggerCreate() {
    Logger *obj = (Logger *)malloc(sizeof(Logger) * MAX_M);
    return obj;
}

bool loggerShouldPrintMessage(Logger* obj, int timestamp, char * message) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(obj[i].msg, message) == 0) {
            if (timestamp >= obj[i].timestamp + 10) {
                obj[i].timestamp = timestamp;
                return true;
            } else return false;
        }
    }
    obj[cnt].timestamp = timestamp;
    strcpy(obj[cnt].msg, message);
    cnt++;
    return true;
}

void loggerFree(Logger* obj) {
    free(obj);
    return ;
}

/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/