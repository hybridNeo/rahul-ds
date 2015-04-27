class Tree{

private:
	struct t_node{
		
		struct t_node* left;
		struct t_node* right;
		int val;
	};
	t_node *root;
public:
	Tree();
	void insert(int val);
	void inorder(t_node *);
	void print_inorder();
	
};