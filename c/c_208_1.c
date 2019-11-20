/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 15:28:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 16:44:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define alphabet 26
struct TrieNode{
    bool isWord;
    struct TrieNode* map[alphabet];
};
typedef struct TrieNode Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* obj = malloc(sizeof(Trie));
    obj->isWord = false;
    for (int i = 0; i < alphabet; i++) {
        obj->map[i] = NULL;
    }
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int sLen = strlen(word);
    for (int i = 0; i < sLen; i++) {
        if (obj->map[word[i] - 'a'] == NULL) {
            obj->map[word[i] - 'a'] = trieCreate();
        }
        obj = obj->map[word[i] - 'a'];
    }
    obj->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int sLen = strlen(word);
    for (int i = 0; i < sLen; i++) {
        if (obj->map[word[i] - 'a'] != NULL) {
            obj = obj->map[word[i] - 'a'];
        } else return false;
    }
    return obj->isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    int sLen = strlen(prefix);
    for (int i = 0; i < sLen; i++) {
        if (obj->map[prefix[i] - 'a'] != NULL) {
            obj = obj->map[prefix[i] - 'a'];
        } else return false;
    }
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < alphabet; i++) {
        if (obj->map[i] != NULL) {
            trieFree(obj->map[i]);
        }
    }
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

int main() {

    return 0;
}