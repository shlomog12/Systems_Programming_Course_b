
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>
namespace ariel{

    template<class T>
    class BinaryTree{
    private:
        struct Node {
            T value;
            Node* left;
            Node* right;
            Node* next_pre;
            Node* next_post;
            Node* next_in;
            Node(const T& v): 
            value(v),left(NULL),right(NULL),next_in(NULL),next_post(NULL),next_pre(NULL){}
	    };
        Node* root;

    public:

        BinaryTree():root(NULL){};


        void copy(Node* new_node,Node* old_node){
            if (old_node->left!=NULL){
                new_node->left=new Node(old_node->left->value);
                copy(new_node->left,old_node->left);
            }
            if (old_node->right!=NULL){
                new_node->right=new Node(old_node->right->value);
                copy(new_node->right,old_node->right);
            }
        }



        BinaryTree(const BinaryTree &other){
            if (this!=&other && other.root!=NULL){
                // if (other.root!=NULL){
                    this->root=new Node(other.root->value);
                    copy(this->root,other.root);
                // }  
            }
        }

        BinaryTree& operator=(const BinaryTree &other) {
            if (this!=&other && other.root!=NULL){
                    this->root=new Node(other.root->value);
                    copy(this->root,other.root);
            }
            return *this;
        }

        
        // move
        BinaryTree(BinaryTree&& other) noexcept    {
       
        }
    

        BinaryTree& operator=(BinaryTree&& other)  noexcept {
            return *this;
        }


        ~BinaryTree(){
            delete this->root;
        };



    
        Node* get_node(T val){
            auto it=iterator_inorder(this->root);
            Node* n=it.get_curr();
            while (n!=NULL){
                if (n->value==val){
                    return n;
                }
                n=n->next_in;
            }
            
            throw std::out_of_range("EROR");
        }
        BinaryTree& add_root(const T &root_new){
            Node* new_node=new Node(root_new);
            if (root!=NULL) {
                new_node->left=this->root->left;
                new_node->right=this->root->right;
            }
            this->root=new_node;
            return *this;
        };
        BinaryTree& add_left(T father,T child){
            Node* node_father = get_node(father);
            Node* new_node = new Node(child);    
            if (node_father->left!=NULL){
                new_node->left=node_father->left->left;
                new_node->right=node_father->left->right;
            }
            node_father->left=new_node;
            return *this;
        };
        BinaryTree& add_right(T father,T child){
            Node* node_father = get_node(father);
            Node* new_node=new Node(child);  
            if (node_father->right!=NULL){
                new_node->left=node_father->right->left;
                new_node->right=node_father->right->right;
            }
            node_father->right=new_node;
            return *this;
        }
        friend std::ostream& operator<< (std::ostream& os,const BinaryTree& tree){
            os << "myTree:\n";
            for (auto it=tree.begin_inorder(); it!=tree.end_inorder(); ++it) {
                os << (*it) << " " ;
            } 
            return os;
        };
      
        
        class iterator_preorder{
            private:
                Node* current_node;
            public:
                iterator_preorder(Node* node = nullptr): current_node(node) {
                    if (node==NULL){
                        return;
                    } 
                    init_next(node->left);
                    init_next(node->right);
                    current_node=node;
		        }  
                void init_next(Node * node){
                    if (node==NULL) {return;}
                    current_node->next_pre=node;
                    current_node=node;
                    init_next(node->left);
                    init_next(node->right);
                    
                }                                 
                T& operator*() const {
			        return current_node->value;
		        }
                T* operator->() const {
			        return &(current_node->value);
		        }
		        iterator_preorder& operator++() {
			        current_node =current_node->next_pre;
			        return *this;
		        }
                /*const*/ iterator_preorder operator++(int) {
			        iterator_preorder temp= *this;
                    current_node =current_node->next_pre;
			        return temp;
		        }
                bool operator==(const iterator_preorder& other) const {
			        return current_node == other.current_node;
		        }
                bool operator!=(const iterator_preorder& other) const {
                    
                    return !(*this==other);
			        // return current_node != rhs.pointer_to_current_node;
		        }
        };    
        class iterator_inorder{
            private:
                Node* current_node;
                Node* first;
            public:
                iterator_inorder(Node* node = nullptr): current_node(NULL) {
                    if (node==NULL){
                        return;
                    } 
                    init_next(node);
                    current_node=first;
		        }
                Node* get_curr(){
                    return current_node;
                }
                void init_next(Node * node){
                    if (node==NULL){return;}
                    init_next(node->left);
                    if (current_node==NULL){
                        first=node;
                    }else{
                        current_node->next_in=node;
                    }
                    current_node=node;
                    init_next(node->right);
                }  
                T& operator*() const {
			        return current_node->value;
		        }
                T* operator->() const {
			        return &(current_node->value);
		        }
		        iterator_inorder& operator++() {
			        current_node =current_node->next_in;
			        return *this;
		        }
                /*const*/ iterator_inorder operator++(int) {
			        iterator_inorder temp= *this;
			        current_node =current_node->next_in;
			        return temp;
		        }
                bool operator==(const iterator_inorder& other) const {
			        return current_node == other.current_node;
		        }
                bool operator!=(const iterator_inorder& other) const {
                    return !(*this==other);
			        // return current_node != rhs.pointer_to_current_node;
		        }
        };
        class iterator_postorder{
            private:
                Node* current_node;
                Node* first;
            public:
                iterator_postorder(Node* node = nullptr): current_node(NULL) {
                    if (node==NULL){
                        return;
                    } 
                    init_next(node);
                    // node->next=NULL;
                    // current_node->next=node;
                    current_node=first;
		        } 
                 void init_next(Node * node){
                    if (node==NULL){return;}
                    init_next(node->left);
                    init_next(node->right);
                    if (current_node==NULL){
                        first=node;
                    }else{
                        current_node->next_post=node;
                    }
                    current_node=node;
                    
                }                    
                T& operator*() const {
			        return current_node->value;
		        }
                T* operator->() const {
			        return &(current_node->value);
		        }
		        iterator_postorder& operator++() {
			        current_node =current_node->next_post;
			        return *this;
		        }
                /*const*/ iterator_postorder operator++(int) {
			        iterator_postorder temp= *this;
			        current_node =current_node->next_post;
			        return temp;
		        }
                bool operator==(const iterator_postorder& other) const {
			        return current_node == other.current_node;
		        }
                bool operator!=(const iterator_postorder& other) const {
                    return !(*this==other);
			        // return current_node != rhs.pointer_to_current_node;
		        }
        };        
    
    
        iterator_preorder begin_preorder(){
            return iterator_preorder(this->root);
        };
        iterator_preorder end_preorder(){
            return iterator_preorder(nullptr);
        };
        iterator_inorder begin_inorder(){
            return iterator_inorder(this->root);
        };
        iterator_inorder end_inorder(){
            return iterator_inorder(nullptr);
        };
        iterator_postorder begin_postorder(){
            return iterator_postorder(this->root);
        };
        iterator_postorder end_postorder(){
             return iterator_postorder(nullptr);
        };
       

        iterator_inorder begin() {
            return iterator_inorder(this->root);
	    }
	
	    iterator_inorder end() {
            return iterator_inorder(nullptr);
	    }
    };
}
