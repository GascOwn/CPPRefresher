#include "Node.h"
#include <iostream>

using namespace std;

void add_entry(Node* head, int new_value)
{
	Node* new_node = new Node{ new_value, nullptr };
	Node* current = head;
	while (current->next) {
		current = current->next;
	}
	current->next = new_node;
}

void add_entry_beginning(Node*& head, int new_value)
{
	Node* new_node = new Node{ new_value, head };
	head = new_node;
}

void cycle_nodes(Node* head)
{
	Node* current = head;
	while (current) {
		Node* next = current->next;
		current = next;
	}
}

void delete_entry(Node*& head, int value)
{
	Node* current = head;
	Node* previous = nullptr;
	while (current) {
		if (current->value == value) {
			if (previous) {
				previous->next = current->next;
			}
			else {
				head = current->next;
			}
			delete current;
			break;
		}
		previous = current;
		current = current->next;
	}
}

void print_list(Node* head)
{
	Node* current = head;
	while (current) {
		cout << current->value << "\n";
		current = current->next;
	}
}