/*
 * @Author: AGOGIN 
 * @Date: 2020-03-28 16:24:33 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-28 18:22:41
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
void trieInsert(Trie* obj, char* word) {
    int sLen = strlen(word);
    for (int i = 0; i < sLen; i++) {
        if (obj->map[word[i] - 'a'] == NULL) {
            obj->map[word[i] - 'a'] = trieCreate();
        }
        obj = obj->map[word[i] - 'a'];
    }
    obj->isWord = true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < alphabet; i++) {
        if (obj->map[i] != NULL) {
            trieFree(obj->map[i]);
        }
    }
    free(obj);
}
void countNumTrieWords(Trie* obj, int* ret, int floor) {
    int num = 0;
    for (int i = 0; i < alphabet; i++) {
        if (obj->map[i] != NULL) {
            countNumTrieWords(obj->map[i], ret, floor + 1);
            num++;
        }
    }
    if (num == 0) (*ret) += floor + 1;
}

void reverse(char* word) {
    int sLen = strlen(word);
    for (int i = 0; i < sLen / 2; i++) {
        char temp = word[i];
        word[i] = word[sLen - 1 - i];
        word[sLen - 1 - i] = temp;
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int ret = 0;
    if (wordsSize == 0) return ret;
    Trie* obj = trieCreate();
    for (int i = 0; i < wordsSize; i++) {
        reverse(words[i]);
        trieInsert(obj, words[i]);
    }
    countNumTrieWords(obj, &ret, 0);
    trieFree(obj);
    return ret;
}

int main() {
    char** words = malloc(sizeof(char*) * 3);
    char a[] = "time";
    char b[] = "me";
    char c[] = "bell";
    words[0] = a;
    words[1] = b;
    words[2] = c;
    int ret = minimumLengthEncoding(words, 3);
    printf("%d\n", ret);
    return 0;
}