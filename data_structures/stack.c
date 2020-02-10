#include <stdio.h>
#include <stdlib.h>

typedef struct ReusableNode {
  char* song_name;
  struct ReusableNode* next_element;  
} Node;

void push(Node* stack, Node* node){
  Node* tmp = malloc(sizeof(Node));
  tmp->song_name = stack->song_name;
  tmp->next_element = stack->next_element;  
  stack->song_name = node->song_name;
  stack->next_element = tmp;
}

void print_stack(Node* stack) 
{
   printf("%s", stack->song_name);
   printf("\n");
   if(stack->next_element != NULL) {
     print_stack(stack->next_element);	   
   }	   
}

Node* pop(Node* stack){
  Node* popped_element = malloc(sizeof(stack));
  popped_element->song_name = stack->song_name;
  popped_element->next_element = stack->next_element;  
  stack->song_name = stack->next_element->song_name;
  stack->next_element = stack->next_element->next_element;
  return popped_element;  
}

int main(int argc, char** argv){
  Node* node = malloc(sizeof(Node));
  node->song_name = malloc(6);
  node->song_name = "Diego";
  node->next_element = NULL;
  
  Node* next_node = malloc(sizeof(Node));
  next_node->song_name = malloc(6);
  next_node->song_name = "Alan";
  next_node->next_element = NULL;
  
  Node* next = malloc(sizeof(Node));
  next->song_name = malloc(6);
  next->song_name = "Pedro";
  next->next_element = NULL;

  push(node, next_node);
  push(node, next);
  print_stack(node);

  printf("Popped element: %s", pop(node)->song_name);
  printf("\n");
  print_stack(node);
  return EXIT_SUCCESS;
}
