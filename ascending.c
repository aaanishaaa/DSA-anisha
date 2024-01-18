#include<stdio.h>

int N=-1;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void traverse(int A[]){
    for(int i=0;i<=N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void minheapify(int *a,int i,int n){
    int l,r,m;
    while(2*i+1<=n){
        l=2*i+1;
        r=l+1;
        m=l;
        if(r<=n){
            if(a[r]<a[l]){
               m=r; 
            }
        }
        if(a[i]>a[m]){
            swap(&a[i],&a[m]);
        }
        else{
            break;
        }
        i=m;
        
    }
}

void Enqueue(int A[],int x){
    A[N+1]=x;
    N=N+1;
    int P=(N-1)/2;
    int C=N;
    while(C>0 && A[C]>A[P]){
        swap(&A[C],&A[P]);
        C=P;
        P=(P-1)/2;
    }
}

int dequeue(int A[]){
    int x=A[0];
    A[0]=A[N];
    N=N-1;
    minheapify(A,0,N);
    return x;
}

int main() {
    int x, y;
    int choice;
    int A[10] = {};

    while (1) {
        printf("\nENTER YOUR CHOICE\n1 for Enqueue\n2 for Dequeue\n3 for Traversal\n0 to Exit\n");
        scanf("%d", &x);

        switch (x) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &choice);
                Enqueue(A, choice);
                break;

            case 2:
                y = dequeue(A);
                if (y != -1) {
                    printf("Element dequeued is %d\n", y);
                }
                break;

            case 3:
                traverse(A);
                break;

            case 0:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}