#include<string>
#include <iostream>
namespace ariel{

    template<class T>
    class BinaryTree{
    private:
        struct Node {
            T value;
            Node* next;
            Node(const T& v, Node* n): value(v), next(n) {}
	    };

    public:
        
        class iterator{
        private:
                 Node* node;
        public:
            bool operator!=(const iterator& rhs) const {
			return false;
		    }
            iterator& operator++() {
                    return *this;
            }
            T& operator*() const {
                    return node->value;
            }
            T* operator->() const {
                    return nullptr;
            }
            

        };
        iterator iterator1;




        BinaryTree():iterator1{iterator{}}{};

        BinaryTree& add_root(const T &root_new){
            return *this;
            };
        BinaryTree& add_left(T father,T child){
            return *this;
        };
        BinaryTree& add_right(T father,T child){
            return *this;
        }
        friend std::ostream& operator<< (std::ostream& os,const  BinaryTree& tree){
            return os;
        };
        iterator begin_preorder(){
            return iterator1;
        };
        iterator end_preorder(){
            return iterator1;
        };
        iterator begin_inorder(){
            return iterator1;
        };
        iterator end_inorder(){
            return iterator1;
        };
        iterator begin_postorder(){
            return iterator1;
        };
        iterator end_postorder(){
             return iterator1;
        };
        iterator begin(){
            return iterator1;
        };
        iterator end(){
            return iterator1;
        };
      
        
        
       
        
    };
}

