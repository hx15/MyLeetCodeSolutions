class TrieNode{
private:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
    
public:
    TrieNode(){
        
    }
    
public:
    TrieNode* getChild(char c){
        return children[c];
    }
    
    bool charExits(char c){
        bool found = false;
        unordered_map<char, TrieNode*>::iterator it = children.find(c);
        return !(it == children.end());
    }
    
    void addChar(char c){
        TrieNode* newNode = new TrieNode();
        children[c] = newNode;
    }
    
    void markWord(){
        isEndOfWord = true;
    }
    
    bool isWord(){
        return isEndOfWord;
    }
    
};
​
class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c: word)
        if(curr->getChild(c) == NULL){
            curr->addChar(c);
            curr = curr->getChild(c);
        }
        else
            curr = curr->getChild(c);
        
        curr->markWord();
    }
    
    bool search(string word) {
