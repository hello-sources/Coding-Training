#define MAX_N 5005

typedef struct {
    int persons[MAX_N];
    int times[MAX_N];
    int size;
    int hash[MAX_N];
    int data[MAX_N];
} TopVotedCandidate;


TopVotedCandidate* topVotedCandidateCreate(int* persons, int personsSize, int* times, int timesSize) {
    TopVotedCandidate *obj = (TopVotedCandidate *)malloc(sizeof(TopVotedCandidate));
    for (int i = 0; i < personsSize; i++) {
        obj->persons[i] = persons[i];
        obj->times[i] = times[i];
    }
    obj->size = personsSize;
    memset(obj->data, 0, MAX_N);
    memset(obj->hash, 0, MAX_N);
   int cnt = 0, max = 0;
   for (int i = 0; i < personsSize; i++) {
       obj->hash[obj->persons[i]]++;
       if (obj->hash[obj->persons[i]] >= cnt) {
           cnt = obj->hash[obj->persons[i]];
           obj->data[i] = obj->persons[i];
           max = obj->persons[i];
       } else {
           obj->data[i] = max;
       }
   } 
    return obj;
}

int topVotedCandidateQ(TopVotedCandidate* obj, int t) {
    int l = 0, r = obj->size;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (obj->times[mid] > t) r = mid;
        else l = mid + 1;
    }
    return obj->data[l - 1];
}

void topVotedCandidateFree(TopVotedCandidate* obj) {
    if (obj == NULL) return ;
    free(obj);
    return ;
}

/**
 * Your TopVotedCandidate struct will be instantiated and called as such:
 * TopVotedCandidate* obj = topVotedCandidateCreate(persons, personsSize, times, timesSize);
 * int param_1 = topVotedCandidateQ(obj, t);
 
 * topVotedCandidateFree(obj);
*/