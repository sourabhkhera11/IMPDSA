#include<stdio.h>
#include<stdlib.h>
//struct is creating a userdefined datatype out of 
//the primitive / built-in datatypes
struct node{
    int data;
    struct node *next;
};
//creating a initial linked list 
struct node* create(int num){
    struct node *head,*temp,*ptr; //making the pointers 
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    //Now create the first element 
    printf("Enter the value of 1 element =");
    int value;
    scanf("%d",&value);
    head->data=value;
    head->next=NULL;
    ptr=head;
    for(int i=2;i<=num;i++){
        printf("Enter the value of %d element =",i);
        scanf("%d",&value);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}
void display(struct node *head){
    struct node *ptr;
    if(head==NULL){
        printf("LL is empty!");
        exit;
    }
    ptr=head;
    printf("Current linked list = ");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node * AddToHead(struct node * head,int item){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    temp->data=item;
    temp->next=head;
    head=temp;
    return head;
}
struct node * AddToTail(struct node * head,int item){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    temp->data=item;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    ptr=head;
    //Will stop at the last element
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
struct node * AfterGivenEle(struct node * head,int item,int ele){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    temp->data=item;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    ptr=head;
    //Will stop at the last element
    while(ptr->data!=ele){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
struct node * BeforeGivenEle(struct node * head,int item,int ele){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    temp->data=item;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    if(head->data==ele){
        temp->next=head;
        head=temp;
        return head;
    }
    ptr=head;
    //Will stop at the last element
    while(ptr->next->data!=ele){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
struct node * Insortedmanner(struct node * head,int item){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc filed! Exiting from the function");
        exit;
    }
    temp->data=item;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    if(head->data >item){
        temp->next=head;
        head=temp;
        return head;
    }
    ptr=head;
    while(ptr->next->data<item ){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
struct node * DeleteToHead(struct node * head){
    if(head==NULL){
        printf("Already LL is Null!");
        exit;
    }
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node * DeleteToTail(struct node * head){
    if(head==NULL){
        printf("Already LL is Null!");
        exit;
    }
    struct node *temp,*ptr;
    ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}
struct node * DeleteGivenEle(struct node * head,int ele){
    struct node *temp,*ptr;
    if(head==NULL){
        printf("Already LL is Null!");
        exit;
    }if(head->data==ele){
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    ptr=head;
    while(ptr->next->data!=ele){
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
}
struct node * DeleteEntireLL(struct node * head){
    struct node *ptr;
    if(head==NULL){
        printf("Already LL is Null!");
        exit;
    }
    ptr=head;
    while(head!=NULL){
        ptr=head;
        head=head->next;
        free(head);
    }
    return NULL;
}

int main(){
    printf("Enter the number of elements you want initially in the linked list=");
    int num;
    scanf("%d",&num);
    struct node *head;
    //create function to create a ll 
    head=create(num);
    //Display function to display a ll
    display(head);
    printf("1)Insert at beginning \n2)Insert at the end \n3)Insert after a given element \n4)Insert before a given element \n5)Insert in a sorted list \n6)Delete At beginning \n7)Delete At end \n8)Delete the node of given element \n9)Delete the entire LL \n10)Exit");
    printf("Enter your choice =");
    int ch;
    scanf("%d",&ch);
    int item,ele;
    switch (ch)
    {
    case 1:
        printf("-------------------------------\n");
        printf("ADD TO HEAD!!\n");
        printf("Enter the element=");
        scanf("%d",&item);
        head=AddToHead(head,item);
        display(head);
        printf("-------------------------------\n");
        break;
    case 2:
        printf("-------------------------------\n");
        printf("ADD TO Tail!!\n");
        printf("Enter the element=");
        scanf("%d",&item);
        head=AddToTail(head,item);
        display(head);
        printf("-------------------------------\n");
        break;
    case 3:
        printf("-------------------------------\n");
        printf("Insert after a given element!!\n");
        printf("Enter the item=");
        scanf("%d",&item);
        printf("Enter the element after which you want to insert=");
        scanf("%d",&ele);
        head=AfterGivenEle(head,item,ele);
        display(head);
        printf("-------------------------------\n");
        break;
    case 4:
        printf("-------------------------------\n");
        printf("Insert after a given element!!\n");
        printf("Enter the item=");
        scanf("%d",&item);
        printf("Enter the element before which you want to insert=");
        scanf("%d",&ele);
        head=BeforeGivenEle(head,item,ele);
        display(head);
        printf("-------------------------------\n");
        break;
    case 5:
        printf("-------------------------------\n");
        printf("ADD In The Sorted LL!!\n");
        printf("Enter the element=");
        scanf("%d",&item);
        head=Insortedmanner(head,item);
        display(head);
        printf("-------------------------------\n");
        break;
    case 6:
        printf("-------------------------------\n");
        printf("Delete At Beginning!!\n");
        head=DeleteToHead(head);
        display(head);
        printf("-------------------------------\n");
        break;
    case 7:
        printf("-------------------------------\n");
        printf("Delete At End!\n");
        head=DeleteToTail(head);
        display(head);
        printf("-------------------------------\n");
        break;
    case 8:
        printf("-------------------------------\n");
        printf("Delete The node of given ele!!\n");
        printf("Enter the element =");
        scanf("%d",&ele);
        head=DeleteGivenEle(head,ele);
        display(head);
        printf("-------------------------------\n");
        break;
    case 9:
        printf("-------------------------------\n");
        printf("Delete Entire LL!!\n");
        head=DeleteEntireLL(head);
        display(head);
        printf("-------------------------------\n");
        break;
    case 10:
        exit;
        break;
    
    default:
        break;
    }
}