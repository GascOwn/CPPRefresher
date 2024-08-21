struct Node {
	int value;
	Node* next;
};

void add_entry(Node* head, int new_value);
void add_entry_beginning(Node*& head, int new_value);
void cycle_nodes(Node* head);
void print_list(Node* head);
void delete_entry(Node*& head, int value);
