bool verifyPostorder(int* postorder, int postorderSize){
    if (postorderSize == 0 || postorderSize == 1) return true;
    int i, j;
    for (i = 0; i < postorderSize - 1; i++) {
        if (postorder[i] > postorder[postorderSize - 1]) break;
    }
    for (int j = i; j < postorderSize - 1; j++) {
        if (postorder[j] < postorder[postorderSize - 1]) return false;
    }
    return verifyPostorder(postorder, i) && verifyPostorder(postorder + i, postorderSize - i - 1);
}