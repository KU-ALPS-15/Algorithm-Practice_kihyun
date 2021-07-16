#include "binaryTree.cpp"

class BinSrchTree : public BinaryTree {
public:
	BinSrchTree():BinaryTree(){}
	Node* search(int key) {
		if (isEmpty()) {
			printf("Ʈ���� ��� �ֽ��ϴ�."); 
			return NULL;
		}
		else {
			//Node* found = searchRecur(root, key);
			Node* found = searchIter(key);
			if (found == NULL) {
				printf("ã�� �� �����ϴ�.\n");
				return found;
			}
			else {
				printf("ã�ҽ��ϴ�. key�� [%d]�� �༮�� �ּҴ� 0x%x �Դϴ�.\n", found->getData(), found);
				return found;
			}
		}
	}
	Node* searchRecur(Node* n, int key) {
		if (n == NULL) return NULL;
		else {
			int data = n->getData();
			if (data == key) return n;
			else if (key < data) return searchRecur(n->getLeft(), key);
			else return searchRecur(n->getRight(), key);
		}
	}

	Node* searchIter(int key) {
		if (isEmpty()) return NULL;
		else {
			Node* now_node = root;
			while (now_node != NULL) {
				if (now_node->getData() == key) return now_node;
				else if(key < now_node->getData()) now_node = now_node->getLeft();
				else now_node = now_node->getRight();
			}
			return now_node;
		}
		
	}
	void insert(Node* n) {
		if (n == NULL) printf("NULL �� ���� �� �����ϴ�.\n");
		else {
			if (isEmpty()) root = n;
			else insert(root, n);
		}
	}
	void insert(Node* r, Node* n) {
		
		if (r->getData() == n->getData()) printf("���� key�� �̹� �ֽ��ϴ�.\n");
		else if (r->getData() < n->getData()) {
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insert(r->getRight(), n);
		}
		else {
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else
				insert(r->getLeft(), n);
		}
	}

	void remove(int key) {
		if (isEmpty()) printf("Ʈ���� ��� �ֽ��ϴ�.\n");
		else {
			Node* parent = NULL;
			Node* child = root;
			while (child !=NULL) {
				if (child->getData() == key) break;
				else if (key < child->getData()) {
					parent = child;
					child = child->getLeft();
				}
				else {
					parent = child;
					child = child->getRight();
				}
			}
			if (child == NULL) printf("�����ϰ��� �ϴ� ��尡 �����ϴ�.\n");
			else { 
				//������ ��� ã�Ұ�
				remove(parent, child);
			}
			
		}
	}

	void remove(Node* parent, Node* child) {
		//�ڽ� 0��(���� ���)
		if (child->isLeaf()) {
			if (parent == NULL) {
				root = NULL;
				printf("��Ʈ ����(Leaf)\n");
			}
			else {
				if (parent->getRight() == child) parent->setRight(NULL);
				else parent->setLeft(NULL);
			}
			delete child;
		}
		//�ڽ� �� ��
		else if (child->isComplete()) {
			Node* succp = child;
			Node* succ = child->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}
			
			//child �ٷ� �������� succ �� ��
			if (succ == succp->getRight()) {
				if (parent == NULL) {
					printf("��Ʈ ����(Two Child)\n");
					succ->setLeft(child->getLeft());
					setRoot(succ);
				}
				else {
					if (parent->getRight() == child) {
						succ->setLeft(child->getLeft());
						parent->setRight(succ);
					}
					else {
						succ->setLeft(child->getLeft());
						parent->setLeft(succ);
					}
				}
				delete child;
			}
			else {
				succp->setLeft(succ->getRight());
				child->setData(succ->getData());
				child = succ;
				delete succ;
			}
			
		}
		//�ڽ� �� ��
		else {
			if (parent == NULL) {
				root = child->getLeft() != NULL ? child->getLeft() : child->getRight();
				printf("��Ʈ ����(One Child)\n");
			}
			else {
				if (parent->getLeft() == child) {
					if (child->getRight() == NULL) parent->setLeft(child->getLeft());
					else parent->setLeft(child->getRight());
				}
				else {
					if (child->getRight() == NULL) parent->setRight(child->getLeft());
					else parent->setRight(child->getRight());
				}
			}
			delete child;
		}
		
	}


	

};

int main() {
	BinSrchTree tree;
	tree.insert(new Node(35));
	tree.insert(new Node(18));
	tree.insert(new Node(7));
	tree.insert(new Node(26));
	tree.insert(new Node(12));
	tree.insert(new Node(3));
	tree.insert(new Node(68));
	tree.insert(new Node(22));
	tree.insert(new Node(30));
	tree.insert(new Node(99));
	tree.inOrder();
	printf("\n");
	//tree.search(22);
	tree.remove(18);
	tree.inOrder();
}