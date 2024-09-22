# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>


# define MAX_LENGTH 100
# define ALPHABET_SIZE 27 


typedef struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;
} TrieNode;


TrieNode* createNode(){
    TrieNode* node =  (TrieNode*)malloc(sizeof(TrieNode));
    for(int i = 0; i < ALPHABET_SIZE; i++){
        node->children[i]=NULL;
    }
    node->is_end_of_word=false;
    return node;
}


void insert(TrieNode* root, const char* word){
    TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++){
        int index = word[i]-'a';
        if(node->children[index]==NULL){
            node->children[index]= createNode();
        }
        node = node->children[index];
    }
    node->is_end_of_word = true;
}

bool search(TrieNode* root, const char* word){
    TrieNode* node = root;
    for(int i = 0; word[i]!='\0';i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL){
            return false; // not found
        }
        node = node->children[index];
    }
    return node->is_end_of_word;
}

bool startsWith(TrieNode* root, const char* prefix){
    TrieNode* node = root;
    for (int i =0 ; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}



int main(){ 

    TrieNode* root = createNode();


    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");

    bool res = search(root, "ap");
    printf("%d\n", res);
    return 0;
}
