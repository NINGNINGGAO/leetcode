/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 15:26:49
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 17:22:25
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


int cmp(const void* a, const void* b) {
    return strcmp((*(char**)a), (*(char**)b));
}
bool isPreWord(Trie* obj, char* word) {
    int sLen = strlen(word);
    for (int i = 0; i < sLen; i++) {
        if (obj->map[word[i] - 'a'] != NULL && obj->map[word[i] - 'a']->isWord == true) {
            obj = obj->map[word[i] - 'a'];
        } else return false;
    }
    return true;
}
char * longestWord(char ** words, int wordsSize){
    Trie* obj = trieCreate();
    for (int i = 0; i < wordsSize; i++) {
        trieInsert(obj, words[i]);
    }
    char** res = malloc(sizeof(char*) * wordsSize);
    int maxLen = 0;
    int mid = 0;
    for (int i = 0; i < wordsSize; i++) {
        int sLen = strlen(words[i]);
        if (sLen == maxLen && isPreWord(obj, words[i])) {
            res[mid++] = words[i];
        } else if (sLen > maxLen && isPreWord(obj, words[i])) {
            mid = 0;
            maxLen = sLen;
            res[mid++] = words[i];
        }
    }
    trieFree(obj);
    qsort(res, mid, sizeof(char*), cmp);
    return res[0];
}

int main() {
    int wordSize = 7;
    char** word = malloc(sizeof(char*) * wordSize);
    for (int i = 0; i < wordSize; i++) {
        word[i] = malloc(sizeof(char) * 20);
    }
    word[0] = "w";
    word[1] = "wo";
    word[2] = "wor";
    word[3] = "worl";
    word[4] = "world";
    word[5] = "worla";
    word[6] = "bananana";
    char* res = longestWord(word, wordSize);
    return 0;
}