template <typename T>
class TreeNode
{
public:
	TreeNode() { val = T(); left = NULL; right = NULL; }
	TreeNode(T value) { val = value; left = NULL; right = NULL; }
	~TreeNode() { val = T(); delete left; delete right; }
	T val;
	TreeNode* left;
	TreeNode* right;


};
