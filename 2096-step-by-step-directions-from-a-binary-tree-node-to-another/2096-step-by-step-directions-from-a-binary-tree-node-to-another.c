bool findPath(struct TreeNode *root, int val, char *s, int *i) {
    if(root->val == val) return true;
    // Add directions 'L' or 'R' based on left on right traversals
    if(root->left && findPath(root->left, val, s, i))   
        s[(*i)++] = 'L';
    else if(root->right && findPath(root->right, val, s, i))  
        s[(*i)++] = 'R';
    // Return true if value is found. 
    // If value is found then path string s will not be empty
    return (*i > 0);  
}

#define RANGE   100001
char * getDirections(struct TreeNode* root, int startValue, int destValue){
    char sPath[RANGE], dPath[RANGE];
    int idx = 0, sLen, dLen;
    
    findPath(root, startValue, sPath, &idx);
    sLen = idx;
    idx = 0;
    findPath(root, destValue, dPath, &idx);
    dLen = idx;
    
    // Remove common prefix from both paths from the back side
    while(sLen > 0 && dLen > 0 && sPath[sLen-1] == dPath[dLen-1]) {
        sLen--; 
        dLen--;
    }
    
    // Form the result by concatenating both paths. Replace 'L' and 'R' 
    // to 'U' in startPath and reversing the direction in  destPath
    char *res = calloc(sizeof(char), (sLen + dLen + 1));
    int resIdx = 0;
    
    // Common ancestor, add 'U'
    for(int i = 0; i < sLen; i++)
        res[resIdx++] = 'U';
    
    // From common ancestor to dest
    for(int i = dLen - 1; i >= 0; i--)
        res[resIdx++] = dPath[i];           // add direction
    return res;
}