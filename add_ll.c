# include<stdio.h>
# include<malloc.h>
# include<math.h>

struct node{
    int data;
    struct node* next;
};

struct node* reverse(struct node* head){
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

struct node* add(struct node* list1,struct node* list2){
    struct node* result=NULL;

    int a=0,b=0,c;

    struct node* temp1=list1;
    struct node* temp2=list2;

    int count1=0;
    struct node* temp =list1;
    while(temp->next !=NULL){
        count1++;
        temp=temp->next;

    }
    count1++;

    int count=count1;
    while(temp1 != NULL){
        a=a+temp1->data*pow(10,count-1);
        temp1=temp1->next;
        count--;
    }
    count=count1;
    while(temp2 != NULL){
        b=b+temp2->data*pow(10,count-1);
        temp2=temp2->next;
        count--;
    }

    c=a+b;

    while(c > 0){
        struct node* ptr;
        ptr=(struct node*)malloc(sizeof(struct node));

        ptr->data=c%10;
        ptr->next=NULL;
        c=c/10;

        if(result == NULL){
            result=ptr;
        }
        else{
            struct node* temp = result;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=ptr;
        }

    }
    
    result=reverse(result);

    return result;

}

void display(struct node* head){
    struct node* ptr=head;
    while(ptr->next != NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d \n",ptr->data);
}

int main(){

    struct node* head=NULL;
    struct node* head1=NULL;
    
    int n;
    printf("Enter the no. of elements you want : ");
    scanf("%d",&n);

    printf("For list 1 enter elements: \n");
    for(int i=0;i<n;i++){
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));

        int data;
        printf("Enter element %d :",i+1);
        scanf("%d",&data);

        newnode->data=data;
        newnode->next=NULL;

        if(head == NULL){
            head=newnode;
        }

        else{
            struct node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=newnode;
            
        }
    }


    printf("For list 2 enter elements: \n");
    for(int i=0;i<n;i++){
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));

        int data;
        printf("Enter element %d :",i+1);
        scanf("%d",&data);

        newnode->data=data;
        newnode->next=NULL;

        if(head1 == NULL){
            head1=newnode;
        }

        else{
            struct node* temp = head1;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=newnode;
            
        }
    }

    printf("List 1 is : ");
    display(head);

    printf("List 2 is : ");
    display(head1);

    struct node *rel;
    rel=add(head,head1);

    printf("Final output is : ");
    display(rel);
    return 0;
}
