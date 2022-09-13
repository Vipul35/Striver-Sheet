class LRUCache {
public:
    class node{
        public:
        node*next;
        node*prev;
        int val;
        int key;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    unordered_map<int,node*> m;
    int cap;
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    void addnode(node*newnode)
    {
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node*existing)
    {
        node*previous=existing->prev;
        node*nextptr=existing->next;
        previous->next=nextptr;
        nextptr->prev=previous;
    }
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node*existing=m[key];
            int res=existing->val;
            m.erase(key);
            deletenode(existing);
            addnode(existing);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node*existing=m[key];
            m.erase(key);
            deletenode(existing);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */