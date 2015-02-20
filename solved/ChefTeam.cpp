#include<stdio.h>

int minAge[100001];
int minRating[100001];
int maxAge[100001];
int maxRating[100001];

int mincount = 0;
int maxcount = 0;
int medianAge = 1000000001;
int medianRating = 0;
long long unsigned int leftSum = 0;
long long unsigned int rightSum = 0;

int left(int i){
    return 2*i;
}

int right(int i){
    return (2*i +1);
}

void maxHeapify (int i, int flag){
    if( i == 0 ) return;
    int l = left(i);
    int r = right(i);
    int largest;
    if( l <= mincount && minAge[l] > minAge[i])
        largest = l;
    else    largest = i;
    if( r <= mincount && minAge[r] > minAge[largest])
        largest = r;
    if ( largest != i){
        int temp = minAge[i];
        minAge[i] = minAge[largest];
        minAge[largest] = temp;
        temp = minRating[i];
        minRating[i] = minRating[largest];
        minRating[largest] = temp;
        if( flag == 0)
            maxHeapify(i/2, 0);
        else
            maxHeapify(largest, 1);
    }
}

void insertMin( int age, int rating){
    mincount++;
    minAge[mincount] = age;
    minRating[mincount] = rating;
    leftSum = leftSum + rating;
    maxHeapify(mincount/2, 0);
}

void maxElement(){
    medianAge = minAge[1];
    medianRating = minRating[1];
}

void minHeapify (int i, int flag){
    if( i == 0) return;
    int l = left(i);
    int r = right(i);
    int smallest;
    if( l <= maxcount && maxAge[l] < maxAge[i])
        smallest = l;
    else    smallest = i;
    if( r <= maxcount && maxAge[r] < maxAge[smallest])
        smallest = r;
    if ( smallest != i){
        int temp = maxAge[i];
        maxAge[i] = maxAge[smallest];
        maxAge[smallest] = temp;
        temp = maxRating[i];
        maxRating[i] = maxRating[smallest];
        maxRating[smallest] = temp;
        if( flag == 0)
                minHeapify(i/2, 0);
       else
                minHeapify(smallest, 1);
    }
}

void insertMax( int age, int rating){
    maxcount++;
    maxAge[maxcount] = age;
    maxRating[maxcount] = rating;
    rightSum = rightSum + rating;
    minHeapify(maxcount/2, 0);
}

void deleteElement(){
    int tempAge = maxAge[1];
    int tempRating = maxRating[1];
    maxAge[1] = maxAge[maxcount];
    maxRating[1] = maxRating[maxcount];
    rightSum = rightSum - tempRating;
    maxcount--;
    minHeapify(1,1);
    insertMin(tempAge, tempRating);
    maxElement();
}

main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    int age,rating;
    int balance = 0;

    for( int i = 0; i < n; i++){
            scanf("%d", &age);
            scanf("%d", &rating);

            switch(balance){
                case 0:
                            if( age < medianAge){
                                insertMin(age, rating);
                                maxElement();
                            }
                            else{
                                insertMax(age, rating);
                                deleteElement();
                            }
                            balance = -1;
                            break;

                  case -1:
                            if( age < medianAge){
                                insertMin(age, rating);
                                int tempAge = minAge[1];
                                int tempRating = minRating[1];
                                minAge[1] = minAge[mincount];
                                minRating[1] = minRating[mincount];
                                leftSum = leftSum - tempRating;
                                mincount--;
                                maxHeapify(1,1);
                                maxElement();
                                insertMax(tempAge, tempRating);
                            }
                            else{
                                insertMax(age, rating);
                            }
                            balance = 0;
                            break;
            }
            if(leftSum >= rightSum)
                    printf("%llu\n", leftSum - rightSum);
            else
                    printf("%llu\n", rightSum - leftSum);
    }
}
