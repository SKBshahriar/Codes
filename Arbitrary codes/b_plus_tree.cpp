#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> data,listData;

struct lkdlist{
    int value[100];
    struct lkdlist *parent;
    struct lkdlist *child[101];
};

typedef lkdlist node;

node *start, *splitHead;

void split(node *head,node *start,int item,bool leaf);

void initialize(node *temp)
{
    temp=new node();
    temp->parent=NULL;

    for(int i=0;i<n;i++){
        temp->child[i]=NULL;
        temp->value[i]=-1;
    }
}

void listSort(node *temp,int item)
{
    int i=0;
    while(temp->value[i]!=-1){
        listData.push_back(temp->value[i]);
        i++;
    }
    listData.push_back(item);
    sort(listData.begin(),listData.begin()+(n-1));
    for(int i=0;i<listData.size();i++) temp->value[i]=listData.at(i);
    listData.clear();
}

void leafToParent(node *temp,node *temp1,node *start,int item)
{
    if(temp->parent==NULL){   // if node has no parent
        node *head;
        initialize(head);
        head->value[0]=item;
        head->child[0]=temp;
        head->child[1]=temp1;
        temp1->parent=head;
        temp->parent=head;
        start=head;

    }
    else{                   //if node has parent
        node *head;
        head=temp->parent;
        int i=0;
        while(i<n-1 && head->value[i]!=-1) i++;
        if(i<n){           // if parent has space for new entry
            listSort(head,item);
            int noOfValue=i+1;        // for counting number of value in parent node
            node *arr[101];
            i=0;
            while(head->child[i]!=NULL){ // saving all child of a node in an array
                arr[i]=head->child[i];
                i++;
            }
            arr[i]=temp1;       //saving new child
            i++;

            for(int j=0;j<i;j++){
                for(int x=0;x<noOfValue;x++){
                    if(arr[j]->value[0]<head->value[x]){
                        head->child[x]=arr[j];
                        arr[j]->parent=head;
                        break;
                    }

                }
                if(j==i-1){
                    head->child[noOfValue+1]=arr[j];
                    arr[j]->parent=head;
                }
            }

        }
        else{

            node *head;
            head=temp->parent;
            node *arr[101];
            int i=0;
            while(head->child[i]!=NULL){  // saving all child of a node in an array
                arr[i]=head->child[i];
                i++;
            }
            arr[i]=temp1;       //saving new child
            i++;
            split(head,start,item,false);
            int noOfValue1=n/2;
            int noOfValue2=n-(n/2)-1;
            int cnt=0;
            for(int j=0;j<i;j++){
                for(int x=0;x<noOfValue1;x++){
                    if(arr[j]->value[0]<head->value[x]){
                        head->child[x]=arr[j];
                        arr[j]->parent=head;
                        cnt++;
                        break;
                    }
                }
            }
            int f=0;
            for(int x=0;x<i;x==){
                if(head[noOfValue1]->value==arr[x]){
                    head[noOfValue1+1]->child=arr[x];
                    arr[x]->parent=head;
                    f=1;

                }
            }

            for(int j=0;j<i;j++){
                for(int x=0;x<noOfValue2;x++){
                    if(arr[j]->value[0]<splitHead->value[x]){
                        head->child[x]=arr[j];
                        arr[j]->parent=head;
                        cnt++;
                        break;
                    }
                }
            }

        }
    }
}

void split(node *head,node *start,int item,bool leaf)
{
    data.push_back(item);
    for(int i=0;i<n-1;i++) data.push_back(head->value[i]);
    sort(data.begin(),data.begin()+(n-1));
    for(int i=0;i<n/2;i++) head->value[i]=data.at(i);
    node *temp;
    initialize(temp);
    if(leaf){                      // if it is leaf node
        for(int i=n/2,j=0;i<n;i++) temp->value[j]=data.at(i);
        data.clear();
        leafToParent(head,temp,start,temp->value[0]);

    }
    else{
        int first;
        for(int i=n/2,j=0;i<n;i++){
            if(i==n/2) first=data.at(i);
            else temp->value[j]=data.at(i);
        }
        data.clear();
        leafToParent(head,temp,start,first);
        splitHead=temp;

    }

}

void insert(int item)
{
    if(start->child[0]==NULL){    //if start has no child
        int i=0;
        while(i<n-1 && start->value!=-1) i++;
        if(i<n) listSort(start,item);
        else{
            node *head=start;
            start=split(head,start,item,true);

        }
    }
    else{
        int i=0;
        while(i<n-1 && start->value!=-1) i++;
        node head=new node();
         head=start;
         int f=0;
         if(j=0;j<i;j++){
            if(head->child[j]->value[0]>item){
                f=1;
                head=head->child[j];
                while(1){
                    int f2=0;
                    if(head->child[0]==NULL) break;
                    int x=0
                    while(x<n-1 && head->value!=-1) x++;

                    for(int k=0;k<x;k++){

                        if(head->child[k]->value[0]>item){
                            head=head->child[k];
                            f2=1;
                            break;
                        }
                        else if(k==x-1 and f2==0){
                            head=head->child[k+1];
                        }
                    }
                }

            }
            if(j==i-1 and f==0){
                head=head->child[j+1]
                while(1){
                    int f2=0;
                    if(head->child[0]==NULL) break;
                    int x=0
                    while(x<n-1 && head->value!=-1) x++;

                    for(int k=0;k<x;k++){

                        if(head->child[k]->value[0]>item){
                            head=head->child[k];
                            f2=1;
                            break;
                        }
                        else if(k==x-1 and f2==0){
                            head=head->child[k+1];
                        }
                    }
                }
            }
         }
        int x=0;
        while(x<n-1 && head->value!=-1) x++;
        if(x<n) listSort(head,item);
        else{

            start=split(head,start,item,true);
        }
    }
}

int main()
{
    cout<<"Enter The Value Of N: ";
    cin>>n;

    initialize(start);

    while(1){

        cout<<"if you want to insert, enter data or enter -1 to exit";
        int ans;
        cin>>ans;
        if(ans==-1) break;

        start=insert(ans);
    }
}
