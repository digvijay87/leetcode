
typedef struct {
    struct Trie *children[ALPHABET_SIZE];
    bool isLeaf;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *newnode=malloc(sizeof(Trie));
    newnode->isLeaf=false;
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        newnode->children[i]=NULL;
    }
    return newnode;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int index;
    int len=strlen(word);
    for(int i=0;i<len;i++)
    {
        index=word[i]-'a';
        if(!obj->children[index])
        {
            obj->children[index]=trieCreate();
        }
        obj=obj->children[index];
    }
    obj->isLeaf=true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int index;
    for(int i=0;i<strlen(word);i++)
    {
        index=word[i]-'a';
        if(!obj->children[index])
            return false;
        obj=obj->children[index];
    }
    return (obj!=NULL&&obj->isLeaf);

}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    int index;
    for(int i=0;i<strlen(prefix);i++)
    {
        index=prefix[i]-'a';
        if(!obj->children[index])
            return false;
        obj=obj->children[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
