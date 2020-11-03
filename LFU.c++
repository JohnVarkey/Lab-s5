#include<iostream>
#include<map>
#define MAX 3

using namespace std;



// values for the queue put as Global
int queue_array[MAX];
int rear = -1;
int front = -1;
map <int , int > mp;
 



/*
 * @brief 
 *      checks if full 
 * @return int 
 *      return 1 if full else 0
 */
int isfull(){

    if((front == rear + 1) || (front == 0 && rear == MAX - 1))
       return 1; 
    return 0;

}

/*
 * @brief 
 *      checks if empty 
 * @return int 
 *      return 1 if empty else 0
 */

int isempty(){
    if(front == -1) 
        return 1;
    return 0;
}
/*
 * @brief
 *      insert into the Queue 
 * @param val 
 *      value to be inserted
 */

void enqueue(int val){

    if (isfull()){
    	
    cout << " OverFlow  ";
    	
	}else{
        if (front == - 1) 
    	    front = 0;
        rear = (rear + 1) % MAX;
        queue_array[rear] = val;
    }
}

/*
 * @brief  
 *      delete element from queue. Changes have bee made for the program
 * @param index 
 *      index of the value to be deleted in the queue
 */
void dequeue(int index){

    unsigned int i;
    if (isempty())
    {
        cout<<"Queue Underflow \n";
        return ;
    }

    
    for(i=index+1;i<MAX;i++)
        queue_array[i-1]=queue_array[i];
    --rear;
}

/*
 * @brief  
 *      Print the whole queue 
 */
void print(){
    int i;
    cout<<"Front:"<<front<<" | ";
    for(i = 0;i< MAX; i++ )
        cout<<"  "<<queue_array[i]<< " |";
    cout<< "Rear: "<< rear << endl;
}

/*
 * @brief  
 *      search for a element in the queue  
 * @param key  
 *      index of the element to be searched(refarray[key])
 * @return int 
 *      index of the element in the queue if found else -1 is returned
 */

int search(int key){

    unsigned int i;
    int flag=-1;
    if (isempty())
        return -1;
    for(i = 0; i<MAX ; i++ ){
        if(key == queue_array[i]){
            flag=1;
            break;
        }
    }
    if(flag == -1)
        return -1;
    else
        return i;
    
}
/*
 * @brief 
 *      finds the least frequently page 
 * @return int 
 *      index of the least frequently used page
 */
int LF(){
    int i;
    int smallest=queue_array[0];
    for( i=1;i<MAX ;i++){ // this loop is used to find the least frequency
        if(mp[queue_array[i]]<mp[smallest])
            smallest = queue_array[i];
    }
    //traversed from front to rear to find the first element with the least frequency(checking fifo) 
    i=front;
    while(i<=rear){
        if(mp[queue_array[i]]==mp[smallest])
            return i ;
        i = (i+1)%MAX;
    }
}

/*
 * @brief 
 *      used to dequeue the least frequently used page
 */
void LFdequeued(){

    int index = LF();
    mp[queue_array[index]]=0;
    dequeue(index);
}



int main(){
    int num, i, refarr[50], faults=0;
    //initialising the queue with -1 
    for(i=0 ; i<MAX ; i++)
        queue_array[i] = -1;
    
    //taking input
    cout << "Enter the Number of Elements in the Reference String";
    cin >> num;
    cout<<"Enter the reference string: \n";
    for ( i = 0; i < num; i++)
        cin >> refarr[i];
    

    // LFU logic
    for(i = 0;i < num; i++){
        cout<<"key: "<<refarr[i]<<"  ";
        mp[refarr[i]]+=1; // here the the frequency of the page in increased by 1 
        if(search(refarr[i])==-1){
            faults+=1;
            if(isfull()){
                LFdequeued();
                enqueue(refarr[i]);
            }else
                enqueue(refarr[i]);
        }
        print();
        cout<<"Page Faults: "<< faults<<endl;
    } 
    cout<<"Faults Total: "<<faults;

    return 0;
}
